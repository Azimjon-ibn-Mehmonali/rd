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
const ll mod = 1000000007ll;
const int INF = 1000000000;

#define int long long

int f(int n) {
	int jv = 1;
	for (int i = 1; i <= n; i++)
		jv = (jv * i) % mod;

	return jv;
}

int gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;

		return a;
	}

	int x1, y1;
	int jv = gcd(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return jv;
}

signed main() {
	int n, m;
	cin >> m >> n;

	int jv = f(m + n - 2);

	int x, y;
	gcd((f(n - 1) * (f(m - 1)) % mod), mod, x, y);

	x %= mod;
	x += mod;
	x %= mod;

	jv = (jv * x) % mod;

	cout << jv << endl;

	return 0;
}
