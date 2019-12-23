#include<bits/stdc++.h>
using namespace std;

set<string> found;
vector<string> grid(4);
bool vis[4][4];
string s;

int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};

void dfs(int x, int y) {
	s+=grid[x][y];
	found.insert(s);
	for (int i=0; i<4; i++) {
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0||nx>=4||ny<0||ny>=4) continue;
		if(vis[nx][ny]) continue;
		vis[nx][ny]=true;
		dfs(nx,ny);
		vis[nx][ny]=false;
	}
	s.pop_back();
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	for (int i=0; i<4; i++)
		cin>>grid[i];
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++) {
			vis[i][j]=true;
			dfs(i,j);
			vis[i][j]=false;
		}

	int n; cin>>n;
	for (int i=0; i<n; i++) {
		string s; cin>>s;
		cout<<s<<": "<<(found.count(s) ? "YES":"NO")<<endl;
	}
	return 0;
}
