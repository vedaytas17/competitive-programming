#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100007];
bool primes[1000007];
void sieve(){
    primes[1] = 1;
    int i,j;
    for(i = 2;i<=1000;i++){
        if(!primes[i]){
            for(j = i+i;j <= 1000000;j+=i){
                primes[j] = 1;
            }
        }
    }
}
bool check(ll x){
	int z = sqrt(x);
    //cout<<z*z<<' '<<primes[z]<<endl;
    if(z*1LL*z == x && primes[z] == 0){
        //cout<<"In\n";
        return 1;
    }
	return 0;
}
int main(){
    sieve();
	int n,i;
	cin>>n;
    //cout<<check(36)<<endl;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i = 0;i < n;i++){
		if(check(arr[i]))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}