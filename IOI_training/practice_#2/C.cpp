
// Problem: C. Math Show
// Contest: Codeforces - Practice #2
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/294003/problem/C
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

	int n, k, m;
	cin >> n >> k >> m;

	vi a(k);
	int s = 0;
	for (int i = 0; i < k; i++)
		cin >> a[i], s += a[i];

	int jv = 0;

	for (int i = 0; i <= n; i++) {
		if (i * s > m) break;
		int jj = 0;
		int q = m - i * s;
		jj += i * (k + 1);

		int w = n - i;
		vi d;
		for (int e = 0; e < w; e++)
			d.insert(d.end(), a.begin(), a.end());

		rSORT(d);

		while (!d.empty() && q - d.back() >= 0) {
			q -= d.back();
			d.pop_back();
			jj++;
		}

		jv = max(jv, jj);
	}

	cout << jv << endl;

	return 0;
}
