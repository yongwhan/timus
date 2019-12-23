#include<bits/stdc++.h>
using namespace std;

const int mx=45;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	vector<int> f(mx);
	f[0]=1; f[1]=2;
	for (int i=2; i<mx; i++)
		f[i]=f[i-1]+f[i-2];
	string s=string(n,'0');
	if(f[n]<k) {
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0; i<n; i++)
		if(f[n-i]>=k&&f[n-i-1]<k)
			s[i]++, k-=f[n-i-1], i++;
	cout<<s<<endl;
	return 0;
}
