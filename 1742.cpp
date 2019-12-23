#include <bits/stdc++.h>
using namespace std;

#define mx 200000
#define mod 1000000007ll

typedef long long ll;
typedef vector<int> vi;
#define mem(x,val) memset((x),(val),sizeof(x));
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define sz(x) ((int)x.size())
#define pb push_back

vi edge[mx];
int _low[mx], _dtime[mx], _dfstime, _stack[mx], _size, _comp[mx], _comps;
bool _instack[mx];

void tarjan(int u){
	_low[u]=_dtime[u]=++_dfstime;
	_stack[_size++]=u;
	_instack[u]=true;

	rep(i,sz(edge[u])){
		int v=edge[u][i];
		if(_dtime[v]==-1) tarjan(v), _low[u]=min(_low[u],_low[v]);
		else if(_instack[v]) _low[u]=min(_low[u],_dtime[v]);
	}

	if(_dtime[u]==_low[u]){
		_comps++;
		int v=-1;
		do{
			v=_stack[--_size];
			_instack[v]=false;
			_comp[v]=_comps;
		}while(u!=v);
	}
}

void scc(int n){
	_comps=_dfstime=_size=0;
	mem(_dtime,-1);
	mem(_low,0);
	mem(_stack,0);
	mem(_comp,0);
	mem(_instack,0);
	rep(i,n) if(_dtime[i]==-1)tarjan(i);
}

typedef vector<int> vi;

class UnionFind { 
	private:
		vi p, rank, setSize;
		int numSets;
	public:
		UnionFind(int N) {
			setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
			p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j) { 
			if (!isSameSet(i, j)) { numSets--; 
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
				else                   { p[x] = y; setSize[y] += setSize[x];
					if (rank[x] == rank[y]) rank[y]++; } } }
		int numDisjointSets() { return numSets; }
		int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
	int n; cin>>n;
	UnionFind UF(n);
	vector<int> deg(n,0);
	for (int i=0; i<n; i++) {
		int x; cin>>x; x--;
		edge[i].pb(x);
		deg[i]++; deg[x]++;
		UF.unionSet(i,x);
	}
	scc(n);
	int ret=0;
	set<int> cmp;
	for (int i=0; i<n; i++)
		if(deg[i]==1)
			ret++, cmp.insert(UF.findSet(i));
	for (int i=0; i<n; i++) {
		int cur=UF.findSet(i);
		if(cmp.count(cur)) continue;
		cmp.insert(cur); ret++;
	}
	cout<<ret<<" "<<_comps<<endl;
	return 0;
}
