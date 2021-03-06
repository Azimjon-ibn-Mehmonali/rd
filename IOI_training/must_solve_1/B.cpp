
// Problem: B. Checkout Assistant
// Contest: Codeforces - must_solve_1
// URL: https://codeforces.com/gym/294367/problem/B
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

	int n;
	cin >> n;

	vi t(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> c[i];
		t[i]++;
	}

	const int N = 10000;

	vi d(N, INF);
	d[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = N / 2; j >= 0; j--) {
			d[j + t[i]] = min(d[j + t[i]], d[j] + c[i]);
		}
	}
	// xtp1(d);
	int jv = INF;
	for (int i = n; i < N; i++)
		jv = min(jv, d[i]);

	cout << jv << endl;

	return 0;
}
