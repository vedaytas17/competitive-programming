//Link to the question : https://www.hackerrank.com/contests/sears-dots-arrows/challenges/simple-paths
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector < vector<pii> > graph;
int color[45][100007];
int ctr;
void dfs(int src,int col){
    //Do the dfs of the node src neglecting the edge of color col
	color[col][src] = ctr;
	int i;
	for(i = 0;i < graph[src].size();i++){
		if(graph[src][i].second != col && !color[col][graph[src][i].first]){
			dfs(graph[src][i].first,col);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,Q,i,j,c,k;
	cin>>n>>m>>c;
	graph.resize(n+3);
	while(m--){
		cin>>i>>j>>k;
		graph[i].push_back(pii(j,k));
		graph[j].push_back(pii(i,k));
	}
	for(i = 0;i <= c;i++){
		for(j = 1;j <= n;j++){
			if(!color[i][j]){
				ctr++;
                //if(i == 1)cout<<ctr<<endl;
				dfs(j,i);
			}
		}
	}
    //cout<<color[1][1]<<' '<<color[1][3];
    //cout<<endl;
	cin>>Q;
	while(Q--){
		cin>>i>>j;
		int ans = 0;
		for(int ii = 1;ii <= c;ii++){
			if(color[0][i] == color[0][j] && color[ii][i] != color[ii][j]){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
