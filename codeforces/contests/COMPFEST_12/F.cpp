
// Problem: F. Flamingoes of Mystery
// Contest: Codeforces - 2020 ICPC, COMPFEST 12, Indonesia Multi-Provincial
// Contest (Unrated, Online Mirror, ICPC Rules, Teams Preferred) URL:
// https://codeforces.com/contest/1425/problem/F Memory Limit: 256 MB Time
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

signed main() {
	TEZ;

	int n;
	cin >> n;

	function<int(int, int)> sora = [&](int l, int r) {
		int t;
		cout << "? " << l << " " << r << endl;
		cout.flush();
		cin >> t;

		return t;
	};

	vi a(n + 1, 0);
	int yi = sora(1, n);
	int t;
	for (int i = n; i >= 3; i--) {
		t = sora(1, i - 1);
		a[i] = yi - t;
		yi -= yi - t;
	}
	int y = sora(2, 3);
	a[2] = y - a[3];

	a[1] = t - a[2];

	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout.flush();

	return 0;
}
