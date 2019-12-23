#include<bits/stdc++.h>
using namespace std;

const int MAX_V=277;
const double INF=1e15;
typedef pair<int,double> id;
typedef pair<double,int> di;
int V;

map<int,map<int,double>> adj;
vector<double> x(MAX_V,0), y(MAX_V,0);

map<int,int> pa;

double dist(double xi, double yi, double xe, double ye) {
	double dx=xi-xe, dy=yi-ye;
	return sqrt(dx*dx+dy*dy);
}

vector<double> dijkstra(int src) {
	vector<double> dist(V, INF);
	dist[src]=0;
	priority_queue<di> pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()) {
		double cost=-pq.top().first;
		int here=pq.top().second;
		pq.pop();
		if(dist[here]<cost) continue;
		for (const auto &it : adj[here]) {
			int there=it.first;
			double nextDist=cost+it.second;
			if(dist[there]>nextDist) {
				dist[there]=nextDist;
				pq.push(make_pair(-nextDist, there));
				pa[there]=here;
			}
		}
	}
	return dist;
}

id get_closest(double xo, double yo) {
	int ret=-1; double val=INF;
	for (int i=0; i<V; i++) {
		double cur=dist(xo,yo,x[i],y[i]);
		if(val>cur) val=cur, ret=i;
	}
	return {ret,val};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	double foot, undg; cin>>foot>>undg;
	int n; cin>>n;
	V=n;
	for (int i=0; i<n; i++)
		cin>>x[i]>>y[i];
	int a,b;
	while(cin>>a>>b) {
		if(!a&&!b) break;
		a--; b--;
		double w=dist(x[a],y[a],x[b],y[b])/undg;
		adj[a][b]=w;
		adj[b][a]=w;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			double w=dist(x[i],y[i],x[j],y[j])/foot;
			if(!adj[i].count(j)) adj[i][j]=w;
			else adj[i][j]=min(adj[i][j],w);
		}
	}

	double xi,yi, xe,ye;
	cin>>xi>>yi>>xe>>ye;
	int sta_i, sta_e;
	double dist_i, dist_e;
	tie(sta_i,dist_i)=get_closest(xi,yi), tie(sta_e,dist_e)=get_closest(xe,ye);
	vector<double> sta_dist=dijkstra(sta_i);
	double used = sta_dist[sta_e]+(dist_i+dist_e)/foot;
	double unused = dist(xi,yi,xe,ye)/foot;
	if(used<unused) {
		cout<<setprecision(15)<<fixed<<used<<endl;
		int cur=sta_e;
		vector<int> ret;
		while(1) {
			ret.push_back(cur+1);
			if(cur==sta_i) break;
			cur=pa[cur];
		}
		reverse(ret.begin(),ret.end());
		cout<<ret.size();
		for (const int & x : ret)
			cout<<" "<<x;
		cout<<endl;
	} else {
		cout<<setprecision(15)<<fixed<<unused<<endl;
		cout<<0<<endl;
	}
	return 0;
}
