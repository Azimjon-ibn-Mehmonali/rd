
// Problem: A. Digit Game
// Contest: Codeforces - Codeforces Round #671 (Div. 2)
// URL: https://codeforces.com/contest/1419/problem/A
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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		vi a(n);
		for (int i = 0; i < n; i++)
			a[i] = s[i] - '0';

		int tt, tj, jj, jt;
		tt = tj = jj = jt = 0;

		for (int i = 0; i < n; i++) {
			if ((i + 1) % 2) {
				if (a[i] % 2)
					tt++;
				else
					tj++;
			} else {
				if (a[i] % 2)
					jt++;
				else
					jj++;
			}
		}
		bool ra = 1;
		for (int i = 0; i < n - 1; i++) {
			if (ra) {
				if (tj) {
					tj--;
				} else {
					tt--;
				}
			} else {
				if (jt)
					jt--;
				else
					jj--;
			}
			ra = !ra;
		}

		if (tj + jj)
			cout << 2 << endl;
		else
			cout << 1 << endl;
	}

	return 0;
}
