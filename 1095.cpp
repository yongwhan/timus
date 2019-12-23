#include<bits/stdc++.h>
using namespace std;

int mod(string s, int n) {
	int sz=s.size(), cur=0;
	for (int i=0; i<sz; i++) {
		cur=cur*10+(s[i]-'0');
		cur%=n;
	}
	return cur;
}
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		set<char> st={'1','2','3','4'};
		for (int i=0; i<s.size(); i++)
			if(st.count(s[i]))
				st.erase(s[i]), s.erase(s.begin()+i), i=-1;
		sort(s.rbegin(),s.rend());
		s+="1234";
		if(s[0]=='0') swap(s.front(),s.back());
		do {
			if(mod(s,7)==0) {
				cout<<s<<endl;
				break;
			}
		} while(next_permutation(s.begin(),s.end()));
	}
	return 0;
}
