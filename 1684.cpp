#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string &s) {
	int n = (int) s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r) z[i] = min (r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}

bool no(const vector<string> &v, const string &s) {
	string t;
	for (const auto & x : v)
		t+=x;
	return s==t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s,t; cin>>s>>t;
	string u=s+"@"+t+"@";;
	vector<int> z=z_function(u);
	int n=s.size(), m=t.size(), mx=n+1, prev=n+1;
	vector<string> ret;
	for (int i=n+1; i<=min(mx,n+m); i++) {
		int cur=i+z[i];
		if(mx<cur) {
			if(i!=prev) {
				ret.push_back(u.substr(prev,i-prev));
			}
			prev=i;
			mx=cur;
		}
	}
	ret.push_back(u.substr(prev,min(mx,n+m+1)-prev));
	if(no(ret,t)) {
		cout<<"No"<<endl;
		int sz=ret.size();
		for (int i=0; i<sz; i++) {
			if(i) cout<<" ";
			cout<<ret[i];
		}
		cout<<endl;
	} else cout<<"Yes"<<endl;
	return 0;
}
