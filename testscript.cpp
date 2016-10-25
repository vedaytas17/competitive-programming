#include<bits/stdc++.h>
using namespace std;
int ma[100005];
int main(){
	srand(time(NULL));
	int q = 5*10000;
	cout<<100000<<' '<<q<<endl;
	for(int i= 1;i <= 100000;){
		i = rand()%100000+1;
		if(ma[i] == 0){
			ma[i] = 1;i++;
			cout<<i<<' ';
		}
	}
	cout<<endl;
	while(q--){
		int i,j;
		i = rand()%100000;
		j = rand()%100000;
		if(i > j)swap(i,j);
		cout<<i<<' '<<j<<endl;
	}
	return 0;
}
