#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;

	vector<int> v;
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] == ',') s[i] = ' ';
	istringstream ss(s);

	int t;
	while (ss >> t) {
		v.push_back(t);
	}
	vector<int> tmp;

	while (K--) {
		tmp.clear();
		for (int i = 1; i < v.size(); i++) {
			tmp.push_back(v[i] - v[i - 1]);
		}
		v = tmp;
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << ",";
	}
}