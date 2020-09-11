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

int main() {
	TEZ;

	int s, t;
	cin >> s >> t;

	int a, b;
	cin >> a >> b;

	int m, n;
	cin >> m >> n;

	int tt, jo, jp;
	jo = jp = 0;
	for (int i = 0; i < m; i++) {
		cin >> tt;

		if (s <= a + tt && tt + a <= t) jo++;
	}

	for (int i = 0; i < n; i++) {
		cin >> tt;

		if (s <= b + tt && tt + b <= t) jp++;
	}

	cout << jo << endl << jp << endl;

	return 0;
}
