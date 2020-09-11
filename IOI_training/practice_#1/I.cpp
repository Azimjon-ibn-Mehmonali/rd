
// Problem: I. Sereja and Brackets
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/I
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

//=========================================================

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//=========================================================
#ifdef DEBUGG
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

const int N = 1111111;

struct mal {
	int jv, o, y;

	ostream& operator<<(ostream& os) {
		os << jv << " " << o << " " << y;
		return os;
	}
};

string s;
int n;
mal t[4 * N];

mal hosil(char c) {
	mal jj;
	jj.jv = jj.o = jj.y = 0;
	if (c == '(')
		jj.o = 1;
	else
		jj.y = 1;

	return jj;
}

mal birlash(mal x, mal y) {
	mal jj;
	int z = min(x.o, y.y);
	jj.jv = x.jv + y.jv + z;

	jj.o = x.o - z + y.o;
	jj.y = x.y + y.y - z;

	return jj;
}

void build(int p, int l, int r) {
	if (l == r) {
		t[p] = hosil(s[l]);
		return;
	}

	int m = (l + r) / 2;

	build(2 * p, l, m);
	build(2 * p + 1, m + 1, r);

	t[p] = birlash(t[2 * p], t[2 * p + 1]);
}

mal ol(int p, int l, int r, int tl, int tr) {
	if (tr < l || r < tl) {
		mal r;
		r.jv = r.o = r.y = 0;

		return r;
	}

	if (tl <= l && r <= tr) return t[p];

	int m = (l + r) / 2;

	mal x = ol(2 * p, l, m, tl, tr);
	mal y = ol(2 * p + 1, m + 1, r, tl, tr);

	return birlash(x, y);
}

signed main() {
	TEZ;

	cin >> s;
	n = s.size();
	s.insert(s.begin(), '-');

	build(1, 1, n);

	int m, l, r;
	cin >> m;
	/*
		for (int i = 1; i <= 4 * n; i++) {
			// cout << i << "--:" << t[i].jv << " " << t[i].o << " " << t[i].y
	   <<
			// endl;
		}
	*/
	for (int i = 0; i < m; i++) {
		cin >> l >> r;

		cout << 2 * ol(1, 1, n, l, r).jv << endl;
	}

	return 0;
}
