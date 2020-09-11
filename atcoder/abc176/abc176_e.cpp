
// Problem: E - Bomber
// Contest: AtCoder - AtCoder Beginner Contest 176
// URL: https://atcoder.jp/contests/abc176/tasks/abc176_e
// Memory Limit: 1024 MB
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

signed main() {
	TEZ;

	int h, w, m;
	cin >> h >> w >> m;

	vi r(h + 1, 0ll), c(w + 1, 0ll);

	int a, b;
	set<ii> el;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		r[a]++;
		c[b]++;

		el.insert({a, b});
	}

	vii rr, cc;
	for (int i = 1; i <= h; i++)
		rr.pb({r[i], i});

	for (int i = 1; i <= w; i++)
		cc.pb({c[i], i});

	rSORT(rr);
	rSORT(cc);

	int ro, co;
	ro = h - 1;
	co = w - 1;

	while (rr[ro].F < rr[0].F)
		ro--;
	while (cc[co].F < cc[0].F)
		co--;

	// random_shuffle(rr.begin(), rr.begin() + ro);
	// random_shuffle(cc.begin(), cc.begin() + co);
	vii u;
	// for (int i = ro; i >= max(0ll, ro - 10); i--) {
	// u.pb(rr[i]);
	// }
	// rr.insert(rr.begin(), u.begin(), u.end());

	// u.clear();
	// for (int i = co; i >= max(0ll, co - 1000); i--) {
	// u.pb(cc[i]);
	// }
	// cc.insert(cc.begin(), u.begin(), u.end());

	int jv = -100;
	for (int i = 0; i < min((int)rr.size(), 20ll); i++) {
		for (int j = 0; j < min((int)cc.size(), 300000ll); j++) {
			int jj = rr[i].F + cc[j].F;

			if (el.count({rr[i].S, cc[j].S})) jj--;

			jv = max(jj, jv);
		}
	}

	for (int i = 0; i < min((int)rr.size(), 300000ll); i++) {
		for (int j = 0; j < min((int)cc.size(), 20ll); j++) {
			int jj = rr[i].F + cc[j].F;

			if (el.count({rr[i].S, cc[j].S})) jj--;

			jv = max(jj, jv);
		}
	}

	cout << jv << endl;

	return 0;
}
