
// Problem: A. Subset Mex
// Contest: Codeforces - Codeforces Round #670 (Div. 2)
// URL: https://codeforces.com/contest/1406/problem/A
// Memory Limit: 512 MB
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
	vi a(105, 0ll);
	int t;
	int ka = -1;
	for (int i = 0; i < n; i++) {
		cin >> t;

		a[t]++;
		ka = max(ka, t);
	}
	// xtp(a);
	int x, y;
	x = y = -1;
	vi bi, ik;
	for (int i = 0; i <= 100; i++) {
		if (a[i] == 1) {
			bi.pb(i);
		} else if (a[i] > 1) {
			bi.pb(i);
			ik.pb(i);
		}
	}

	for (int i = 0; i < bi.size(); i++)
		if (bi[i] != i) {
			x = i;
			break;
		}

	for (int i = 0; i < ik.size(); i++)
		if (ik[i] != i) {
			y = i;
			break;
		}
	if (x == -1) x = ((int)bi.size());
	if (y == -1) y = ((int)ik.size());

	xtp(x);
	xtp(y);
	xtp(bi);
	xtp(ik);

	cout << max(x + y, -1ll) << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
