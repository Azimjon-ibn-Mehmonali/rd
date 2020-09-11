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
#define mp make_pair
#define pb push_back
#define sc scanf
#define pr printf
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define lsb(x) ((x) & (-x))

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

int n;
int ft[1000005] = {0};

vi almashtir(vi a) {
	vi t = a;
	SORT(t);

	for (int i = 0; i < a.size(); i++) {
		a[i] = lower_bound(ALL(t), a[i]) - t.begin() + 1;
	}

	return a;
}

void qosh(int i, int k) {
	while (i <= n) {
		ft[i] += k;
		i += lsb(i);
	}
}

ll yig(int i) {
	ll jv = 0;
	while (i > 0) {
		jv += ft[i];
		i -= lsb(i);
	}

	return jv;
}

void bajar() {
	cin >> n;

	vi a(n);
	for (int &i : a)
		cin >> i;

	vi b = almashtir(a);

	memset(ft, 0, sizeof(ft));
	// for (int i = 0; i < n; i++)
	// cout << b[i] << " ";

	ll jv = 0;
	for (int i = n - 1; i >= 0; i--) {
		jv += yig(b[i] - 1);
		qosh(b[i], 1);
	}

	cout << jv << endl;
}

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		bajar();

	return 0;
}