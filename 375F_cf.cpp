#include<bits/stdc++.h>
#define in(n) scanf("%d",&n)
#define pii pair<int,int> 
using namespace std;
int component_info[200007][2];
vector < vector<int> > g;
vector<pii> info,results;
bool visited[200007];
int s,t,value;
int comp_cnt = 1;
void dfs(int src){
	visited[src] = 1;
	int i;
	for(i = 0;i < g[src].size();i++){
		if(g[src][i] == s){
			if(value != s){
				value += s;
				component_info[comp_cnt][0] = src;
			}
			continue;
		}
		if(g[src][i] == t){
			if(value != t){
				value += t;
				component_info[comp_cnt][1] = src;
			}
			continue;
		}
		if(visited[g[src][i]])continue;
		//cout<<src<<' '<<g[src][i]<<"AR\n";
		results.push_back(pii(src,g[src][i]));
		dfs(g[src][i]);
	}
}
bool cmp(const pii &a,const pii &b){
	return a.second<b.second;
}
int main(){
	int n,m,i,j,ds,dt;
	bool flag = 1;
	in(n);in(m);
	g.clear();
	g.resize(n+3);
	while(m--){
		in(i);in(j);
		g[i].push_back(j);
		g[j].push_back(i);
	}
	in(s);in(t);in(ds);in(dt);
	info.push_back(pii(0,0));
	for(i = 1;i <= n;i++){
		if(i == s || i == t || visited[i])continue;
		value = 0;
		dfs(i);
		if(value == 0)flag = 0;
		info.push_back(pii(comp_cnt,value));
		comp_cnt++;
	}
	//cerr<<info.size()<<"done\n";
	bool merge = 0;
	sort(info.begin(),info.end(),cmp);
	//cerr<<component_info[1][0]<<' '<<component_info[1][1]<<endl;
//	for(i = 0;i < info.size();i++){
//		cout<<info[i].first<<' '<<info[i].second<<endl;
//	}
	for(i = 1;i < comp_cnt;i++){
		if(info[i].second == s){
			results.push_back(pii(s,component_info[info[i].first][0]));
			ds--;
		}
		else if(info[i].second == t){
			results.push_back(pii(t,component_info[info[i].first][1]));
			dt--;
		}
		else{
			if(merge == 0){
				//cerr<<info[i].first<<endl;;
				results.push_back(pii(s,component_info[info[i].first][0]));
				results.push_back(pii(t,component_info[info[i].first][1]));
				ds--;dt--;
				//cerr<<ds<<' '<<dt<<"\n\n";
				merge = 1;
			}
			else{
				if(dt > ds){
					results.push_back(pii(t,component_info[info[i].first][1]));
					dt--;
				}
				else{
					results.push_back(pii(s,component_info[info[i].first][0]));
					ds--;
				}
				//cerr<<ds<<' '<<dt<<"\n\n";
			}
		}
	}
	if(results.size() < n-1){
		flag = 0;
		for(i = 0;i < g[s].size();i++){
			if(g[s][i] == t){
				flag = 1;
				results.push_back(pii(s,t));
				dt--;ds--;
				break;
			}
		}
	}
	if(ds < 0 || dt < 0 || flag == 0){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
		for(i = 0;i < results.size();i++){
			cout<<results[i].first<<' '<<results[i].second<<endl;
		}
	}
	return 0;
}

