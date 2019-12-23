#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,x,cur; cin>>n;
	priority_queue<int> pq;
	ll ret=0, sum=0;
	for (int i=0; i<n; i++)
		cin>>x, pq.push(x), sum+=x;
	while(!pq.empty())
		cur=pq.top(), pq.pop(),
		ret+=(sum+sum-cur)*cur, sum-=cur;
	cout<<ret<<endl;
	return 0;
}
