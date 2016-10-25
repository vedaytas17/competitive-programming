#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[300007];
int mod(int x){
    if(x < 0)return -x;
    return x;
}
int main(){
    ll ans = 0;
	int n,i;
	cin>>n;
    //cout<<check(36)<<endl;
	for(i=1;i<=n;i++){
		cin>>arr[i];
	}
    sort(arr+1,arr+n+1);
	for(i = 1;i <= n;i++){
		ans += (mod(i-arr[i]));
	}
    cout<<ans<<"\n";
	return 0;
}