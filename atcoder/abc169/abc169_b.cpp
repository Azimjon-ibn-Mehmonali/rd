
// Problem : B - Multiplication 2
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
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
const ull mx = 1000000000000000000ll;

int main() {
	TEZ;

	int n;
	cin >> n;

	ll t, p = 1;
	ld k = 1;
	while (n--) {
		cin >> t;

		k *= t;
		p *= t;
	}
	xatop(k);
	if (k > 1e18)
		cout << -1 << endl;
	else
		cout << p << endl;

	return 0;
}
