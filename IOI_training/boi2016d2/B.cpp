// Muallif: Azimjon Mehmonali o'g'li

//=========================================================

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//=========================================================
#ifdef DEBUG
#define xtp xtp1
#else
#define xtp(x)
#endif
//=========================================================

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define pb push_back
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define rSORT(a) sort(rALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

void f() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> a(n + 1, string(m + 1, '-'));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 != 0 || (i % 4 == 2 && j == m) || (i % 4 == 0 && j == 1))
				a[i][j] = '.';
			else
				a[i][j] = '#';
		}
	}

	a[1][1] = 'x';

	if (n % 4 == 1) {
		for (int i = max(0ll, m - k) + 1; i <= m; i++)
			a[n][i] = 'o';
		k -= m;

		if (k > 0) {
			for (int i = max(0ll, m - k) + 1; i <= m; i++)
				a[n - 1][i] = 'o';
			k -= m;
		}
	} else if (n % 4 == 2) {
		for (int i = max(0ll, m - k) + 1; i <= m; i++)
			a[n][i] = 'o';
		k -= m;

		if (k > 0) {
			for (int i = max(0ll, m - k) + 1; i <= m; i++)
				a[n - 1][i] = 'o';
			k -= m;
		}
	} else if (n % 4 == 3) {
		for (int i = 1; i <= min(k, m); i++)
			a[n][i] = 'o';
		k -= m;

		if (k > 0) {
			for (int i = max(0ll, m - k) + 1; i <= m; i++)
				a[n - 1][i] = 'o';
			k -= m;
		}
	} else {
		for (int i = 1; i <= min(k, m); i++)
			a[n][i] = 'o';
		k -= m;

		if (k > 0) {
			for (int i = max(0ll, m - k) + 1; i <= m; i++)
				a[n - 1][i] = 'o';
			k -= m;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << a[i][j];
		cout << endl;
	}
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
