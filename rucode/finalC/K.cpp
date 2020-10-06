
// Problem: K. Keen Gardener
// Contest: Yandex - RuCode Championship 2020 Div C
// URL:
// https://official.contest.yandex.com/rucode2020autumn/contest/20369/problems/K/
// Memory Limit: 512 MB
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

const int N = 1e6 + 5;

int a[N], d[N], l[N];

signed main() {
	TEZ;

	int n;
	cin >> n;

	multiset<int> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m.emplace(a[i]);
	}

	int jv = 0;
	while (m.count(jv)) {
		jv++;
	}

	int r = n;
	for (; m.count(a[r]) > 1 || jv < a[r]; r--) {
		m.erase(m.find(a[r]));
	}

	int l = 1;
	for (l = 1; m.count(a[l]) > 1; l++) {
		m.erase(m.find(a[l]));
	}

	cout << l << " " << r << endl;

	return 0;
}
