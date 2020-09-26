
// Problem: C. Mortal Kombat Tower
// Contest: Codeforces - Educational Codeforces Round 95 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1418/problem/C
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

void f() {
	int n;
	cin >> n;

	vi a(n);
	for (int &i : a)
		cin >> i;
	a.insert(a.begin(), 0);
	vector<vi> d(n + 1, vi(2, INF));
	d[0][1] = 0;

	for (int i = 0; i <= n; i++) {
		if (i > 0) d[i][1] = min(d[i][1], d[i - 1][0]);
		if (i > 1) d[i][1] = min(d[i][1], d[i - 2][0]);

		if (i > 0) d[i][0] = min(d[i][0], d[i - 1][1] + a[i]);
		if (i > 1) d[i][0] = min(d[i][0], d[i - 2][1] + a[i - 1] + a[i]);
	}

	cout << min(d[n][0], d[n][1]) << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
