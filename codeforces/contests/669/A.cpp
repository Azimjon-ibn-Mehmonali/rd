
// Problem: A. Ahahahahahahahaha
// Contest: Codeforces - Codeforces Round #669 (Div. 2)
// URL: https://codeforces.com/contest/1407/problem/A
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
	int n;
	cin >> n;

	vi a(n);
	int s = 0;
	for (int &i : a)
		cin >> i, s += i;

	if (n == 2) {
		if (a[0] == 1 && a[1] == 1) {
			cout << "2\n1 1\n";
			return;
		}
	}

	if (s > n / 2) {
		int q = n / 2;
		if (q & 1) q++;
		cout << q << endl;
		for (int i = 0; i < q; i++)
			cout << "1 ";
		cout << endl;
	} else {
		cout << n / 2 << endl;
		for (int i = 0; i < n / 2; i++)
			cout << "0 ";
		cout << endl;
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
