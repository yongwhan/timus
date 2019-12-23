#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,map<int,int>> ii;

const int mx=40;
const ll LIMIT=1e18;

vector<ll> ps;

int eval(map<int,int> &mp) {
	ll ret=1;
	int ct=0;
	for (const auto &it : mp) ct+=it.second;
	for (int i=1; i<=12; i++) ret*=(ct+1), ct-=mp[i];
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<bool> flag(mx,true);
	flag[0]=flag[1]=false;
	for (int i=2; i*i<mx; i++)
		if(flag[i])
			for (int j=i; j*i<mx; j++)
				flag[i*j]=false;
	for (int i=0; i<mx; i++)
		if(flag[i])
			ps.push_back(i);
	vector<ll> pri;
	ll cur=1;
	double curd=1;
	for (const auto & p : ps) {
		curd*=p;
		if(curd>LIMIT) break;
		cur*=p;
		pri.push_back(cur);
	}
	queue<ii> q;
	q.push({1,{}});
	map<int,int> mp;
	for (int i=0; i<=11; i++) {
		ll x=pri[i];
		int sz=q.size();
		while(sz--) {
			ii p=q.front(); q.pop();
			ll cur=p.first;
			double curd=p.first;
			mp=p.second;
			while(1) {
				if(curd>LIMIT) break;
				q.push({cur,mp});
				cur*=x; mp[i+1]++; curd*=x;
			}
		}
	}
	map<ll,int> ct;
	while(!q.empty()) {
		ii p=q.front(); q.pop();
		ct[p.first]=eval(p.second);
	}
	set<ll> record;
	int mx=0;
	for (const auto &it : ct)
		if(it.second>mx)
			mx=it.second, record.insert(it.first);
	int t; cin>>t;
	while(t--) {
		ll n; cin>>n;
		auto it=record.upper_bound(n);
		it--;
		ll key=*it;
		cout<<key<<" "<<ct[key]<<endl;
	}
	return 0;
}
