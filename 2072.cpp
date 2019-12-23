#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	ll ret=n;
	vector<int> a(n);
	map<int,ll> left, right;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		if(!left.count(a[i])) left[a[i]]=i;
		right[a[i]]=i;
	}
	set<int> st(a.begin(),a.end());
	vector<int> b(st.begin(),st.end());
	map<int,ll> left_best, right_best;
	auto left_it=left.begin(), right_it=right.begin();
	left_best[(*left_it).first]=((*right_it).second-(*left_it).second)+(*right_it).second;
	right_best[(*right_it).first]=(*right_it).second;
	for (int i=1; i<b.size(); i++) {
		int cur=b[i], prev=b[i-1];
		left_best[cur]=min(left_best[prev]+abs(left[cur]-right[cur])+abs(right[cur]-left[prev]),
		                   right_best[prev]+abs(left[cur]-right[cur])+abs(right[cur]-right[prev]));
		right_best[cur]=min(left_best[prev]+abs(right[cur]-left[cur])+abs(left[cur]-left[prev]),
		                    right_best[prev]+abs(right[cur]-left[cur])+abs(left[cur]-right[prev]));
	}
	ret+=min(left_best[b.back()],right_best[b.back()]);
	cout<<ret<<endl;
	return 0;
}
