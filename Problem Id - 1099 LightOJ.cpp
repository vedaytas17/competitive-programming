#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define pii pair< ll, ll >
#define MAX 5001
const ll INF = 1e16;

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
 
priority_queue< pii, vector< pii >, comp > Q;
vector <pii> G[MAX];
ll D[MAX],parent[MAX],value[MAX];
bool F[MAX];
vector <ll> vec;

int main(){
	ll t,n,r,u,v,w;
	cin>>t;
	for(ll tc = 1;tc <= t;tc++){
		cin>>n>>r;
		for(ll i = 1;i <= n;i++)G[i].clear();
		for(ll i = 0;i < r;i++){
			cin>>u>>v>>w;
			G[u].push_back(pii(v,w));
			G[v].push_back(pii(u,w));
		}
		memset(F,0,sizeof(F));
		for(ll i = 1;i <= n;i++){
			D[i] = INF;
			parent[i] = -1;
			value[i] = 0;
		}
		
		D[n] = 0;
		Q.push(pii(n,0));
		
		while(!Q.empty()) {
	        u = Q.top().first;
	        Q.pop();
	        if(F[u]) continue;
	        ll sz = G[u].size();
	        for(ll i=0; i<sz; i++) {
	            v = G[u][i].first;
	            w = G[u][i].second;
	            if(!F[v] && D[u]+w < D[v]) {
	                D[v] = D[u] + w;
	                parent[v] = u;
	                value[v] = w;
	                Q.push(pii(v, D[v]));
	            }
	        }
	        F[u] = 1;
	    }
	    
	    ll result = D[1];
	    
		vec.clear();
		ll x = 1;
		vec.push_back(x);
		while(parent[x] != -1){
			x = parent[x];
			vec.push_back(x);
		}
		
		ll ans = INF;
		ll len = 0;
		for(ll i = 0;i < vec.size();i++){
			ll src = vec[i],tmp,tmp1;
			for(ll j = 0;j < G[src].size();j++){
				ll vertex = G[src][j].first;
				if(parent[src] == vertex && value[src] == G[src][j].second){
					ans = min(ans,result + 2*G[src][j].second);
					tmp = G[src][j].second;
				}
				else if(D[vertex] < MAX){
					tmp1 = D[vertex] + G[src][j].second+len;
					if(tmp1 > result)ans = min(ans,tmp1);	
					else ans = min(ans,tmp1 + G[src][j].second*2);
				}
			}
			len += tmp;
		}
		cout<<"Case "<<tc<<": "<<ans<<"\n";
	}
	return 0;
}
