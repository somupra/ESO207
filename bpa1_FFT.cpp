#include <iostream>
#include <iomanip>
#include <tgmath.h>

typedef long long int li;
typedef long double ld;

using namespace std;

complex< ld > * RecFFT(complex< ld > * a, li n){
    if(n == 1){
        return a;
    }
    complex< ld > * Ae = new complex< ld >  [n/2];
    complex< ld > * Ao = new complex< ld >  [n/2];
    complex< ld > * Ye, * Yo;
    complex< ld > * y = new complex< ld > [n];

    for(li i = 0; i < n; i++){
        if(i %2 == 0){
            Ae[i/2] = a[i];
        }else{
            Ao[i/2] = a[i];
        }
    }
    Ye = RecFFT(Ae, n/2);
    Yo = RecFFT(Ao, n/2);
    complex< ld >  Wn = complex< ld > (cosl(2 * M_PI / n), sinl(2 * M_PI / n));
    complex< ld >  w = complex< ld > (1L, 0L);
    
    for(li k = 0; k < n/2; k++){
        y[k] = Ye[k] + w * Yo[k];
        

        y[k + n/2] = Ye[k]- w * Yo[k];
        
        w = Wn * w;
    }
    return y;
}


void compute(){
    li n ;
    cin >> n;
    li N = 1;
    li m = n;
    while(1){
        if(n < N){
            n = N;
            break;
        }else if(n > N){
            N *= 2;
        }else if( n == N){
            break;
        }
    }
    complex< ld > * a = new complex< ld >  [n];

    for(li i = 0; i < m; i++){
        ld x, y;
        cin >> x >> y;
        a[i] = complex<ld > (x, y);
    }
    
    for(li i = m; i < n; i++){
        a[i] = complex< ld > (0L, 0L);
    }
    
    complex< ld > * y = RecFFT(a, n);
    complex< ld > * dft = new complex< ld > [n];
    
    for(li i = 0; i < n; i++){
        cout <<"(" << ((fabs(real(y[i])) < 0.0005)? 0.000: real(y[i])) <<","<<((fabs(imag(y[i])) < 0.0005)? 0.000: imag(y[i])) <<")\n";
    }
}

int main(){
    cout << fixed << setprecision(3);
    li t;
    cin >> t;
    while(t--){
        compute();
    }
}
