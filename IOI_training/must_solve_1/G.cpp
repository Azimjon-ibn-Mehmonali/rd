
// Problem: G. Strange Game On Matrix
// Contest: Codeforces - must_solve_1
// URL: https://codeforces.com/gym/294367/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

int a[300][300];

signed main() {
	TEZ;

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int x, y;
	x = y = 0;
	for (int j = 1; j <= m; j++) {
		ii jv = {0, INF};
		int bs = 0;
		for (int i = 0; i <= n; i++) {
			bs += a[i][j];
			int yi = 0;
			for (int e = i + 1; e <= (n, i + k); e++)
				yi += a[e][j];
			jv = max(jv, {yi, -bs});
		}

		if (bs == 0 || jv.S == INF) continue;

		x += jv.F;
		y += -jv.S;
	}

	cout << x << " " << y << endl;

	return 0;
}
