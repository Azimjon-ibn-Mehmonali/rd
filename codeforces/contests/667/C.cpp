
// Problem: C. Yet Another Array Restoration
// Contest: Codeforces - Codeforces Round #667 (Div. 3)
// URL: https://codeforces.com/contest/1409/problem/C
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

void f() {
	int n, x, y;
	cin >> n >> x >> y;
	vi j;
	for (int i = 1; i <= y - x; i++) {
		vi a;
		for (int k = x; k <= y; k += i)
			a.pb(k);
		if (a.back() != y) continue;
		if (a.size() > n) continue;
		int q = n - a.size();
		for (int g = x - i; g > 0 && q > 0; g -= i, q--) {
			a.insert(a.begin(), g);
		}
		for (int g = y + i; q > 0; g += i, q--) {
			a.pb(g);
		}
		j = a;
		break;
	}
	for (int g : j)
		cout << g << " ";
	cout << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
