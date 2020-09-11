
// Problem : BT engine
// Contest : CodeChef - Crack me if you can!
// URL : https://www.codechef.com/CMYC2020/problems/BTENG
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
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sc scanf
#define pr printf
#define endl "\n"

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
		int n, k;
		sci2(n, k);

		vi a;
		int h = 1;
		int mx = -1;
		int xl[131075] = {0};
		for (int i = 1; i <= n; i++) {
			h = h xor i;
			mx = max(h, mx);
			// a.pb(h);
			xl[h]++;
			// cout << h << endl;
		}

		int hs = mx;
		while (k) {
			if (hs < 0) {
				cout << -1 << endl;
			}
			if (k <= xl[hs]) {
				cout << hs << endl;
				k = 0;
			} else
				k -= xl[hs], hs--;
		}
	}

	return 0;
}
