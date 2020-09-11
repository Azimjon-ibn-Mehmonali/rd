
// Problem : Grid Paths
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1638
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

int n, a[1005][1005], dp[1005][1005] = {0};

bool mum(int i, int j) { return 0 <= i && i < n && 0 <= j && j < n && a[i][j]; }

int main() {
	TEZ;

	cin >> n;

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;

			if (c == '.')
				a[i][j] = 1;
			else
				a[i][j] = 0;

			// cout << c;
		}
		// cout << endl;
	}

	if (!a[n - 1][n - 1]) {
		cout << 0 << endl;
		return 0;
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!a[i][j]) continue;
			if (mum(i + 1, j)) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			if (mum(i, j + 1)) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
		}
	}

	// for (int i = 0; i < n; i++) {
	// for (int j = 0; j < n; j++) {
	// cout << dp[i][j] << " ";
	// }
	// cout << endl;
	// }

	cout << dp[n - 1][n - 1] << endl;

	return 0;
}
