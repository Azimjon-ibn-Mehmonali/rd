
// Problem: B. Big Vova
// Contest: Codeforces - Codeforces Round #669 (Div. 2)
// URL: https://codeforces.com/contest/1407/problem/B
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
	for (int &i : a)
		cin >> i;

	SORT(a);

	vi j;
	int w;
	j.pb(a.back());
	w = j.back();
	a.pop_back();

	while (!a.empty()) {
		int e, r;
		e = r = -1;
		// int w = j.back();
		for (int i = 0; i < a.size(); i++) {
			if (gcd(w, a[i]) > e) {
				e = gcd(w, a[i]);
				r = i;
			}
		}
		w = gcd(w, e);
		j.pb(a[r]);
		a.erase(a.begin() + r);
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
