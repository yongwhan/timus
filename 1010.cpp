#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<ll> a(n);
	for (int i=0; i<n; i++)
		cin>>a[i];
	ll mx=-1; int j=-1;
	for (int i=0; i<n-1; i++) {
		ll cur=abs(a[i+1]-a[i]);
		if(mx<cur)
			mx=cur, j=i+1;
	}
	cout<<j<<" "<<j+1<<endl;
	return 0;
}
