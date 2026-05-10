#include<bits/stdc++.h>
using namespace std;

bool canAchieve(vector<int>& a, long long mid, long long k){
    int n = a.size();
    long long ops = 0;
    for(int i = n/2; i < n; i++){
        if(a[i] < mid)
            ops += mid - a[i];
        if(ops > k) return false;
    }
    return true;
}

int main(){
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long lo = a[n/2];         
    long long hi = a[n/2] + k;    // worst case use all k ops on median

    long long ans = a[n/2];
    while(lo <= hi){
        long long mid = lo + (hi - lo) / 2;
        if(canAchieve(a, mid, k)){
            ans = mid;
            lo = mid + 1;   // try bigger
        } else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}