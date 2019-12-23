#include<bits/stdc++.h>
using namespace std;

const int mx=10, dx[8]={-2,-1,1,2,2,1,-1,-2}, dy[8]={1,2,2,1,-1,-2,-2,-1};
bool vis[mx][mx];
int row[mx*mx],col[mx*mx];
int n,x=0,y=0,mv=0;

void print() {
	for (int i=0; i<n*n; i++)
		cout<<char(row[i]+'a')<<char(col[i]+'1')<<endl;
}

void dfs() {
	vis[x][y]=true;
	row[mv]=x;
	col[mv]=y;
	mv++;
	if(mv==n*n) {
		print();
		exit(0);
	}

	for (int i=0; i<8; i++) {
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(vis[nx][ny]) continue;
		x=nx; y=ny;
		dfs();
	}
	mv--;
	vis[row[mv]][col[mv]]=false;
	mv--;
	x=row[mv]; y=col[mv];
	mv++;
}

int main() {
	cin>>n;
	if(1<=n&&n<=8) dfs();
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
