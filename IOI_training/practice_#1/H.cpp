
// Problem: H. Imbalanced Array
// Contest: Codeforces - Practice #1
// URL: https://codeforces.com/group/mcSSKLGGT5/contest/293496/problem/H
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

const int N = 1111111;

int a[N], l[N], r[N], ll[N], rr[N];

signed main() {
	TEZ;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	stack<int> xir;

	for (int i = 1; i <= n; i++) {
		while (!xir.empty() && a[xir.top()] <= a[i])
			xir.pop();
		if (xir.empty())
			l[i] = 0;
		else
			l[i] = xir.top();
		xir.push(i);
	}

	while (xir.size())
		xir.pop();

	for (int i = n; i > 0; i--) {
		while (!xir.empty() && a[xir.top()] < a[i])
			xir.pop();
		if (xir.empty())
			r[i] = n + 1;
		else
			r[i] = xir.top();
		xir.push(i);
	}

	while (xir.size())
		xir.pop();

	for (int i = 1; i <= n; i++) {
		while (!xir.empty() && a[xir.top()] >= a[i])
			xir.pop();
		if (xir.empty())
			ll[i] = 0;
		else
			ll[i] = xir.top();
		xir.push(i);
	}

	while (xir.size())
		xir.pop();

	for (int i = n; i > 0; i--) {
		while (!xir.empty() && a[xir.top()] > a[i])
			xir.pop();
		if (xir.empty())
			rr[i] = n + 1;
		else
			rr[i] = xir.top();
		xir.push(i);
	}

	int ki, ka;
	ki = ka = 0;
	/*
		for (int i = 1; i <= n; i++) {
			cout << ll[i] << " " << rr[i] << endl;
		}
	*/
	for (int i = 1; i <= n; i++) {
		ki += a[i] * (rr[i] - i) * (i - ll[i]);

		ka += a[i] * (r[i] - i) * (i - l[i]);
	}

	xtp(ka);
	xtp(ki);
	cout << ka - ki << endl;

	return 0;
}
