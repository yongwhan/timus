#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll u,d=1,l=1,r,f=1,b,um,rm,bm;
	cin>>rm>>um>>bm; u=um; r=rm; b=bm;
	string s; cin>>s;
	for (const char &ch:s) {
		switch(ch) {
			case 'u': u=min(u+1, um); d=min(d+1, um); break;
			case 'd': u=max(u-1,1LL); d=max(d-1,1LL); break;
			case 'l': l=max(l-1,1LL); r=max(r-1,1LL); break;
			case 'r': l=min(l+1, rm); r=min(r+1, rm); break;
			case 'f': f=max(f-1,1LL); b=max(b-1,1LL); break;
			case 'b': f=min(f+1, bm); b=min(b+1, bm); break;
		}
	}
	cout<<(u-d+1)*(r-l+1)*(b-f+1)<<endl;
	return 0;
}
