
// Problem: A. Buying Torches
// Contest: Codeforces - Educational Codeforces Round 95 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1418/problem/A
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
	int x, y, k;
	cin >> x >> y >> k;

	int e = k * y + k;

	int jv = 0;
	int n = (k * (y + 1) - 1) / (x - 1);

	int h = 1 + n * (x - 1);

	if (h < e) h += x, n++;

	cout << n + k << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
