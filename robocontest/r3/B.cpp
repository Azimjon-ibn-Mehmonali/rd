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

#define sci1(n) sc("%d", &n);
#define sci2(n, m) sc("%d%d", &n, &m);
#define scl1(n) sc("%I64d", &n);
#define scl2(n, m) sc("%I64d%I64d", &n, &m);

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

int f(int n) {
	int q = ceil(n / 3.);

	ll jv = 3ll * q * n;

	jv -= 3ll * (2 + (q - 1) * 3ll) * q / 2ll;

	if (n % 3 == 1) jv++;

	return jv;
}

int main() {
	set<int> ucs;
	ucs.insert(0);

	for (int i = 1; i <= 10000; i++)
		ucs.insert(f(i));

	int t;
	sci1(t);

	while (t--) {
		int n;
		sci1(n);

		if (ucs.count(n))
			cout << 1;
		else
			cout << 0;
	}

	return 0;
}
