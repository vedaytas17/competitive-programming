#include<bits/stdc++.h>
using namespace std;
int arr[103][103];
bool row[103],col[103];
int main(){
	int n,m,i,j;
	cin>>n>>m;
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			cin>>arr[i][j];
		}
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			if(arr[i][j] == 0){
				row[i] = 1;col[j] = 1;
			}
		}
	}
	bool fl = 0;
	for(i = 0;i < n;i++){
		if(row[i] == 0){
			fl = 1;break;
		}
	}
	if(fl == 0){
		for(j=0;j < m;j++)col[j] = 1;
	}
	fl = 0;
	for(j = 0;j < m;j++){
		if(col[j] == 0){
			fl = 1;break;
		}
	}
	if(fl == 0){
		for(i=0;i < m;i++)row[i] = 1;
	}
	fl = 0;
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			if(arr[i][j] == 1){
				//row[i] = 1;col[j] = 1;
				if(row[i] && col[j]){
					fl = 1;break;
				}
			}
		}
		if(fl)break;
	}
	if(fl)cout<<"NO\n";
	else{
		cout<<"YES\n";
		//memset(arr,1,sizeof(arr));
		for(i = 0;i < n;i++){
			for(j = 0;j < m;j++)arr[i][j] = 1;
		}
		for(i = 0;i < n;i++){
			if(row[i]){
				for(j = 0;j < m;j++)arr[i][j] = 0;
			}
		}
		for(j = 0;j < m;j++){
			if(col[j]){
				for(i = 0;i < n;i++){
					arr[i][j] = 0;
				}
			}
		}
		for(i = 0;i < n;i++){
			for(j = 0;j < m;j++)cout<<arr[i][j]<<' ';
			cout<<"\n";
		}
	}
	return 0;
}