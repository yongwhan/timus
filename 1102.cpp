#include<bits/stdc++.h>
using namespace std;

const vector<string> lst={"one", "out", "output", "puton", "in", "input"};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		int sz=s.size();
		vector<bool> flag(sz+1,false);
		flag[0]=true;
		for (int cur=0; cur<=sz; cur++) {
			if(!flag[cur]) continue;
			for (const auto &word : lst)
				if(s.substr(cur,word.size())==word)
					flag[cur+word.size()]=true;
		}
		cout<<(flag[sz]?"YES":"NO")<<'\n';
	}
	return 0;
}
