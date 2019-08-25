#include <iostream>
using namespace std;

int rsearch(long long* a, int b, int e, long long k){
    // cout << a[0] << endl;
    if( b == e ){
        long ans = k == a[b] ?  b : -1;
        return ans;
    } 
    
    int m = b + (e-b)/2;
    
    if(k == a[m]) return m;
    
    if(a[b] < a[m]){
        if(k >= a[b] && k <= a[m]) return rsearch(a, b, m, k);
        else return rsearch(a, m+1, e, k);
    }
    else {
        if(k >= a[m+1] && k <= a[e]) return rsearch(a, m+1, e, k);
        else return rsearch(a, b, m, k);
    }

    return 0;
}

int main() {
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        long long a[n], k;
        for(int j = 0; j < n; j++) cin >> a[j];
        cin >> k;
        cout << rsearch(a, 0, n-1, k) << endl;
    }
    
    return 0;
}
