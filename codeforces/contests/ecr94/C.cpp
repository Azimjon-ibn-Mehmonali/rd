
// Problem: C. Binary String Reconstruction
// Contest: Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1400/problem/C
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
	string s;
	cin >> s;

	int x, n = s.size();
	cin >> x;

	string w(n, '-');
	vi ke;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (i >= x) {
				w[i - x] = '0';
			}
			if (i + x < n) {
				w[i + x] = '0';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (i >= x && !(i + x < n)) {
				if (w[i - x] == '0') {
					cout << -1 << endl;
					return;
				}
				w[i - x] = '1';
				continue;
			}
			if (!(i >= x) && (i + x < n)) {
				if (w[i + x] == '0') {
					cout << -1 << endl;
					return;
				}
				w[i + x] = '1';
				continue;
			}

			if (i >= x && (i + x < n)) {
				if (w[i - x] == '0' && w[i + x] == '0') {
					cout << -1 << endl;
					return;
				}
				if (w[i - x] == '-') w[i - x] = '1';
				if (w[i + x] == '-') w[i + x] = '1';
				continue;
			}

			cout << -1 << endl;
			return;
		}
	}

	for (char &c : w)
		if (c == '-') c = '1';

	cout << w << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
