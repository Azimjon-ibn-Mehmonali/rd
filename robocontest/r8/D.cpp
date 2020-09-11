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
const ll mod = 1000000007;
const int INF = 1000000000;

ll ikda(ll a, ll b, ll m) {
	ll jv = 1;
	while (b) {
		if (b & 1) jv = (jv * a) % m;

		a = sqr(a % m) % m;
		b /= 2;
	}

	return jv;
}

int main() {
	TEZ;

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll ek = -1;
	ll bol;
	for (int i = 1; i * i <= d; i++) {
		if (d % i == 0) {
			bol = i;
			if ((ikda(a, b, bol) - c) % bol == 0) ek = max(ek, bol);

			bol = d / i;
			if ((ikda(a, b, bol) - c) % bol == 0) ek = max(ek, bol);
		}
	}

	cout << ek << endl;

	return 0;
}
