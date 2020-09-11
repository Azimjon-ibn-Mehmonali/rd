
// Problem : E. Special Elements
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/E
// Memory Limit : 64 MB
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

#define sqr(x) (x) * (x)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sc scanf
#define pr printf
#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)
#define INF 1000000000
#define mod 1000000007

const double PI = 3.1415926535897932384626433832795;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		// xatop(n);
		int a[8800];
		for (int i = 0; i < n; i++)
			sc("%d", a + i);
		// xatop(a[5]);
		// jsatr;

		int pf[8800];
		pf[0] = 0;

		for (int i = 1; i <= n; i++) {
			pf[i] = pf[i - 1] + a[i - 1];
		}

		// jsatr;

		bitset<64000005> my;

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int yg = pf[j] - pf[i - 1];
				my[yg] = 1;
			}
		}

		// jsatr;

		xatop(my[3]);
		xatop(my[8]);
		xatop(a[5]);

		int jv = 0;
		for (int i = 0; i < n; i++) {
			jv += (int)my[a[i]];
			xatop(a[i]);
			xatop(my[a[i]]);
		}

		// jsatr;

		cout << jv << endl;
	}

	return 0;
}
