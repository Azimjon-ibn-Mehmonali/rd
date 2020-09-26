
// Problem: B. Minimum Product
// Contest: Codeforces - Codeforces Round #667 (Div. 3)
// URL: https://codeforces.com/contest/1409/problem/B
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
	int a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;

	int aa, bb, xx, yy, nn;
	aa = a;
	bb = b;
	xx = x;
	yy = y;
	nn = n;
	if (x > y) {
		swap(x, y);
		swap(a, b);
	}
	int jv = INF;

	{
		int z = min(a - x, n);
		n -= z;
		a -= z;

		z = min(b - y, n);
		n -= z;
		b -= z;

		jv = min(jv, a * b);
	}
	a = aa;
	b = bb;
	x = xx;
	y = yy;
	n = nn;
	if (a > b) {
		swap(x, y);
		swap(a, b);
	}
	{
		int z = min(a - x, n);
		n -= z;
		a -= z;

		z = min(b - y, n);
		n -= z;
		b -= z;

		jv = min(jv, a * b);
	}

	cout << jv << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
