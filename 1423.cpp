#include <bits/stdc++.h>
using namespace std;

struct kmp{
	string t,p;
	int* b;
	int* m; 
	kmp(string _t, string _p){
		t = _t;
		p = _p;
		b = new int[p.length()+1];
		m = new int[t.length()+1];
	}
	void init(){
		int i=0,j=-1;
		b[0]=-1;
		while(i<p.length()){
			while(j>=0 && p[j] != p[i]) j=b[j];
			i++; j++;
			b[i]=j;
		}
	}
	int match(){
		int i=0,j=0;
		while(i<t.length()){
			while(j>=0 && p[j] != t[i]) j=b[j];
			i++; j++;
			m[i]=j;
			if(j==p.length()){
				return i-j;
				j = b[j];
			}
		}
		return -1;
	}
};

int main(){
	int n; string s,t;
	cin>>n>>s>>t;
	t+=t;
	kmp u(t,s);
	u.init();
	cout<<u.match()<<endl;
	return 0;
}
