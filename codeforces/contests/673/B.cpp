
// Problem: B. Two Arrays
// Contest: Codeforces - Codeforces Round #673 (Div. 2)
// URL: https://codeforces.com/contest/1417/problem/B
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
	int n, t;
	cin >> n >> t;

	vi a(n);
	int ys = 0;
	for (int &i : a) {
		cin >> i;
		ys += i == t / 2;
	}

	// SORT(a);
	vi b(n, 0);
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (a[i] == t / 2 && t % 2 == 0) continue;
		mp[a[i]] = 1;
		mp[t - a[i]] = 2;
	}
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == t / 2 && t % 2 == 0) {
			b[i] = x;
			x ^= 1;
		} else {
			b[i] = mp[a[i]] - 1;
		}
	}

	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
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
