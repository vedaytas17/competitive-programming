//To compile run g++-5 filename.cpp on cmd
//Link to the question : http://codeforces.com/problemset/problem/2/A
#include<bits/stdc++.h>
using namespace std;
map <string,int> ma;
map <int,string> ma1;
vector<int> v;
vector<int> :: iterator it;
int arr[1003][2];
int val[1003];
int main(){
	int n,i,j;
	string s;
	cin>>n;
	string ans;
	int k = 1;
	for(i = 0;i < n;i++){
		cin>>s>>j;
		if(ma.find(s) == ma.end()){
			ma1[k] = s;
			ma[s] = k++;
			val[k-1] = j;
		}
		else{
			int idx = ma[s];
			val[idx] += j;
		}
		arr[i][0] = ma[s];
		arr[i][1] = j;
	}

	int maxi = 0;
	for(i = 1;i < k;i++){
		maxi = max(maxi,val[i]); 
	}
	v.clear();
	for(i = 1;i < k;i++){
		if(val[i] == maxi)v.push_back(i);
	}
	//cerr<<v[0]<<endl;
	int key;
	memset(val,0,sizeof(val));
	for(i = 0;i < n;i++){
		val[arr[i][0]] += arr[i][1];
		//cout<<val[arr[i][0]]<<endl;
		if(val[arr[i][0]] >= maxi){
			it = lower_bound(v.begin(),v.end(),arr[i][0]);
			//cerr<<*it<<endl;
			if(*it == arr[i][0]){
				key = arr[i][0];break;
			}
		}
	}

	ans = ma1[key];
	
	cout<<ans<<"\n";
	return 0;
}