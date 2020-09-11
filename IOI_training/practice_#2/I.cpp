// Problem: I. The Wu
// Contest: Codeforces - Practice #2
// Memory Limit: 256 MB
// Time Limit: 2000 ms

// Muallif: Azimjon Mehmonali o'g'li

//=========================================================

#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

int a[5000][5000], ms[5000], as[5000][200];

signed main() {
	TEZ;

	int n, m, q;
	cin >> n >> m >> q;

	vi w(n);

	for (int i = 0; i < n; i++)
		cin >> w[i];

	function<int(string)> bintod = [&](string s) {
		int jv = 0;
		REV(s);
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == '1') jv |= 1 << i;
		}

		return jv;
	};

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		ms[bintod(s)]++;
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			int yi = 0;
			for (int k = 0; k < n; k++) {
				if ((i & (1 << k)) == (j & (1 << k))) {
					yi += w[n - k - 1];
				}
			}
			if (yi <= 100) as[i][yi] += ms[j];
		}
		for (int j = 1; j <= 100; j++)
			as[i][j] += as[i][j - 1];
	}

	while (q--) {
		string s;
		int d, x;

		cin >> s >> d;

		x = bintod(s);

		cout << as[x][d] << endl;
	}

	return 0;
}