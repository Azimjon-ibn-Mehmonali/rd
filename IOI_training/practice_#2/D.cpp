
// Problem: D. Field expansion
// Contest: Codeforces - Practice #2
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/294003/problem/D
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

int dp[50][111111];

signed main() {
	TEZ;

	memset(dp, 0, sizeof(dp));
	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;

	vi e(n);
	for (int &i : e)
		cin >> i;

	if ((a <= h && b <= w) || (b <= h && a <= w)) {
		cout << 0 << endl;
		return 0;
	}

	rSORT(e);
	e.insert(e.begin(), 1);
	n = min(n, 40ll);

	dp[0][w] = h;

	for (int i = 0; i < n; i++) {
		for (int hw = 0; hw <= 100000; hw++) {
			if (dp[i][hw] == 0) continue;
			dp[i + 1][hw] = min(dp[i][hw] * e[i + 1], 100001ll);
			dp[i + 1][min(hw * e[i + 1], 100001ll)] = dp[i][hw];

			int x, y;
			x = hw;
			y = dp[i + 1][hw];

			if ((a <= x && b <= y) || (b <= x && a <= y)) {
				cout << i + 1 << endl;

				return 0;
			}
			x = min(hw * e[i + 1], 100001ll);
			y = dp[i + 1][x];
			if ((a <= x && b <= y) || (b <= x && a <= y)) {
				cout << i + 1 << endl;
				return 0;
			}
		}
	}
	/*
		for (int i = 0; i <= 12; i++) {
			for (int j = 0; j < 100000; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
	*/
	cout << -1 << endl;

	return 0;
}
