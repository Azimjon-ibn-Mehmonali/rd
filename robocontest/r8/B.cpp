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

	int x, y;
	cin >> x >> y;

	int s = 100;
	int jv = 0;
	while (s > 0 || jv == 0) {
		jv++;
		xatop(s);
		s = min(100, s + y);
		s -= x;

		if (s <= 0) {
			break;
		}

		s = min(100, s + y);
		s = min(100, s + y);
	}

	cout << jv << endl;

	return 0;
}
