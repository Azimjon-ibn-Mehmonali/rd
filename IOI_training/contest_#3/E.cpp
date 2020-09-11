
// Problem: E. Reading Books (easy version)
// Contest: Codeforces - Contest #3
// URL: https://codeforces.com/group/5mF1N2M956/contest/288691/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const ll LINF = 1000000000000000000LL;

int main() {
	TEZ;

	int n, k;
	cin >> n >> k;

	vll s11, s01, s10;

	int t, a, b;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> b;

		if (a + b == 2)
			s11.pb(t);
		else if (a == 1)
			s10.pb(t);
		else
			s01.pb(t);
	}

	SORT(s11);
	SORT(s01);
	SORT(s10);

	vll p11, p01, p10;

	p11.pb(0);
	for (ll i : s11)
		p11.pb(p11.back() + i);

	p01.pb(0);
	for (ll i : s01)
		p01.pb(p01.back() + i);

	p10.pb(0);
	for (ll i : s10)
		p10.pb(p10.back() + i);

	ll jv = LINF;
	for (int i = 0; i < min(k + 1, (int)p11.size()); i++) {
		if (((int)p01.size() > k - i) && ((int)p10.size() > k - i)) {
			jv = min(jv, p11[i] + p10[k - i] + p01[k - i]);
		}
	}

	cout << (jv == LINF ? -1 : jv) << endl;

	return 0;
}