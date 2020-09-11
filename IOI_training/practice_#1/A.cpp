
// Problem: A. Three displays
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/A
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

	vi a(n), c(n);
	for (int &i : a)
		cin >> i;
	for (int &i : c)
		cin >> i;

	int jv = INF;

	for (int j = 1; j < n - 1; j++) {
		int ki = INF;
		for (int i = 0; i < j; i++)
			if (a[i] < a[j]) ki = min(ki, c[i]);
		int kk = INF;
		for (int k = j + 1; k < n; k++)
			if (a[j] < a[k]) kk = min(kk, c[k]);

		jv = min(jv, ki + c[j] + kk);
	}

	cout << (jv == INF ? -1 : jv) << endl;

	return 0;
}
