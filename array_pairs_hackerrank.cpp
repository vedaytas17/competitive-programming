//Link to the question : https://www.hackerrank.com/contests/101hack42/challenges/array-pairs
#include<bits/stdc++.h>
#define in(n) scanf("%d",&n)
#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii > node;
pii arr[500007]; // value,index
vector < node > query; //i,j,k...range[i..j] and query is for # of numbers less than or equal to k
int L[500007],R[500007];
int tree1[4*500007],m;
int tree[4*500007];
vector <int> nums;
ll ans = 0;
bool cmp1(const node &a,const node &b){
	return a.second.second > b.second.second;
}
bool cmp2(const pii &a,const pii &b){
	return a.first > b.first;
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

void build1(int start,int end,int idx){
	if(start == end){
		tree1[idx] = start;return;
	}
	int mid = (start + end)/2;
	build1(start,mid,2*idx);
	build1(mid+1,end,2*idx+1);
	if(arr[tree1[2*idx]].first > arr[tree1[2*idx+1]].first){
		tree1[idx] = tree1[2*idx];
	}
	else tree1[idx] = tree1[2*idx+1];
}
int solve1(int start,int end,int l,int r,int idx){
	if(start > end || l > end || r < start){
		return -1;
	}
	else if(l<=start & r>=end){
		return tree1[idx];
	}
	int mid = (start+end)/2;
	int z1 = solve1(start,mid,l,r,2*idx);
	int z2 = solve1(mid+1,end,l,r,2*idx+1);
	if(z1 == -1)return z2;
	else if(z2 == -1)return z1;
	else if(arr[z1] > arr[z2])return z1;
	return z2;
}
void recurse(int start,int end,int n){
	if(start >= end)return;
	int idx = solve1(0,n-1,start,end,1);
//	nums.push_back(arr[idx].first);
	int i,maximum;
	maximum = arr[idx].first;
	//cerr<<start<<' '<<end<<' '<<idx<<' '<<L[idx]<<' '<<R[idx]<<endl;
	if(idx-L[idx] <= R[idx] - idx){
		for(i = L[idx];i <= idx;i++){
			int z = maximum/arr[i].first;
			if(arr[i].first == 1){
				ans++;
			}
			query.push_back(node(idx+1,pii(R[idx],z)));// less than or equal to z..
			m++;
		}
	}
	else{
		for(i = idx;i <= R[idx];i++){
			int z = maximum/arr[i].first;
			if(arr[i].first == 1){
				ans++;
			}
			query.push_back(node(L[idx],pii(idx-1,z)));
			m++;
		}
	}
	recurse(start,idx-1,n);
	recurse(idx+1,end,n);
}
int main(){
	int n,i,j,x,cnt1 = 0;
	in(n);
	for(i = 0;i < n;i++){
        in(x);
		//in(arr[i].first);
		if(x == 1)cnt1++;
        arr[i].first = x;
		arr[i].second = i;
	}
	vector < pii > vec;
	for(i = 0;i < n;i++){
		while(vec.size() > 0 && vec.back().first < arr[i].first)vec.pop_back();
		if(vec.size() == 0)L[i] = 0;
		else L[i] = vec.back().second+1;
		vec.push_back(pii(arr[i].first,i));
	}
	vec.clear();
	for(i = n-1;i >= 0;i--){
		while(vec.size() > 0 && vec.back().first <= arr[i].first)vec.pop_back();
		if(vec.size() == 0)R[i] = n-1;
		else R[i] = vec.back().second-1;
		vec.push_back(pii(arr[i].first,i));
	}
	build1(0,n-1,1);
	recurse(0,n-1,n);
	//cerr<<m<<endl;
//	for(i = 0;i < nums.size();i++){
//		if(nums[i] == 1){
//			ans += cnt1-1;
//		}
//		else ans += cnt1;
//	}
	build(0,n-1,1);
	sort(arr,arr+n,cmp2);
	sort(query.begin(),query.end(),cmp1);
//	for(i = 0;i < m;i++){
//		cerr<<query[i].first<<' '<<query[i].second.first<<' '<<query[i].second.second<<endl;
//	}
	int ptr = 0;
	for(i = 0;i < m;i++){
		int target = query[i].second.second;
		while(ptr < n && arr[ptr].first > target){
			update(0,n-1,1,arr[ptr].second);
			ptr++;
		}
		ans += solve(0,n-1,query[i].first,query[i].second.first,1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
10
1 1 1 4 2 24 23 12321 1 1

Ans = 35*/
