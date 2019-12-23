#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,x; cin>>n;
	queue<int> q;
	priority_queue<ii> pq;
	for (int i=1; i<=n; i++)
		cin>>x, pq.push({x,i});
	while(!pq.empty()) {
		auto u=pq.top(); pq.pop();
		q.push(u.second); u.first--;
		if(pq.empty()) {
			for (int j=0; j<u.first; j++)
				q.push(u.second);
			break;
		}
		auto v=pq.top(); pq.pop();
		q.push(v.second); v.first--;
		if(u.first) pq.push(u);
		if(v.first) pq.push(v);
	}
	bool first=true;
	while(!q.empty()) {
		if(!first) cout<<" ";
		cout<<q.front();
		q.pop();
		first=false;
	}
	cout<<endl;
	return 0;
}
