#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
set<ii> bs;
int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
string label="RTLB";

vector<int> parse(const string &s) {
	stringstream ss(s);
	vector<int> ret;
	int cur;
	while(ss>>cur) ret.push_back(cur);
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line;
	getline(cin,line);
	vector<int> parsed=parse(line);
	if(parsed.size()==1) {
		int b=parsed[0];
		vector<int> x(b), y(b);
		for (int i=0; i<b; i++) {
			getline(cin,line);
			parsed=parse(line);
			x[i]=parsed[0];
			y[i]=parsed[1];
			bs.insert({x[i],y[i]});
		}
		map<ii,vector<ii>> adj;
		for (int i=0; i<b; i++)
			for (int j=0; j<4; j++)
				adj[{x[i],y[i]}].push_back(bs.count({x[i]+dx[j],y[i]+dy[j]})?make_pair(x[i]+dx[j],y[i]+dy[j]):make_pair(0,0));
		queue<ii> q; q.push({x[0],y[0]});
		set<ii> vis; vis.insert({x[0],y[0]});
		cout<<x[0]<<" "<<y[0]<<endl;
		while(b--) {
			ii cur=q.front(); q.pop();
			for (int i=0; i<4; i++) {
				ii nxt=adj[cur][i];
				if(!nxt.first||vis.count(nxt)) continue;
				cout<<label[i];
				vis.insert(nxt);
				q.push(nxt);
			}
			cout<<(!b?".":",")<<endl;
		}
	} else {
		int x=parsed[0], y=parsed[1];
		queue<ii> q; q.push({x,y});
		set<ii> ret;
		while(!q.empty()) {
			ii cur=q.front(); q.pop();
			ret.insert(cur);
			getline(cin,line);
			for (const auto &ch : line) {
				int i=-1;
				for (int j=0; j<4; j++)
					if(label[j]==ch)
						i=j;
				if(i==-1) continue;
				ii nxt=cur;
				nxt.first+=dx[i];
				nxt.second+=dy[i];
				q.push(nxt);
			}
		}
		cout<<ret.size()<<endl;
		for (const auto &p : ret)
			cout<<p.first<<" "<<p.second<<endl;
	}
	return 0;
}
