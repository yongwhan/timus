#include<bits/stdc++.h>
using namespace std;

#define MAX 100

typedef long long ll;

ll MOD;

ll mul(ll a, ll b) {
	ll x=0, y=a%MOD;
	while(b>0) {
		if(b%2) x=(x+y)%MOD;
		y=(y+y)%MOD;
		b/=2;
	}
	return x%MOD;
}

ll mat[MAX][MAX], res[MAX][MAX];

int getmul(ll res[MAX][MAX], ll mat[MAX][MAX], int n) {
	ll tmp[MAX][MAX];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			tmp[i][j]=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				tmp[i][j]=(tmp[i][j]+mul(res[i][k],mat[k][j]))%MOD;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			res[i][j]=tmp[i][j];
	return 0;
}

int getexp(ll mat[MAX][MAX], int n, ll e) {
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			if(i==j) res[i][j]=1;
			else res[i][j]=0;
		}
	while(e) {
		if(e%2) getmul(res,mat,n);
		getmul(mat,mat,n);
		e/=2;
	}
	return 0;
}

int main() {
	ll N,K; cin>>N>>K>>MOD;
	mat[0][0]=(K-1)%MOD; mat[0][1]=(K-1)%MOD;
	mat[1][0]=1; mat[1][1]=0;
	getexp(mat,2,N);
	cout<<res[0][0]<<endl;
	return 0;
}
