#include<bits/stdc++.h>
using namespace std;

int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,m; cin>>n>>m;
	int grid[n+2][m+2];
	for (int i=0; i<n+2; i++)
		for (int j=0; j<m+2; j++)
			grid[i][j]=0;
	for (int i=0; i<=n+1; i++)
		grid[i][0]=-1, grid[i][m+1]=-1;
	for (int j=0; j<=m+1; j++)
		grid[0][j]=-1, grid[n+1][j]=-1;
	grid[1][1]=1;
	int x=1, y=1, dir=0;
	for (int t=2; t<=n*m; t++) {
		int nx=x+dx[dir], ny=y+dy[dir];
		if(grid[ny][nx]!=0)
			dir=(dir+1)%4, nx=x+dx[dir], ny=y+dy[dir];
		grid[ny][nx]=t;
		x=nx, y=ny;
	}
	int x0,y0,x1,y1; cin>>y0>>x0>>y1>>x1;
	cout<<abs(grid[y1][x1]-grid[y0][x0])<<endl;
	return 0;
}
