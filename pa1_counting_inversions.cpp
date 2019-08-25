#include <iostream> 
using namespace std; 


long long merge(long long* arr, long long* temp, int l, int m, int r){ 
    int i = l, j = m, k = l; 
    
    long long inv_count = 0; 
    
    while ((i <= m - 1) && (j <= r)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        }else{ 
            temp[k++] = arr[j++]; 
            inv_count = inv_count + (m - i); 
        } 
    } 

    while (i <= m - 1) temp[k++] = arr[i++]; 

    while (j <= r) temp[k++] = arr[j++]; 

    for (i = l; i <= r; i++) arr[i] = temp[i]; 

    return inv_count; 
} 

long long count(long long* arr, long long* temp, int l, int r){ 
    long m, inv_count = 0; 
    if (r > l) 
    { 
        m = l + (r - l)/2; 
        inv_count = count(arr, temp, l, m); 
        inv_count += count(arr, temp, m + 1, r); 

        inv_count += merge(arr, temp, l, m + 1, r); 
    } 
    return inv_count; 
} 


int main() 
{ 
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        long long arr[n], temp[n];
        for(int j = 0; j < n; j++) cin >> arr[j];
        cout << count(arr, temp, 0, n-1) << endl; 
    }
    return 0; 
} 
