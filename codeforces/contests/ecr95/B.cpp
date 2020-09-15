
// Problem: B. Negative Prefixes
// Contest: Codeforces - Educational Codeforces Round 95 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1418/problem/B
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
	int n;
	cin >> n;

	int yi = 0;

	vi a(n), l(n);
	for (int &i : a) {
		cin >> i;
		yi += i;
	}
	for (int &i : l)
		cin >> i;

	vi t;

	for (int i = 0; i < n; i++) {
		if (l[i] == 0) {
			t.pb(a[i]);
		}
	}
	vi q(n);
	function<bool(vi)> te = [&](vi w) {
		for (int i = 0; i < n; i++) {
			if (l[i] == 0) {
				q[i] = w.back();
				w.pop_back();
			} else {
				q[i] = a[i];
			}
		}

		bool ha = 1;
		int s = 0;
		for (int &i : q) {
			s += i;
			ha &= s >= 0;
		}

		return ha;
	};

	SORT(t);
	if (te(t))
		goto n1;
	else {
		rSORT(t);
		goto n1;
	}

n1:
	for (int &i : q)
		cout << i << " ";
	cout << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
