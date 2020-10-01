
// Problem: B. Arrays Sum
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/B
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
	int n, k;
	cin >> n >> k;

	vi a(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}

	if (k == 1) {
		if (s.size() == 1) {
			cout << 1 << endl;
			return;
		}
		cout << -1 << endl;
		return;
	}

	int jv = 0;
	while (true) {
		jv++;
		int g = 1;
		int d = a[0];
		a[0] = 0;
		for (int i = 1; i < n; i++) {
			if (g == k) {
				a[i] -= d;
				continue;
			}
			if (d < a[i]) {
				g++;
				xtp(d);
				d = a[i];
				a[i] -= d;
			} else {
				a[i] -= d;
			}
		}
		xtp(a);
		xtp(d);
		xtp(g);
		int yi = accumulate(ALL(a), 0);
		if (yi == 0) break;
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
