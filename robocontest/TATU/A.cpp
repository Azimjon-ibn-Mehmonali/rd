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

ll ikda(ll a, ll b, ll m) {
	ll jv = 1;
	while (b) {
		if (b & 1) jv = (jv * a) % m;
		a = (a * a) % m;
		b /= 2;
	}

	return jv;
}

ll kea(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll jv = kea(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return jv;
}

ll modbt(ll a, ll m) {
	ll x, y;

	kea(a, m, x, y);

	return (x % m + m) % m;
}

int main() {
	ll a, b, c, m;

	ll jv;

	jv = ikda(a, b, m) * modbt(c, m) % m;

	cout << jv << endl;

	return 0;
}
