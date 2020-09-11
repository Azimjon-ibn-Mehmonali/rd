// Muallif: Azimjon Mehmonali o'g'li

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
#define pb push_back
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

#define int long long

ll f(ll x) {
	if (x < 4) {
		return 1;
	}

	return f(x - 1) + 2 * f(x - 2) + 3 * f(x - 3);
}

void multiply(int F[3][3], int M[3][3]);
void power(int F[3][3], int n);

int fib(int n) {
	int F[3][3] = {{1, 2, 3}, {0, 0, 1}, {0, 1, 0}};
	if (n == 0) return 0;
	power(F, n - 3);

	return F[0][0];	 // + F[0][1] + F[0][2];
}

void power(int F[3][3], int n) {
	if (n == 0 || n == 1) return;
	int M[3][3] = {{1, 2, 3}, {0, 0, 1}, {0, 1, 0}};

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0) multiply(F, M);
}

void multiply(int F[3][3], int M[3][3]) {
	int c[3][3];
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			ll sum = 0;
			for (int k = 0; k <= 2; k++) {
				sum = sum + F[i][k] * M[k][j];
			}
			c[i][j] = sum;
		}
	}

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			F[i][j] = c[i][j];
		}
	}
}

signed main() {
	int n = 9;

	// cout << fib(9);

	for (int i = 1; i < 10; i++)
		cout << fib(i) << " ";
	cout << endl;
	for (int i = 1; i < 10; i++)
		cout << f(i) << " ";

	return 0;
}