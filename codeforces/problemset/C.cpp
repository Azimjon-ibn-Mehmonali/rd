
// Problem: C. Graph and String
// Contest: Codeforces - Practice #3
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/294889/problem/C
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

int a[600][600];

signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<vi> g(n + 1, vi());
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		a[x][y] = a[y][x] = 1;
		g[x].pb(y);
		g[y].pb(x);
	}

	string s(n + 1, '-');

	for (int i = 1; i <= n; i++) {
		if (g[i].size() == n - 1) {
			s[i] = 'b';
		}
	}

	for (int i = 1; i <= n; i++) {
		if (s[i] == '-') {
			s[i] = 'a';
			for (int h : g[i]) {
				if (s[h] == '-') s[h] = 'a';
			}
			break;
		}
	}

	bool ja = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '-') {
			s[i] = 'c';
			bool ha = 1;

			for (int h : g[i]) {
				if (s[h] == 'a') {
					ha = 0;
					break;
				}
				if (s[h] == '-') s[h] = 'c';
			}
			ja &= ha;
			break;
		}
	}
	xtp(ja);
	for (int i = 1; i <= n; i++) {
		ja &= s[i] != '-';
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (s[i] == s[j] || s[i] + 1 == s[j] || s[j] + 1 == s[i]) {
				ja &= a[i][j];
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j]) {
				ja &= (s[i] == s[j]) || (abs(s[i] - s[j]) == 1);
			}
		}
	}

	if (ja) {
		cout << "Yes\n" << s.substr(1, n) << endl;
	} else {
		cout << "No\n" << endl;
	}

	return 0;
}
