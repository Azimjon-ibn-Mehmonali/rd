
// Problem : Dice Combinations
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1633
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sc scanf
#define pr printf

#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sqr(x) (x) * (x)

#define sci(n) sc("%d", &n);
#define sci2(n, m) sc("%d%d", &n, &m);
#define scl(n) sc("%I64d", &n);
#define scl2(n, m) sc("%I64d%I64d", &n, &m);

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

int main() {
	int n, x;
	sci2(n, x);

	int c[200];
	for (int i = 0; i < n; i++)
		sci(c[i]);

	int a[1000010] = {0};
	a[0] = 0;
	for (int i = 1; i <= x; i++) {
		a[i] = INF;
		for (int j = 0; j < n; j++) {
			if (i - c[j] >= 0 && a[i - c[j]] != INF) {
				a[i] = min(a[i], a[i - c[j]] + 1);
			}
		}
	}
	// xatop(a[1000]);
	cout << (a[x] == INF ? -1 : a[x]) << endl;

	return 0;
}
