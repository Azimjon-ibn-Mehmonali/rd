
// Problem: D. Vus the Cossack and Strings
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/D
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

	string a, b;
	cin >> a >> b;

	int i, j;
	i = 0;
	j = b.size() - 1;

	int as, bs, jv;
	as = bs = jv = 0;

	for (int k = 0; k <= j; k++)
		as += a[k] == '1', bs += b[k] == '1';
	if (as % 2 == bs % 2) jv++;

	for (; j < (int)a.size(); i++, j++) {
		if (i == 0) continue;
		if (a[i - 1] == '1') as--;
		if (a[j] == '1') as++;

		jv += as % 2 == bs % 2;
	}

	cout << jv << endl;

	return 0;
}
