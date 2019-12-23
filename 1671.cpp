#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int mx=1e6+5;

int par[mx], rnk[mx];

void init(int n) {
	for (int i=0; i<n; i++)
		par[i]=i, rnk[i]=0;
}

int find(int x) {
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}

void unite(int x, int y) {
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rnk[x]<rnk[y]) par[x]=y;
	else {
		par[y]=x;
		if(rnk[x]==rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x)==find(y);
}

int main() {
	int n,m; scanf("%d %d", &n, &m);
	vector<int> p(m), q(m);
	multiset<ii> e;
	for (int i=0; i<m; i++) {
		scanf("%d %d", &p[i], &q[i]);
		p[i]--, q[i]--;
		if(p[i]>q[i]) swap(p[i],q[i]);
		e.insert({p[i],q[i]});
	}

	int Q,x; scanf("%d", &Q);
	stack<int> stk;
	for (int i=0; i<Q; i++) {
		scanf("%d", &x), x--, stk.push(x);
		ii cur={p[x],q[x]};
		e.erase(e.find({p[x],q[x]}));
	}

	init(n);
	int ct=n;
	for (auto u : e)
		if(!same(u.first,u.second))
			unite(u.first,u.second), ct--;

	stack<int> ret;
	while(!stk.empty()) {
		ret.push(ct);
		int x=stk.top(); stk.pop();
		if(!same(p[x],q[x]))
			unite(p[x],q[x]), ct--;
	}
	bool first=true;
	while(!ret.empty()) {
		if(!first) printf(" ");
		first=false;
		printf("%d", ret.top());
		ret.pop();
	}
	printf("\n");
	return 0;
}
