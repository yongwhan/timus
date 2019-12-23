#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string bar="+------------------------------+--------+-------------+";

vector<int> s2n(string &s) {
	stringstream ss(s);
	vector<int> ret;
	int x;
	while(ss>>x) ret.push_back(x);
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string line; getline(cin,line);
	vector<int> v=s2n(line);
	int t=v[0];
	cout<<bar<<endl;
	cout<<"|Contest name                  |Date    |ABCDEFGHIJKLM|"<<endl;
	cout<<bar<<endl;
	for (int c=0; c<t; c++) {
		string title; getline(cin,title);
		string date; getline(cin,date);
		getline(cin,line);
		v=s2n(line);
		int n=v[0];
		map<char,char> mp;
		for (int i=0; i<v[1]; i++) {
			getline(cin,line);
			char key=line[0], val=line[2];
			if(mp[key]!='A') mp[key]=val;
		}
		cout<<"|"<<title<<string(30-title.size(),' ')<<"|"<<date<<"|";
		for (int i=0; i<n; i++) {
			if(!mp.count('A'+i)) cout<<".";
			else cout<<(mp['A'+i]=='A'?'o':'x');
		}
		cout<<string(13-n,' ')<<"|"<<endl;
		cout<<bar<<endl;
	}
	return 0;
}
