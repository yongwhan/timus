#include <iostream>
using namespace std;

#define LOGSZ 17

int tree[32777];
int N = 32777;
int ret[15777];

// add v to value at x
void set(int x, int v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}

// get cumulative sum up to and including x
int get(int x) {
  int res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}

int main() {
	int n,x,y; scanf("%d", &n);
	for (int i=0; i<n; i++)
		scanf("%d %d", &x, &y), x++, ret[get(x)]++, set(x,1);
	for (int i=0; i<n; i++)
		printf("%d\n", ret[i]);
	return 0;
}
