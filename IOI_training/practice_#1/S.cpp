
// Problem: S. Portals
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/S
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

	string s;
	cin >> s;

	int st = s.find("s");
	int en = s.find("e");
	vi por;

	for (int i = st; i < n; i++)
		if (s[i] == 'o') {
			por.pb(i);
			break;
		}
	for (int i = st; i >= 0; i--)
		if (s[i] == 'o') {
			por.pb(i);
			break;
		}
	for (int i = en; i < n; i++)
		if (s[i] == 'o') {
			por.pb(i);
			break;
		}
	for (int i = en; i >= 0; i--)
		if (s[i] == 'o') {
			por.pb(i);
			break;
		}

	bool cs, os, ce, oe;
	bool ncs, nos, nce, noe;
	cs = (0 < st) && (s[st - 1] == 'o');
	os = (st < n - 1) && (s[st + 1] == 'o');
	ce = (0 < en) && (s[en - 1] == 'o');
	oe = (en < n - 1) && (s[en + 1] == 'o');

	ncs = (0 < st) && (s[st - 1] == '.');
	nos = (st < n - 1) && (s[st + 1] == '.');
	nce = (0 < en) && (s[en - 1] == '.');
	noe = (en < n - 1) && (s[en + 1] == '.');

	if ((cs || os) && (ce || oe)) {
		cout << -1 << endl;
		return;
	}

	vi bo;

	function<void(int)> dfs = [&](int u) {
		if (bo[u]) return;
		bo[u] = 1;

		if (s[u] == 'o') {
			for (int v : por) {
				dfs(v);
			}
		}

		if (0 < u && s[u - 1] != '#') {
			dfs(u - 1);
		}
		if (u < n - 1 && s[u + 1] != '#') {
			dfs(u + 1);
		}
	};

	function<bool(void)> ha = [&]() {
		bo.assign(n, 0);
		dfs(st);
		return bo[en];
	};

	if (st == 0) {
		s.insert(s.begin(), '#');
		n++;
		for (int &i : por)
			i++;
	} else if (en == 0) {
		s.insert(s.begin(), '#');
		n++;
		for (int &i : por)
			i++;
	}
	en = s.find("e");
	st = s.find("s");
	if (en == n - 1)
		s.pb('#'), n++;
	else if (st == n - 1)
		s.pb('#'), n++;

	string ss = s;

	int jv = INF, jj;

	vi qwe = {0, 8, 4, 2, 1, 12, 10, 9, 6, 5, 3};

	for (int i : qwe) {
		jj = 0;
		if (i & 8) {
			if (s[st - 1] == '.') {
				s[st - 1] = '#';
				jj++;
			}
		}
		if (i & 4) {
			if (s[st + 1] == '.') {
				s[st + 1] = '#';
				jj++;
			}
		}
		if (i & 2) {
			if (s[en - 1] == '.') {
				s[en - 1] = '#';
				jj++;
			}
		}
		if (i & 1) {
			if (s[en + 1] == '.') {
				s[en + 1] = '#';
				jj++;
			}
		}
		if (!ha()) {
			jv = min(jv, jj);
		}

		s = ss;
	}

	if (jv == INF)
		cout << -1 << endl;
	else
		cout << jv << endl;
}

signed main() {
	TEZ;

#ifdef ONLINE_JUDGE
	freopen("portals.in", "r", stdin);
#endif

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
