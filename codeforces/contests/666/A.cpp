
// Problem: A. Juggling Letters
// Contest: Codeforces - Codeforces Round #666 (Div. 2)
// URL: https://codeforces.com/contest/1397/problem/A
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

	vi a(30, 0);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (char c : s) {
			a[c - 'a']++;
		}
	}

	bool ha = 1;

	for (int i = 0; i < 30; i++) {
		if (a[i]) {
			ha &= a[i] % n == 0;
		}
	}

	if (ha)
		cout << "YES\n";
	else
		cout << "NO\n";
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	// while (t--)
	// f();

	unordered_map<char, int> m;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;

		for (char c : s) {
			m[c]++;
		}
	}

	xtp(m);

	int first = m.begin()->S;
	int yes = 1;
	for (auto [k, v] : m) {
		if (v != first && v % 3 != 0) {
			yes = 0;
		}
	}

	cout << (yes ? "yes" : "no") << endl;

	return 0;
}
