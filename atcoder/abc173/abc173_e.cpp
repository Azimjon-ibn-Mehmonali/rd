
// Problem : E - Multiplication 4
// Contest : AtCoder - AtCoder Beginner Contest 173
// URL : https://atcoder.jp/contests/abc173/tasks/abc173_e
// Memory Limit : 1024 MB
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

int main() {
	TEZ;

	ll n, k;
	cin >> n >> k;

	vll p, m;
	bool nl = false;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		if (t < 0) {
			m.pb(t);
		} else if (t == 0) {
			nl = true;
		} else {
			p.pb(t);
		}
	}

	ll nt = 1;
	// xtp(m);
	// xtp(p);
	int ms = m.size(), ps = p.size();

	if (p.empty() && nl) {
		cout << 0 << endl;
		return 0;
	}

	if (ps == 0) {
		rSORT(m);
		for (int i = 0; i < k; i++) {
			nt = (nt * (m[i] % mod)) % mod;
		}

		cout << (nt + mod) % mod << endl;
		return 0;
	}

	if (ms == 0) {
		rSORT(m);
		for (int i = 0; i < k; i++) {
			nt = (nt * (p[i] % mod)) % mod;
		}

		cout << nt << endl;
		return 0;
	}
	rSORT(p);
	SORT(m);
	p.pb(1);
	m.pb(1);
	p.pb(1);
	m.pb(1);

	int i;
	for (i = 0; ms > 1 && ps > 1 && k > 1; i += 2, k -= 2, ms -= 2, ps -= 2) {
		ll g = max(m[i] * m[i + 1], p[i] * p[i + 1]);

		nt = (nt * (g % mod)) % mod;
	}

	for (; ms > 1 && k > 1; k -= 2, i += 2, ms -= 2)
		nt = (nt * ((m[i] * m[i + 1]) % mod)) % mod;
	for (; ps > 1 && k > 1; k -= 2, i += 2, ps -= 2)
		nt = (nt * ((p[i] * p[i + 1]) % mod)) % mod;
	xtp(k);
	if (k) {
		nt = (nt * (p[i] % mod)) % mod;
	}

	cout << nt << endl;

	return 0;
}
