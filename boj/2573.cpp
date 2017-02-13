#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;

int arr[304][304];
int N, M;
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
bool visited[303][303];

void step() {
	int tmp[304][304];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ti = i + dy[k], tj = j + dx[k];
					if (ti >= 0 && tj >= 0 && ti < N && tj < M && arr[ti][tj] == 0) {
						tmp[i][j]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] != 0) {
				arr[i][j] -= tmp[i][j];
				arr[i][j] = max(0, arr[i][j]);
			}
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ti = y + dy[i], tj = x + dx[i];
		if (ti >= 0 && tj >= 0 && ti < N && tj < M && arr[ti][tj] != 0 && !visited[ti][tj]) {
			dfs(ti, tj);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> M;
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	while (1) {
		step();

		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			ans = 0; break;
		}
		ans++;
		if (cnt >= 2) break;
	}
	cout << ans << endl;
}