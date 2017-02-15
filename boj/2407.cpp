#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
vector<string> v;

class bi {
public:
	int n[104];
	int size;

	bi() {
		memset(n, 0, sizeof(n));
		size = 0;
	}
	bi(lld num) {
		memset(n, 0, sizeof(n));
		size = 0;
		while (num > 0) {
			n[size++] = num % 10;
			num /= 10;
		}
	}

	bi operator+(const bi& b) {
		bi tmp(0);
		int max_size = max(this->size, b.size);

		int up = 0;
		for (int i = 0; i < max_size; i++) {
			int val = this->n[i] + b.n[i] + up;
			if (val >= 10) {
				val -= 10;
				up = 1;
			}
			else {
				up = 0;
			}
			tmp.n[i] = val;
		}
		tmp.size = max_size;
		if (up == 1) {
			tmp.n[max_size] = 1;
			tmp.size++;
		}
		return tmp;
	}

	bi& operator=(const bi& b) {
		memcpy(this->n, b.n, sizeof(this->n));
		this->size = b.size;
		return *this;
	}

	void print() {
		for (int i = size - 1; i >= 0; i--) {
			cout << n[i];
		}
		cout << endl;
	}
};

bi c[104][104];

bi dp(int n, int r) {
	if (n == r || r == 0) return bi(1);

	bi &ret = c[n][r];
	if (ret.size != 0) return ret;
	ret = bi(0);

	ret = dp(n - 1, r - 1) + dp(n - 1, r);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < 104; i++) {
		for (int j = 0; j < 104; j++) {
			c[i][j] = bi(0);
		}
	}
	dp(n, m).print();
}