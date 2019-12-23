#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const int mx=1e7+777;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<int> flag(mx,true);
	flag[0]=flag[1]=false;
	for (int i=2; i*i<mx; i++)
		if(flag[i])
			for (int j=i; j*i<mx; j++)
				flag[i*j]=false;
	vector<int> ps;
	for (int i=0; i<mx; i++)
		if(flag[i])
			ps.push_back(i);

	long long x; cin>>x;
	int ret=0;
	for (const auto &p : ps)
		while(x%p==0)
			x/=p, ret++;
	if(x>1) ret++, x=1;
	cout<<(x==1&&ret==20?"Yes":"No")<<endl;
	return 0;
}
