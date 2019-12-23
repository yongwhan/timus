#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_V=1e5+5, INF=1e15;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

vector<ii> adj[MAX_V];

int dijkstra(int src, int dst) {
	vector<int> ret;
	for (int i=0; i<2; i++) {
		ii init={src,i};
		map<ii,int> dist; dist[init]=0;
		priority_queue<iii> pq;
		pq.push({0,{init}});
		while(!pq.empty()) {
			int cost=-pq.top().first;
			ii here=pq.top().second;
			pq.pop();
			if(dist[here]<cost) continue;
			for (int i=0; i<adj[here.first].size(); i++) {
				ii blah=adj[here.first][i];
				int there=blah.first, nextDist=cost+(blah.second!=here.second);
				if(!dist.count(blah) || (dist.count(blah)&&dist[blah]>nextDist)) {
					dist[blah]=nextDist;
					pq.push({-nextDist, blah});
				}
			}
		}
		ii up={dst,0}, down={dst,1};
		if(dist.count(up)) ret.push_back(dist[up]);
		if(dist.count(down)) ret.push_back(dist[down]);
	}
	return *min_element(ret.begin(),ret.end());
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	for (int i=0; i<m; i++) {
		int x,y; cin>>x>>y; x--; y--;
		adj[x].push_back({y,1});
		adj[y].push_back({x,0});
	}
	int x,y; cin>>x>>y; x--; y--;
	cout<<dijkstra(x,y)<<endl;
	return 0;
}
