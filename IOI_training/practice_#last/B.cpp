
// Problem: B. Jamie and Interesting Graph
// Contest: Codeforces - Practice #last
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/295403/problem/B
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
const int inf = 1e9;

signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	function<bool(int)> tub = [&](int x) {
		if (x < 2) return 0;
		if (x == 2) return 1;

		for (int i = 2; i * i <= x; i++)
			if (x % i == 0) return 0;
		return 1;
	};

	function<int(int)> ketub = [&](int x) {
		while (!tub(x))
			x++;

		return x;
	};

	int kt = ketub(n);

	cout << kt << " " << kt << endl;

	for (int i = 1; i < n - 1; i++) {
		cout << i << " " << i + 1 << " " << 1 << endl;
	}
	int d = kt - (n - 2);
	cout << n - 1 << " " << n << " " << d << endl;

	m -= n - 1;

	int i, j;
	i = 1, j = 3;

	while (m--) {
		cout << i << " " << j << " " << inf << endl;
		j++;
		if (j > n) {
			i++;
			j = i + 2;
		}
	}

	return 0;
}
