#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

bool cmp(const iii &a, const iii &b) {
	return a.first.second<b.first.second;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,x,y; cin>>n;
	vector<iii> v(n);
	for (int i=0; i<n; i++)
		cin>>x>>y, v[i]={{x,y},i+1};
	set<iii> st;
	sort(v.begin(),v.end());
	for (const auto &a:v) {
		iii cur={{a.first.second,a.first.first},a.second};
		st.insert(cur);
		if(st.size()>a.first.first)
			st.erase(st.begin());
	}
	vector<iii> w(st.begin(),st.end());
	sort(w.begin(),w.end(),cmp);
	cout<<st.size()<<endl;
	bool first=true;
	for (const auto &a:w) {
		if(!first) cout<<" ";
		cout<<a.second;
		first=false;
	}
	cout<<endl;
	return 0;
}
