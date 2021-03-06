
// Problem: C. Division into Teams
// Contest: Codeforces - Codeforces Round #106 (Div. 2)
// URL: https://codeforces.com/problemset/problem/149/C
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

signed main() {
	TEZ;

	int n;
	cin >> n;

	vii a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}

	SORT(a);
	int k = n;

	int i, j;
	i = 0, j = n - 1;
	vi ch, on;
	int cy, oy;
	cy = oy = 0;
	for (int e = 0; e < k / 2; e++) {
		cy += a[i].F;
		ch.pb(a[i].S);
		i++;

		oy += a[i].F;
		on.pb(a[i].S);
		i++;
	}

	if (n & 1) {
		if (cy < oy) {
			ch.pb(a[i].S);
		} else {
			on.pb(a[i].S);
		}
	}

	cout << ch.size() << endl;
	for (int r : ch)
		cout << r + 1 << " ";
	cout << endl;

	cout << on.size() << endl;
	for (int r : on)
		cout << r + 1 << " ";

	return 0;
}
