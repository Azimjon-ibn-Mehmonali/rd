
// Problem: D. Vasya and Basketball
// Contest: Codeforces - Practice #3
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/294889/problem/D
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

	int n, m;
	cin >> n;

	vi a(n);
	for (int &i : a)
		cin >> i;

	cin >> m;
	vi b(m);
	for (int &i : b)
		cin >> i;

	SORT(a);
	SORT(b);

	int x, y;
	x = -INF;
	y = INF;
	for (int i = 0; i < n; i++) {
		if (i + 1 < n && a[i + 1] == a[i]) continue;
		int h = a[i];
		int s = 2 * (i) + 3 * (n - i);

		int it = upper_bound(ALL(b), h) - b.begin();

		int sb = 2 * it + 3 * (m - it);

		if (s - sb > x - y) {
			x = s;
			y = sb;
			xtp(b);
			xtp(i);
			xtp(h);
			xtp(x);
			xtp(y);
			xtp(it);
		} /*else if (s - sb == x - y) {
			if (x < s) x = s, y = sb;
		}*/
	}

	cout << x << ":" << y << endl;

	return 0;
}
