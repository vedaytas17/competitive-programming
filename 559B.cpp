#include<bits/stdc++.h>
using namespace std;
string smallest(string s) {
    if (s.length() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.length()/2));
    string s2 = smallest(s.substr(s.length()/2, s.length()));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}
int main(){
	string a,b;
	cin>>a>>b;
	a = smallest(a);
	b = smallest(b);
	bool f;
	if(a == b)f = 1;
	else f = 0;
	if(f)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}