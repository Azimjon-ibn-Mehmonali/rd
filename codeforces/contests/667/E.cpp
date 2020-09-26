
// Problem: E. Two Platforms
// Contest: Codeforces - Codeforces Round #667 (Div. 3)
// URL: https://codeforces.com/contest/1409/problem/E
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
	int n, k;
	cin >> n >> k;

	vi x(n);
	for (int &i : x)
		cin >> i;
	vi y(n);
	for (int &i : y)
		cin >> i;

	if (n == 1) {
		cout << 1 << endl;
		return;
	}

	SORT(x);
	vi d(n, 1);
	for (int i = 0; i < n; i++) {
		auto it = upper_bound(ALL(x), x[i] + k);
		d[i] = it - (x.begin() + i);
	}
	xtp(x);
	xtp(d);
	vi pr(n, -INF), su(n, -INF);
	pr[0] = d[0];
	su[n - 1] = d[n - 1];
	for (int i = 1; i < n; i++) {
		pr[i] = max(pr[i - 1], d[i - 1]);
	}
	for (int i = n - 2; i > 0; i--) {
		su[i] = max(su[i + 1], d[i]);
	}
	int jv = pr.back();
	for (int i = 0; i < n; i++) {
		if (i + d[i] < n) jv = max(jv, d[i] + su[i + d[i]]);
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
