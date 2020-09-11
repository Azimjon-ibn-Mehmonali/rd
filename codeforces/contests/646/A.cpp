
// Problem : A. Odd Selection
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/A
// Memory Limit : 256 MB
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
#define sqr(x) ((x) * (x))

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
	int t;
	sci(t);

	while (t--) {
		int n, x;
		sci2(n, x);

		vi a(n);
		int ju, to;
		ju = to = 0;
		for (int &i : a) {
			sci(i);
			i %= 2;
			if (i)
				to++;
			else
				ju++;
		}
		xatop(ju);
		xatop(to);

		if (!to || (x % 2 == 0 && ju == 0)) {
			cout << "No" << endl;
			continue;
		}

		x -= ju;
		if (x < 0) x = 0;
		if ((x & 1) && to) {
			cout << "Yes" << endl;
			continue;
		}

		x++;
		if (to >= x) {
			cout << "Yes" << endl;
			continue;
		}

		cout << "No" << endl;
	}

	return 0;
}
