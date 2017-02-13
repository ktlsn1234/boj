#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int N, K, L;

vector<int> vx, vy;
map<int, int> ix, iy;

struct s {
	int sx, sy, ex, ey, w;
	s(int a, int b, int c, int d, int e) {
		sx = a, sy = b, ex = c, ey = d, w = e;
	}
}arr[100004];

int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K >> L;

		int x, y, xx, yy, w;
		for (int i = 0; i < K; i++) {
			cin >> x >> y >> xx >> yy >> w;
			arr[i] = s(x, y, xx, yy, w);
			//vx.push_back(x), vx.push_back(xx);
			//vy.push_back(y), vy.push_back(yy);
		}
		
		/*sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());

		int sz = vx.size();
		for (int i = 0; i < sz; i++) {
			ix[vx[i]] = i;
			ix[vy[i]] = i;
		}

		for (int i = 0; i < K; i++) {
			
		}*/
	}
}