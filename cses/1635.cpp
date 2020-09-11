
// Problem : Coin Combinations I
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1635
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

	vi c(n);
	for (int &i : c)
		sci(i);

	vi dp(x + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < n; j++) {
			if (i + c[j] <= x) dp[i + c[j]] = (dp[i + c[j]] + dp[i]) % mod;
		}
	}

	/*for (int i = 1; i <= x; i++)
		cout << i << " ";
	cout << endl;
	for (int i = 1; i <= x; i++)
		cout << dp[i] << " ";*/

	cout << dp[x] << endl;

	return 0;
}
