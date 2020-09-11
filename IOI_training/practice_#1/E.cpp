
// Problem: E. Devu and his Brother
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/E
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

	int n, m;
	cin >> n >> m;

	vi a(n), b(m);
	for (int &i : a)
		cin >> i;
	for (int &i : b)
		cin >> i;

	function<int(int)> bolami = [&](int o) {
		int jj = 0;
		for (int &k : a)
			if (k < o) jj += o - k;
		for (int &k : b)
			if (k > o) jj += k - o;
		return jj;
	};

	int l = 0, r = 2e9;

	for (; (r - l) > 3;) {
		int m1 = (l + r) / 2;
		int m2 = m1 + 1;

		if (bolami(m1) < bolami(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}

	int jv = INF;
	for (int i = l; i <= r; i++)
		jv = min(jv, bolami(i));

	cout << jv << endl;

	return 0;
}
