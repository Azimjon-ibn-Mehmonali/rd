
// Problem: A. Circle Coloring
// Contest: Codeforces - Grakn Forces 2020
// URL: https://codeforces.com/contest/1408/problem/A
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
	int n;
	cin >> n;

	vi a(n), b(n), c(n);
	for (int &i : a)
		cin >> i;
	for (int &i : b)
		cin >> i;
	for (int &i : c)
		cin >> i;

	vi p = {-1};
	for (int i = 0; i < n - 1; i++) {
		if (p.back() != a[i]) {
			p.pb(a[i]);
			continue;
		}
		if (p.back() != b[i]) {
			p.pb(b[i]);
			continue;
		}
		if (p.back() != c[i]) {
			p.pb(c[i]);
			continue;
		}
	}
	int t = p.back(), y = p[1];
	set<int> s({a[n - 1], b[n - 1], c[n - 1]});
	xtp(s);
	s.erase(t);
	s.erase(y);
	p[n] = *prev(s.end());

	for (int i = 1; i <= n; i++) {
		cout << p[i] << " ";
	}
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
