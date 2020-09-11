// Problem : B. Orac and Models
// Contest : Codeforces - Codeforces Round #641 (Div. 2)
// URL : https://codeforces.com/contest/1350/problem/B
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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

int n;
int s[100010];
int dp[100010];

int f(int i) {
	if (i == 1) return 1;

	if (dp[i]) return dp[i];

	int jv = 1;
	for (int k = 1; k * k <= i; k++) {
		if (i % k == 0) {
			if (s[k] < s[i]) jv = max(jv, f(k) + 1);
			if (s[i / k] < s[i]) jv = max(jv, f(i / k) + 1);
		}
	}

	dp[i] = jv;
	return jv;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			cin >> s[i];

		int jv = -INF;
		for (int y = 1; y <= n; y++) {
			jv = max(jv, f(y));
		}

		// xatop(f(3));
		// xatop(f(6));

		cout << jv << endl;
	}

	return 0;
}