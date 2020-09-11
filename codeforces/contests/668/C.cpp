
// Problem: C. Balanced Bitstring
// Contest: Codeforces - Codeforces Round #668 (Div. 2)
// URL: https://codeforces.com/contest/1405/problem/C
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

	string s;
	cin >> s;

	string j = s.substr(0, k);
	int ns, bs, ss;
	ns = bs = ss = 0;

	for (char c : j) {
		if (c == '0')
			ns++;
		else if (c == '1')
			bs++;
		else
			ss++;
	}
	if (ns > k / 2 || bs > k / 2) {
		cout << "NO" << endl;
		return;
	}

	for (int i = 0; i < n; i += k) {
		for (int q = 0; q < min(k, n - i); q++) {
			if ((s[i + q] == '0' || s[i + q] == '1')
				&& (j[q] == '0' || j[q] == '1')) {
				if (s[i + q] != j[q]) {
					cout << "NO" << endl;
					return;
				}
				continue;
			}
			if (s[i + q] == '?') continue;
			j[q] = s[i + q];
			if (j[q] == '0')
				ns++;
			else if (j[q] == '1')
				bs++;
			else
				ss++;
			if (ns > k / 2 || bs > k / 2) {
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
