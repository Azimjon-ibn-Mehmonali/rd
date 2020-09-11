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

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

#define int long long

const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

void multiply(int F[2][2], int M[2][2]);

void power(int F[2][2], int n);

int fib(int n) {
	int F[2][2] = {{1, 1}, {1, 0}};
	if (n == 0) return 0;
	power(F, n - 1);
	return F[0][0];
}

void power(int F[2][2], int n) {
	if (n == 0 || n == 1) return;
	int M[2][2] = {{1, 1}, {1, 0}};

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0) multiply(F, M);
}

void multiply(int F[2][2], int M[2][2]) {
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	x %= mod;
	y %= mod;
	z %= mod;
	w %= mod;

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

signed main() {
	TEZ;

	ll i, j;
	cin >> i >> j;

	cout << fib(__gcd(i, j)) << endl;

	return 0;
}
