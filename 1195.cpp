#include<bits/stdc++.h>
using namespace std;

enum State {
	CROSSES,
	OUTHS,
	DRAW,
	UNFINISHED,
};

bool ok(const vector<string> &g, char ch) {
	for (int i=0; i<3; i++) {
		int cur=0;
		for (int j=0; j<3; j++)
			if(g[i][j]==ch)
				cur++;
		if(cur==3) return true;
		cur=0;
		for (int j=0; j<3; j++)
			if(g[j][i]==ch)
				cur++;
		if(cur==3) return true;
	}
	int cur=0;
	for (int i=0; i<3; i++)
		if(g[i][i]==ch)
			cur++;
	if(cur==3) return true;
	cur=0;
	for (int i=0; i<3; i++)
		if(g[i][2-i]==ch)
			cur++;
	return cur==3;
}

void print(const vector<string> &g) {
	for (int i=0; i<3; i++)
		cout<<g[i]<<endl;
}

State get_state(const vector<string> &g) {
	if(ok(g,'X')) return CROSSES;
	else if(ok(g,'O')) return OUTHS;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			if(g[i][j]=='#') return UNFINISHED;
	return DRAW;
}

State verdict(vector<string> g, bool cross) {
	State state=get_state(g);
	if(state!=UNFINISHED) {
		int tot=0, crosses=0, ouths=0;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				if(g[i][j]!='#') continue;
				vector<string> h=g;
				if(cross) h[i][j]='X';
				else h[i][j]='O';
				State cur=verdict(h,!cross);
				tot++;
				if(cur>0) pos++;
				else if(cur<0) neg++;
			}
		}
		state=0;
		if(!cross) swap(pos,neg);
		if(pos==tot) state=-1;
		else if(neg) state=1;
	}
	if(!cross) state=-state;
/*
	cout<<endl<<endl;
	cout<<"!!!!!!!!!!!!!!!"<<endl;
	print(g);
	if(cross) cout<<"CROSSES TURN"<<endl;
	else cout<<"OUTHS TURN"<<endl;
	if(state==1) cout<<"WON"<<endl;
	else if(state==-1) cout<<"LOST"<<endl;
	else cout<<"DRAW"<<endl;
*/
	return state;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	vector<string> g(3);
	for (int i=0; i<3; i++) cin>>g[i];
	int ret=verdict(g,true);
	if(ret==1) cout<<"Ouths win"<<endl;
	else if(ret==-1) cout<<"Crosses win"<<endl;
	else cout<<"Draw"<<endl;
	return 0;
}
