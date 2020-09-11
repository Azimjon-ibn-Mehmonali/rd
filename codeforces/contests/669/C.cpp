
// Problem: C. Chocolate Bunny
// Contest: Codeforces - Codeforces Round #669 (Div. 2)
// URL: https://codeforces.com/contest/1407/problem/C
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
// #define endl "\n"

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

int a[11111];

signed main() {
	TEZ;

	int n;
	cin >> n;

	if (n == 1) {
		cout << "! 1" << endl;
		cout.flush();
		return 0;
	}

	function<int(int, int)> sora = [&](int x, int y) {
		cout << "? " << x << " " << y << endl;
		cout.flush();
		int r;
		cin >> r;
		return r;
	};

	int m = 1, k1, k2;
	for (int i = 2; i <= n; i++) {
		k1 = sora(m, i);
		k2 = sora(i, m);
		if (k1 > k2) {
			a[m] = k1;
			m = i;
		} else {
			a[i] = k2;
		}
	}

	a[m] = n;

	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	cout.flush();
	return 0;
}
