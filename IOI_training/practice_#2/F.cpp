
// Problem: F. Nikita and string
// Contest: Codeforces - Practice #2
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/294003/problem/F
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

signed main() {
	TEZ;

	string s;
	cin >> s;

	vi a, b;
	int ca, cb;
	a = b = {0};

	for (int c : s) {
		ca = cb = 0;

		if (c == 'a')
			ca++;
		else
			cb++;

		a.pb(a.back() + ca);
		b.pb(b.back() + cb);
	}

	int jv = 0;
	int n = s.size();

	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			int ol = b[i] + b[n] - b[j - 1] + a[j - 1] - a[i];
			jv = max(jv, n - ol);
		}
	}

	cout << jv << endl;

	return 0;
}
