
// Problem: F. Maximum Subsequence
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/F
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

signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	int x = n / 2;
	int y = n - x;

	vi a(x), b(y);
	for (int &i : a)
		cin >> i;

	for (int &i : b)
		cin >> i;

	if (n == 1) {
		cout << b[0] % m << endl;
		return 0;
	}

	vi s;
	vi yi;

	for (int i = 0; i < (1 << x); i++) {
		int hs = 0;
		for (int j = 0; j < x; j++)
			if (i & (1 << j)) hs += a[j];
		s.pb(hs % m);
	}

	for (int i = 0; i < (1 << y); i++) {
		int hs = 0;
		for (int j = 0; j < y; j++)
			if (i & (1 << j)) hs += b[j];
		yi.pb(hs % m);
	}

	s.pb(0);
	yi.pb(0);

	int jv = 0;

	SORT(s);
	SORT(yi);

	int i = 0;
	int j = yi.size() - 1;

	while (i < (int)s.size() && 0 <= j) {
		int t = (s[i] + yi[j]);

		if (t >= m) {
			j--;
		} else {
			i++;
		}

		jv = max(jv, t % m);
	}
	i = s.size() - 1, y = 0;
	while (0 <= i && j < (int)yi.size()) {
		int t = (s[i] + yi[j]);

		if (t >= m) {
			i--;
		} else {
			j++;
		}

		jv = max(jv, t % m);
	}

	cout << jv << endl;

	return 0;
}
