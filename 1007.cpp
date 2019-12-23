#include<bits/stdc++.h>
using namespace std;

bool ok(const string &s, int n) {
	int sz=s.size(), ret=0;
	for (int i=0; i<sz; i++)
		if(s[i]=='1')
			ret=(ret+(i+1))%(n+1);
	return !ret;
}

string add(const string &s, int n) {
	for (int i=0; i<=s.size(); i++) {
		string u,v;
		if(i) u=s.substr(0,i);
		if(i<s.size()) v=s.substr(i);
		for (char ch='0'; ch<='1'; ch++) {
			string t=u+ch+v;
			if(ok(t,n)) return t;
		}
	}
	return "@";
}

string replace(string s, int n) {
	if(ok(s,n)) return s;
	int sz=s.size();
	for (int i=0; i<sz; i++)
		if(s[i]=='1') {
			s[i]='0';
			if(ok(s,n)) return s;
			s[i]='1';
		}
	return "@";
}

string remove(const string &s, int n) {
	int sz=s.size();
	for (int i=0; i<sz; i++) {
		string t=s;
		t.erase(t.begin()+i);
		if(ok(t,n)) return t;
	}
	return "@";
}

string eval(const string &s, int n) {
	int sz=s.size();
	if(sz==n-1) return add(s,n);
	else if(sz==n) return replace(s,n);
	else if(sz==n+1) return remove(s,n);
	else return "@";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	string s;
	while(cin>>s) cout<<eval(s,n)<<endl;
	return 0;
}
