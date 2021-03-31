#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=1e9+7;

long long int dp[55][55];
bool don[55][55];

long long int f(long long int n, long long int h){
    if(n==1 && h==1){
        return 1;
    }
    if(n==0 && h==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(n==1){
        return 0;
    }
    if(don[n][h]){
        return dp[n][h];
    }
    
    don[n][h]=1;
    long long int ans=0;
    for(int i=0; i<=n-1; i++){
        for(int j=0; j<=h-1; j++){
            if(j<h-1){
                ans=(ans+f(i, j)*f(n-i-1, h-1))%MOD;
            }
            else{
                for(int k=0; k<=h-1; k++){
                    ans=(ans+f(i, j)*f(n-i-1, k))%MOD;
                }
            }
        }
    }
    dp[n][h]=ans;
    return ans;
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n, h;
    cin>>n>>h;
    cout<<f(n, h);
    return 0;
}