
// Problem: G. The Best Vacation
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/G
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

	int n, x;
	cin >> n >> x;

	vi a(n);
	for (int &i : a)
		cin >> i;

	a.insert(a.end(), a.begin(), a.end());

	int jv, hs, tu, yy;
	jv = -1;
	hs = tu = yy = 0;

	for (int i = 0; i < n; i++) {
		while (hs < x) {
			int t = a[tu];
			hs += t;
			yy += t * (t + 1) / 2;
			tu++;
		}
		int t = hs - x;
		jv = max(jv, yy - (t * (t + 1)) / 2);
		hs -= a[i];
		yy -= a[i] * (a[i] + 1) / 2;
	}

	cout << jv << endl;

	return 0;
}
