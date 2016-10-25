#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+7;
int arr[MAXN],parent[MAXN],indices[MAXN];
vector < int > values;
vector < int > :: iterator it;
int length = 1;

void lis(int n){
	int i,j;
	indices[0] = 0;
	values.push_back(arr[0]);
	for(i = 0;i < n;i++){
		parent[i] = -1;
	}
	int end = 0;
	for(i = 1;i < n;i++){
		if(arr[i] == values[0] || arr[i] == values[end])continue;
		if(arr[i] < values[0]){
			indices[0] = i;
			values[0] = arr[i];
		}
		else if(arr[i] > values[end]){
			end++;length++;
			indices[end] = i;
			parent[i] = indices[end-1];
			values.push_back(arr[i]);
		}
		else{
			it = upper_bound(values.begin(),values.end(),arr[i]);
			int pos = it - values.begin();
			parent[i] = indices[pos-1];
			indices[pos] = i;
			values[pos] = arr[i];
		}
	}
}

int main(){
	int n,i,j;
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>arr[i];
	}
	lis(n);
//	for(i = 0;i < n;i++){
//		cout<<parent[i]<<' ';
//	}
//	cout<<endl;
//	for(i = 0;i < values.size();i++)cout<<indices[i]<<' ';
//	cout<<endl;
	cout<<length<<"\n";
	return 0;
}
