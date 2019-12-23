#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx=101, mx1=mx*9, mx2=mx*9*9;
vector<vector<int>> dp(mx1,vector<int>(mx2,-1)), ct(mx1,vector<int>(mx2,-1));
map<ll,bool> memo;

vector<int> eval(int i, int j, int t) {
	vector<int> p(10,0);
	int iter=0;
	while(i<j&&iter<mx) {
		int k=dp[i][j];
		if(k<=0) return vector<int>(10,0);
		p[k]++; i-=k; j-=k*k;
		iter++;
	}
	p[1]+=i;
	return p;
}

ll get_key(int a, int b, int c, int d) {
	return a*1LL<<(16*3)+b*1LL<<(16*2)+c*1LL<<16+d;
}

bool more(int i, int j, int ii, int jj, int k) {
	ll key=get_key(i,j,ii,jj);
	if(memo.count(key)) return memo[key];
	vector<int> p=eval(i,j,0), q=eval(ii,jj,1);
	q[k]++;
	for (int l=1; l<=9; l++)
		if(p[l]>q[l]) return memo[key]=false;
		else if(p[l]<q[l]) return memo[key]=true;
	return memo[key]=false;
}

int main() {
	for (int i=1; i<mx; i++) ct[i][i]=i, dp[i][i]=i;
	for (int i=1; i<=9; i++) ct[i][i*i]=1, dp[i][i*i]=i;
	for (int i=1; i<mx1; i++)
		for (int j=i+1; j<mx2; j++)
			for (int k=1; k<=9; k++) {
				int ii=i-k, jj=j-k*k;
				if(ii<0||jj<0||ct[ii][jj]==-1||ct[ii][jj]>=mx) continue;
				int val=ct[ii][jj]+1;
				if(ct[i][j]==-1||ct[i][j]>val||(ct[i][j]==val&&more(i,j,ii,jj,k))) dp[i][j]=k, ct[i][j]=val;
			}
	int t; scanf("%d", &t);
	for (int c=0; c<t; c++) {
		int a,b; scanf("%d %d", &a, &b);
		if(a>=mx1||b>=mx2||ct[a][b]==-1||ct[a][b]>=mx) printf("No solution\n");
		else {
			vector<int> p=eval(a,b,0);
			for (int i=1; i<=9; i++)
				for (int j=0; j<p[i]; j++)
					printf("%c",i+'0');
			printf("\n");
		}
	}
	return 0;
}
