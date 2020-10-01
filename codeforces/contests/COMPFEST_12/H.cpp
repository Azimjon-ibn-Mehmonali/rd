
// Problem: H. Huge Boxes of Animal Toys
// Contest: Codeforces - 2020 ICPC, COMPFEST 12, Indonesia Multi-Provincial
// Contest (Unrated, Online Mirror, ICPC Rules, Teams Preferred) URL:
// https://codeforces.com/contest/1425/problem/H Memory Limit: 256 MB Time
// Limit: 2000 ms Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

void f() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if ((a + b) % 2 == 0) {
		cout << "Tidak Tidak ";
		if ((b || c) && !(a || d))
			cout << "Ya Tidak\n";
		else if ((a || d) && !(b || c))
			cout << "Tidak Ya\n";
		else
			cout << "Ya Ya\n";
	} else {
		if ((b || c) && !(a || d))
			cout << "Tidak Ya";
		else if ((a || d) && !(b || c))
			cout << "Ya Tidak";
		else
			cout << "Ya Ya";
		cout << " Tidak Tidak\n";
	}
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
