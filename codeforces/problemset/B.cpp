
// Problem: B. Quantity of Strings
// Contest: Codeforces - Codeforces Round #107 (Div. 1)
// URL: https://codeforces.com/problemset/problem/150/B
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

signed main() {
	TEZ;

	int n, m, k;
	cin >> n >> m >> k;

	int jv;
	if (k == 1 || n < k) {
		jv = 1;
		for (int i = 0; i < n; i++)
			jv *= m, jv %= mod;
	} else if (k == n) {
		jv = 1;
		for (int i = 0; i < (n + 1) / 2; i++)
			jv *= m, jv %= mod;
	} else if (k & 1) {
		jv = (m * m) % mod;
	} else {
		jv = m;
	}

	cout << jv << endl;

	return 0;
}
