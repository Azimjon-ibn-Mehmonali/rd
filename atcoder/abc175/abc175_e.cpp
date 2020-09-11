
// Problem:
// 			E - Picking Goods
//
//
// Contest: AtCoder - AtCoder Beginner Contest 175
// URL: https://atcoder.jp/contests/abc175/tasks/abc175_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

//=========================================================
int recur_depth = 0;
#ifdef DEBUG
#define xtp(x)                                                           \
	{                                                                    \
		++recur_depth;                                                   \
		auto x_ = x;                                                     \
		--recur_depth;                                                   \
		cerr << string(recur_depth, '\t') << __func__ << ":" << __LINE__ \
			 << "\t" << #x << " = " << x_ << endl;                       \
	}
#else
#define xtp(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(
	Ostream& os, const Cont& v) {
	os << "[";
	for (auto& x : v) {
		os << x << ", ";
	}
	return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
	return os << "{" << p.first << ", " << p.second << "}";
}
//=========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

int a[3005][3005], dp[3005][3005], u[3005][3005];

signed main() {
	TEZ;

	int r, c, k;
	cin >> r >> c >> k;

	int q, w, e;
	while (cin >> q >> w >> e) {
		a[q][w] = e;
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}

	int x, y;
	x = r;
	y = c;

	while (1) {
		u[x][y] = 1;
		if ((x == 1 && y == 1)) break;
		if (dp[x][y - 1] >= dp[x - 1][y])
			y--;
		else
			x--;

		if (x < 0) x = 1, y--;
		if (y < 0) y = 1, x--;
	}
	int jv = 0;
	for (int i = 1; i <= r; i++) {
		vi n;
		for (int j = 1; j <= c; j++) {
			if (u[i][j]) n.pb(a[i][j]);
		}
		rSORT(n);
		for (int i = 0; i < min(3ll, (int)n.size()); i++)
			jv += n[i];
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			// cout << u[i][j] << " ";
		}
		// cout << endl;
	}

	cout << jv << endl;

	return 0;
}
