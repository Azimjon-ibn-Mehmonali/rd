
// Problem: D1. Sage's Birthday (easy version)
// Contest: Codeforces - Codeforces Round #671 (Div. 2)
// URL: https://codeforces.com/contest/1419/problem/D1
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

	vi a(n);
	for (int &i : a)
		cin >> i;

	SORT(a);
	vi b(n);
	int o = 0, jv = 0;
	for (int i = 1; i < n; i += 2) {
		b[i] = a[o++];
		if (i == n - 1) continue;
	}

	for (int i = 0; i < n; i += 2) {
		b[i] = a[o++];
	}

	for (int i = 1; i < n - 1; i++)
		jv += b[i - 1] > b[i] && b[i] < b[i + 1];

	cout << jv << endl;
	for (int i : b)
		cout << i << " ";

	return 0;
}
