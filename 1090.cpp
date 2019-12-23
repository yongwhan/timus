#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
	private:
		vi ft;
	public:
		FenwickTree() {}
		FenwickTree(int n) { ft.assign(n + 1, 0); }
		int rsq(int b) {
			int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
			return sum;
		}
		int rsq(int a, int b) {
			return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
		}
		void adjust(int k, int v) {
			for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
		}
};

int main() {
	int n,k,ret=0,mx=-1; cin>>n>>k;
	for (int c=1; c<=k; c++) {
		map<int,int> order;
		for (int i=1; i<=n; i++) {
			int x; cin>>x;
			order[-x]=i;
		}
		FenwickTree ft(n);
		int cur=0;
		for (const auto &it : order)
			cur+=ft.rsq(it.second), ft.adjust(it.second,1);
		if(mx<cur) mx=cur, ret=c;
	}
	cout<<ret<<endl;
	return 0;
}
