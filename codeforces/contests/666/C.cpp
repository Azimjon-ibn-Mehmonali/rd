
// Problem: C. Multiples of Length
// Contest: Codeforces - Codeforces Round #666 (Div. 2)
// URL: https://codeforces.com/contest/1397/problem/C
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

	int n;
	cin >> n;

	vi a(n);
	for (int &i : a)
		cin >> i;

	if (n == 1) {
		cout << "1 1\n0\n";
		cout << "1 1\n0\n";
		cout << "1 1\n" << -a[0];
		return 0;
	}

	int t = n - 1;
	cout << 2 << " " << n << endl;
	for (int i = 1; i < n; i++) {
		int w = a[i];
		a[i] += a[i] * (n - 1);
		cout << w * (n - 1) << " ";
	}
	cout << endl;

	cout << 1 << " " << 1 << endl;
	cout << -a[0] << endl;

	a[0] = 0;

	cout << 1 << " " << n << endl;
	for (int i = 0; i < n; i++) {
		cout << -a[i] << " ";
	}

	return 0;
}
