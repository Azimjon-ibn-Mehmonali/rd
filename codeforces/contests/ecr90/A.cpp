
// Problem : A. Donut Shops
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : http://codeforces.com/contest/1373/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define rALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define rSORT(a) sort(rALL(a))
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

ll a, b, c;

ll bir(ll x) { return x * a; }

ll ikki(ll x) { return c * (x / b + bool(x % b)); }

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--) {
		cin >> a >> b >> c;

		bool x1, x2;
		x1 = x2 = 1;

		ll j1, j2;
		j1 = j2 = -1;

		{
			ll t = b + 1;
			x1 = bir(t) < ikki(t);
			x2 = bir(t) > ikki(t);

			if (x1) j1 = t;
			if (x2) j2 = t;
		}
		{
			ll t = b;
			x1 = bir(t) < ikki(t);
			x2 = bir(t) > ikki(t);

			if (x1) j1 = t;
			if (x2) j2 = t;
		}
		{
			ll t = b - 1;
			x1 = bir(t) < ikki(t);
			x2 = bir(t) > ikki(t);

			if (x1) j1 = t;
			if (x2) j2 = t;
		}
		{
			ll t = 1;
			x1 = bir(t) < ikki(t);
			x2 = bir(t) > ikki(t);

			if (x1) j1 = t;
			if (x2) j2 = t;
		}

		cout << j1 << " " << j2 << endl;
	}

	return 0;
}