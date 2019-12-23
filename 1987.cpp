#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

bool inc(const iii &a, const iii &b) {
	return b.first.first<=a.first.first&&a.first.second<=b.first.second;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<iii> v(n);
	for (int i=0; i<n; i++)
		cin>>v[i].first.first>>v[i].first.second, v[i].second=i+1;
	int m,j=0; cin>>m;
	stack<iii> stk;
	vector<int> c(m);
	for (int i=0; i<m; i++)
		cin>>c[i];
	for (int i=0; i<m; i++) {
		if(stk.empty()||(j<n&&c[i]>=v[j].first.first)) {
			if(j==n) cout<<-1<<endl;
			else {
				if(c[i]<v[j].first.first) cout<<-1<<endl;
				else {
					stk.push(v[j++]);
					while(1) {
						if(j==n) break;
						if(!inc(v[j],stk.top())) break;
						if(c[i]<v[j].first.first) break;
						stk.push(v[j++]);
					}
					i--;
				}
			}
		} else {
			while(!stk.empty()) {
				auto cur=stk.top();
				if(cur.first.first<=c[i]&&c[i]<=cur.first.second) {
					cout<<cur.second<<endl; break;
				}
				else stk.pop();
			}
			if(stk.empty()) i--;
		}
	}
	return 0;
}
