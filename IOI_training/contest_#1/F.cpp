
// Problem : F. Wifi Trees
// Contest : Codeforces - Contest #1
// URL : https://codeforces.com/group/5mF1N2M956/contest/284955/problem/F
// Memory Limit : 64 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

//===========================================================

int recur_depth = 0;
#ifdef DEBUG
#define xtp(x)                                                           \
	{                                                                    \
		++recur_depth;                                                   \
		auto x_ = x;                                                     \
		--recur_depth;                                                   \
		cerr << string(recur_depth, '\t') << __func__ << ":" << __LINE__ \
			 << "\t" << #x << " = " << x_ << endl;                       \
	}
#else
#define xtp(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(
	Ostream& os, const Cont& v) {
	os << "[";
	for (auto& x : v) {
		os << x << ", ";
	}
	return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
	return os << "{" << p.first << ", " << p.second << "}";
}

//===========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const ll mod = 1000000007LL;
const int INF = 1000000000;

#define int long long

int n, m, x;
int f(int ya) { return min(ya, m) * (n - ya) * x; }

void bajar() {
	cin >> n >> m >> x;

	int l = 0, r = n, ya, t1, t2, t3;
	int mh = -1, wto;
	while (l < r) {
		ya = (l + r) / 2;
		t1 = f(ya - 1);
		t2 = f(ya);
		t3 = f(ya + 1);

		if (t1 <= t2 && t2 >= t3)
			break;
		else if (t1 < t3) {
			l = ya + 1;
		} else
			r = ya;
	}

	cout << ya << " " << t2 << endl;
}

signed main() {
	TEZ;

	int t;
	cin >> t;

	srand(time(NULL));
	while (t--)
		bajar();

	return 0;
}
