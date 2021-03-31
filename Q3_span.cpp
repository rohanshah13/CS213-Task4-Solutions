#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
 
 
int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++) cin>>arr[i];
  int ans[n];
  stack<pair<int, int>>st;
  for(int i=0; i<n; i++){
    while(!st.empty() && st.top().f<=arr[i]){
      st.pop();
    }
    if(st.empty()){
      ans[i]=i+1;
    }
    else{
      ans[i]=i-(st.top()).s;
    }
    st.push({arr[i], i});
  }
  for(int i=0; i<n; i++){
    cout<<ans[i]<<endl;
  }
    
  return 0;
}
