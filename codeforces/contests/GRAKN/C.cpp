
// Problem: C. Discrete Acceleration
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	int n, l;
	cin >> n >> l;

	vi a(n);
	for (int &i : a)
		cin >> i;
	a.pb(INF);
	a.insert(a.begin(), -INF);
	n = a.size();

	double c, o;
	c = 0, o = l;
	for (int i = 0; i < 200; i++) {
		double m = (c + o) / 2;

		double t1, t2;
		t1 = t2 = 0;
		double h = 0;
		int v = 1;
		for (int hi = 1; hi < n; hi++) {
			double nk = min(1. * a[hi], m);
			// xtp(nk);
			// xtp(h);
			// xtp(nk - h);
			// xtp(v);
			t1 += 1. * (nk - h) / v;
			h = nk;
			v++;
			if (h >= m) break;
		}

		h = l;
		v = 1;
		for (int hi = n - 2; hi >= 0; hi--) {
			double nk = max(1. * a[hi], m);
			// xtp(nk);
			// xtp(h);
			// xtp(h - nk);
			// xtp(v);
			t2 += 1. * (h - nk) / v;
			h = nk;
			v++;
			if (h <= m) break;
		}
		// xtp(m);
		// xtp(t1);
		// xtp(t2);

		if (fabs(t1 - t2) < 1e-7) {
			cout << setprecision(9) << t1 << endl;
			return;
		} else if (t1 > t2) {
			o = m;
		} else {
			c = m;
		}
	}
	xtp(o);
	xtp(c);
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
