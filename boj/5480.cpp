#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int N, K, L;

vector<int> vx, vy;
map<int, int> ix, iy;

struct s {
	int sx, sy, ex, ey, w;
	s(){}
	s(int a, int b, int c, int d, int e) {
		sx = a, sy = b, ex = c, ey = d, w = e;
	}
};

int main() {
	ios::sync_with_stdio(false);

	int T;
	scanf("%d", &T);
	list<s> ls;
	while (T--) {
		scanf("%d%d%d", &N, &K, &L);

		ls.clear();
		int x, y, xx, yy, w;
		for (int i = 0; i < K; i++) {
			scanf("%d%d%d%d%d", &x, &y, &xx, &yy, &w);
			ls.push_back(s(x, y, xx, yy, w));
		}
		
		int a, b;
		for (int i = 0; i < L; i++) {
			scanf("%d%d", &a, &b);

			list<s>::iterator it = ls.begin();

			int maxs = 0;
			while (it != ls.end()) {
				bool inc = true;
				if (b == 0) {
					int st = it->sy, ed = it->ey;
					if (st > ed) swap(st, ed);
					if (st <= a && ed >= a) {
						maxs = max(maxs, it->w);
						it = ls.erase(it);
						inc = false;
					}
				}
				else {
					int st = it->sx, ed = it->ex;
					if (st > ed) swap(st, ed);
					if (st <= a && ed >= a) {
						maxs = max(maxs, it->w);
						it = ls.erase(it);
						inc = false;
					}
				}
				if (inc) it++;
			}
			printf("%d\n", maxs);
		}
	}
}