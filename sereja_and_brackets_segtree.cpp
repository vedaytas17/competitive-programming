//Link to question : http://codeforces.com/contest/380/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> node;
node tree[4*1000000+7]; //first->answer,second->unbalanced opening bracckets,third->unbalanced closing brackets
string s;
void build(int start,int end,int idx){
	if(start == end){
		if(s[start] == '('){
			tree[idx].second.first = 1;
		}
		else{
			tree[idx].second.second = 1;
		}
		return;
	}
	int mid = (start+end)/2;
	build(start,mid,2*idx);
	build(mid+1,end,2*idx+1);
	int z = min(tree[2*idx].second.first,tree[2*idx+1].second.second);
	tree[idx].first = tree[2*idx].first + tree[2*idx+1].first+z;
	tree[idx].second.first = tree[2*idx].second.first + tree[2*idx+1].second.first - z;
	tree[idx].second.second = tree[2*idx].second.second + tree[2*idx+1].second.second - z;
}
node query(int start,int end,int l,int r,int idx){
	if(start > end || r < start || l > end){
		return node(0,pii(0,0));
	}
	else if(l <= start && r >= end){
		return node(tree[idx].first,pii(tree[idx].second.first,tree[idx].second.second));
	}
	int mid = (start + end)/2;
	node z1,z2,z3;
	z1 = query(start,mid,l,r,2*idx);
	z2 = query(mid+1,end,l,r,2*idx+1);
	int z = min(z1.second.first,z2.second.second);
	z3.first = z1.first + z2.first + z;
	z3.second.first = z1.second.first + z2.second.first -z;
	z3.second.second = z1.second.second + z2.second.second -z;
	return z3;
}
int main(){
	int m,i,j,n;
	cin>>s;
	n = s.length();
	build(0,n-1,1);
	cin>>m;
	while(m--){
		cin>>i>>j;
		node z = query(0,n-1,i-1,j-1,1);
		cout<<2*z.first<<"\n";
	}
	return 0;
}
