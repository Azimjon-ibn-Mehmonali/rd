
// Problem: M. Short Program
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/M
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

int a[20];

signed main() {
	TEZ;

	int n;
	cin >> n;

	memset(a, -1, sizeof(a));

	char c;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> c >> x;

		if (c == '|') {
			for (int k = 0; k < 10; k++) {
				if ((x & (1 << k))) {
					a[k] = 1;
				}
			}
		} else if (c == '&') {
			for (int k = 0; k < 10; k++) {
				if ((x & (1 << k)) == 0) {
					a[k] = 0;
				}
			}
		} else {
			for (int k = 0; k < 10; k++) {
				if ((x & (1 << k))) {
					if (a[k] == 2)
						a[k] = -1;
					else if (a[k] == -1)
						a[k] = 2;
					else if (a[k] == 1) {
						a[k] = 0;
					} else
						a[k] = 1;
				}
			}
		}
	}

	int va, yo, xo;
	va = 1023;
	yo = 0;
	xo = 0;

	for (int k = 0; k < 10; k++) {
		if (a[k] == 0) {
			va &= ~(1 << k);
		} else if (a[k] == 1) {
			yo |= 1 << k;
		} else if (a[k] == 2) {
			xo |= 1 << k;
		}
	}

	cout << 3 << endl;
	cout << "| " << yo << endl;
	cout << "& " << va << endl;
	cout << "^ " << xo << endl;

	return 0;
}
