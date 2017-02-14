#include <bits/stdc++.h>
using namespace std;

int dp[1004];
int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	dp[1] = 1, dp[2] = 0, dp[3] = 1, dp[4] = 1;

	for (int i = 5; i <= N; i++) {
		dp[i] = !dp[i - 1] | !dp[i - 3] | !dp[i - 4];
	}
	if (dp[N] == 1) cout << "SK";
	else cout << "CY";
}