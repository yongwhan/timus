#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9+777;

char todigit(char ch) {
	switch(ch) {
		case 'i': case 'j':           return '1';
		case 'a': case 'b': case 'c': return '2';
		case 'd': case 'e': case 'f': return '3';
		case 'g': case 'h':           return '4';
		case 'k': case 'l':           return '5';
		case 'm': case 'n':           return '6';
		case 'p': case 'r': case 's': return '7';
		case 't': case 'u': case 'v': return '8';
		case 'w': case 'x': case 'y': return '9';
		case 'o': case 'q': case 'z': return '0';
		default:                      return '@';
	}
}

bool match(const string &s, const string &t) {
	for (int i=0; i<s.size(); i++)
		if(todigit(s[i])!=t[i]) return false;
	return true;
}

vector<int> eval(const string &s, const vector<string> &v) {
	int n=s.size();
	vector<set<ii>> mp(n+1);
	for (int i=0; i<v.size(); i++) {
		string cur=v[i];
		int l=cur.size();
		for (int j=0; j<=n-l; j++)
			if(match(cur,s.substr(j,l)))
				mp[j].insert({j+l,i});
	}
	vector<int> dp(n+1,inf), par(n+1,-1), ans(n+1, -1);
	dp[0]=0;
	queue<int> q; q.push(0);
	while(!q.empty()) {
		int cur=q.front(), val=dp[cur]+1; q.pop();
		for (const auto & nxt : mp[cur])
			if(dp[nxt.first]>val)
				par[nxt.first]=cur, dp[nxt.first]=val, ans[nxt.first]=nxt.second, q.push(nxt.first);
	}

	if(dp[n]==inf) return {};
	vector<int> ret;
	int cur=n;
	while(cur) {
		int nxt=par[cur];
		ret.push_back(ans[cur]);
		cur=nxt;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s;
	while(cin>>s&&s!="-1") {
		int n; cin>>n;
		vector<string> v(n);
		for (int i=0; i<n; i++)
			cin>>v[i];
		vector<int> ret=eval(s,v);
		if(ret.empty()) cout<<"No solution."<<endl;
		else {
			int sz=ret.size();
			for (int i=0; i<sz; i++) {
				if(i) cout<<" ";
				cout<<v[ret[i]];
			}
			cout<<endl;
		}
	}
	return 0;
}
