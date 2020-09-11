
// Problem: B. Ternary Sequence
// Contest: Codeforces - Codeforces Round #665 (Div. 2)
// URL: https://codeforces.com/contest/1401/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int x1, y1, z1;
	int x2, y2, z2;

	cin >> x1 >> y1 >> z1;
	cin >> x2 >> y2 >> z2;

	int t, jv = 0;
	{
		t = min(z1, y2);
		jv += 2 * t;
		z1 -= t;
		y2 -= t;
	}

	{
		t = min(y1, y2);
		y1 -= t;
		y2 -= t;
	}

	{
		t = min(z1, z2);
		z1 -= t;
		z2 -= t;
	}

	{
		t = min(z1, x2);
		z1 -= t;
		x2 -= t;
	}

	{
		t = min(y1, x2);
		y1 -= t;
		x2 -= t;
	}

	{
		t = min(y1, z2);
		jv -= 2 * t;
		y1 -= t;
		z2 -= t;
	}

	cout << jv << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--) {
		f();
	}

	return 0;
}
