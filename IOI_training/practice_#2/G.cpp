
// Problem: G. Smallest number
// Contest: Codeforces - Practice #2
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/294003/problem/G
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

	vi a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];

	char b[3];
	cin >> b[0] >> b[1] >> b[2];

	// cout << b[0] << b[1] << b[2] << endl;

	int jv = INF;

	SORT(a);
	do {
		vi c;
		c.pb((b[0] == '+') ? a[0] + a[1] : a[0] * a[1]);
		c.pb(a[2]);
		c.pb(a[3]);
		SORT(c);

		xtp(c);

		do {
			vi w;
			w.pb((b[1] == '+') ? c[0] + c[1] : c[0] * c[1]);
			w.pb(c[2]);

			xtp(w);

			jv = min(jv, (b[2] == '+') ? w[0] + w[1] : w[0] * w[1]);

		} while (next_permutation(ALL(c)));
	} while (next_permutation(ALL(a)));

	cout << jv << endl;

	return 0;
}
