/*
	By Anudeep Nekkanti
	Editorial at http://blog.anudeep2011.com/mos-algorithm/
	Question at http://www.spoj.com/problems/DQUERY/
	O( (N+M) * sqrt N )
*/
//Link to question : https://www.hackerrank.com/contests/sears-dots-arrows/challenges/connection-queries
#include <cstdio>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int ReadInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
#define N 111111
#define A 111111
#define BLOCK 327 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}
bool S[N];
bool inrange(int x,int y,int z){
	if(z>=x && z<=y)return 1;
	return 0;
}
void add(int pos){
	if(S[a[pos]-1] == 0 && S[a[pos]+1] == 0)answer++;
	else if(S[a[pos]-1] == 1 && S[a[pos]+1] == 1)answer--;
	S[a[pos]] = 1;
}
void remove(int pos){
	if(S[a[pos]-1] == 1 && S[a[pos]+1] == 1)answer++;
	if(S[a[pos]-1] == 0 && S[a[pos]+1] == 0)answer--;
	S[a[pos]] = 0;
}
int main() {
	int n,m;
	//scanf("%d %d", &n,&m);
    n = ReadInt();
    m = ReadInt();
	for(int i=0; i<n; i++)
		a[i] = ReadInt();
	for(int i=0; i<m; i++) {
        q[i].L = ReadInt();
        q[i].R = ReadInt();
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + m, cmp);

	int currentL = 0, currentR = 0;
	answer = 0;
	for(int i=0; i<m; i++) {
		//cerr<<i<<endl;
		int L = q[i].L, R = q[i].R;
		//cerr<<L<<' '<<R<<endl;
		while(currentL < L) {
			if(S[a[currentL]] == 1 && !inrange(L,R,currentL)){
				remove(currentL);
			}
			if(S[a[currentL]] == 0 && inrange(L,R,currentL)){
				add(currentL);
			}
			currentL++;
		}
		while(currentL > L) {
			if(S[a[currentL]] == 0 && inrange(L,R,currentL)){
				add(currentL);
			}
			if(S[a[currentL]] == 1 && !inrange(L,R,currentL)){
				remove(currentL);
			}
			currentL--;
		}
		if(S[a[L]] == 0){
			add(L);
		}
		while(currentR < R) {
			if(S[a[currentR]] == 0 && inrange(L,R,currentR)){
				add(currentR);
			}
			if(S[a[currentR]] == 1 && !inrange(L,R,currentR)){
				remove(currentR);
			}
			currentR++;
		}
		while(currentR > R) {
			if(S[a[currentR]] == 1 && !inrange(L,R,currentR)){
				remove(currentR);
			}
			if(S[a[currentR]] == 0 && inrange(L,R,currentR)){
				add(currentR);
			}
			currentR--;
		}
		if(S[a[R]] == 0){
			add(R);
		}
		ans[q[i].i] = answer;
		//cerr<<answer;break;
	}

	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);
}
