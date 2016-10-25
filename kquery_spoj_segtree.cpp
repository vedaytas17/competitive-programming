//Link to question : http://www.spoj.com/problems/KQUERY/
#include<bits/stdc++.h>
#define in(n) scanf("%d",&n)
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,pii> > node; //query number,i,j,k
node query[200007];
pii arr[30007];
int answer[200007];
int tree[4*30000+7];
bool cmp1(const node &a,const node &b){
	return a.second.second.second < b.second.second.second;
}
bool cmp2(const pii &a,const pii &b){
	return a.first < b.first;
}
void build(int start,int end,int idx){
	if(start == end){
		tree[idx] = 1;
		return ;
	}
	int mid = (start+end)/2;
	build(start,mid,2*idx);
	build(mid+1,end,2*idx+1);
	tree[idx] = tree[2*idx]+tree[2*idx+1];
}
void update(int start,int end,int idx,int pos){
	//Sets the value at pos to 0 from 1
	if(pos > end || pos < start)return;
	if(start == end){
		tree[idx] = 0;return;
	}
	int mid = (start+end)/2;
	update(start,mid,2*idx,pos);
	update(mid+1,end,2*idx+1,pos);
	tree[idx] = tree[2*idx] + tree[2*idx+1];
}
int solve(int start,int end,int l,int r,int idx){
	if(end < start || l > end || r < start)return 0;
	if(l <= start && r >= end)return tree[idx];
	int mid = (start+end)/2;
	return solve(start,mid,l,r,2*idx)+solve(mid+1,end,l,r,2*idx+1);
}
int main(){
	int n,m,i;
	in(n);
	for(i = 0;i < n;i++){
		in(arr[i].first);
		arr[i].second = i;
	}
	in(m);
	for(i = 0;i < m;i++){
		in(query[i].second.first);
		in(query[i].second.second.first);
		in(query[i].second.second.second);
		query[i].first = i;
	}
	build(0,n-1,1);
	sort(arr,arr+n,cmp2);
	sort(query,query+m,cmp1);
	int ptr = 0;
	for(i = 0;i < m;i++){
		int query_number = query[i].first;
		//cerr<<query_number<<' ';
		int target = query[i].second.second.second;
		while(ptr < n && arr[ptr].first <= target){
			update(0,n-1,1,arr[ptr].second);
			ptr++;
		}
		answer[query_number] = solve(0,n-1,query[i].second.first-1,query[i].second.second.first-1,1);
		//cerr<<answer[query_number]<<endl;
	}
	for(i = 0;i < m;i++){
		printf("%d\n",answer[i]);
	}
	return 0;
}
