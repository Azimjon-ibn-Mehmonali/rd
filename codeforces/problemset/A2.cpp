
// Problem: A2. Prefix Flip (Hard Version)
// Contest: Codeforces - Codeforces Round #658 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1381/A2
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

	string a, b;
	cin >> a >> b;

	a.pb('0');
	b.pb('0');

	vi o1, o2;

	for (int i = 1; i <= n; i++)
		if (a[i] != a[i - 1]) o1.pb(i);
	for (int i = 1; i <= n; i++)
		if (b[i] != b[i - 1]) o2.pb(i);

	o1.insert(o1.end(), rALL(o2));

	cout << o1.size() << " ";
	for (int &i : o1)
		cout << i << " ";
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
