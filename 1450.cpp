#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m,a,b,c; scanf("%d %d",&n,&m);
	vector<tuple<int,int,int>> es(m);
	for (int i=0; i<m; i++)
		scanf("%d %d %d",&a,&b,&c), es[i]={a,b,c};
	int s,f; scanf("%d %d",&s,&f);
	vector<int> dp(n+1,-1); dp[s]=0;
	for (int i=0; i<n-1; i++)
		for (const auto &e : es)
			dp[get<1>(e)]=max(dp[get<1>(e)],dp[get<0>(e)]!=-1?dp[get<0>(e)]+get<2>(e):-1);
	if(dp[f]==-1) printf("No solution\n");
	else printf("%d\n",dp[f]);
	return 0;
}
