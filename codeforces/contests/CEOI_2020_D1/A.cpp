
// Problem: A. Fancy Fence
// Contest: Codeforces - Central-European Olympiad in Informatics, CEOI 2020,
// Day 1 (IOI, Unofficial Mirror Contest, Unrated) URL:
// https://codeforces.com/contest/1402/problem/A Memory Limit: 256 MB Time
// Limit: 1000 ms Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

	vi h(n), w(n);
	set<int> hs, ws;

	for (int &i : h)
		cin >> i, hs.insert(i);
	for (int &i : w)
		cin >> i, ws.insert(i);

	if (hs.size() == 1) {
		int s = 0;
		for (int i : w)
			s += i;

		int jv, a, b, c, d;

		a = s;
		b = s + 1;
		c = h[0];
		d = h[0] + 1;

		/*				if (a % 2 == 0)
							a /= 2;
						else
							b /= 2;
						if (c % 2 == 0)
							c /= 2;
						else
							d /= 2;
		*/

		a %= mod;
		b %= mod;
		c %= mod;
		d %= mod;

		cout << (250000002 * ((a * b) % mod) * ((c * d) % mod)) % mod << endl;
	}

	return 0;
}
