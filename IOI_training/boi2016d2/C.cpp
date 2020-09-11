
// Problem: Swap
// Contest: CSES - BOI 2016, day 2
// URL: https://cses.fi/88/task/C
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

vi a, b, c;

signed main() {
	TEZ;

	int n;
	cin >> n;

	a.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	c = a;
	vii q;
	for (int k = 2; k <= n; k++)
		q.pb({k / 2, k});

	for (int i = 0; i < (1 << (n - 1)); i++) {
		b = a;
		for (int j = 0; j < (int)q.size(); j++) {
			if (i & (1 << j)) {
				swap(b[q[j].F], b[q[j].S]);
			}
		}

		c = min(c, b);
	}

	for (int i = 1; i <= n; i++)
		cout << c[i] << " ";

	return 0;
}
