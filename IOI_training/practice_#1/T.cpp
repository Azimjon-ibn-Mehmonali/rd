
// Problem: T. Clearing Up
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/T
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

class UnionFind {
   private:
	int sz;
	vi size;
	vi p;

   public:
	UnionFind(int n) {
		sz = n;
		size.assign(n + 1, 1);
		p.assign(n + 1, 0);

		for (int i = 1; i <= n; i++)
			p[i] = i;
	}

	int find(int u) {
		if (p[u] == u) return u;

		return p[u] = find(p[u]);
	}

	void unite(int a, int b) {
		int a = find(a);
		int b = find(b);

		if (a == b) return;

		if (size[a] < size[b]) swap(a, b);
		sz--;
		size[a] += size[b];
		p[b] = a;
	}
};

signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<pair<ii, int>> el(m);

	for (int i = 0; i < n; i++) {
		cin >> el[i].F.F >> el.F.S >> el.S;
		if (el.S == 'S')
			el.S = 1;
		else
			el.S = 2;
	}

	return 0;
}
