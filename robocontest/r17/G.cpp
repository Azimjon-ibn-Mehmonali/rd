// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

#define int long long

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

int pw(int a, int b) {
	int jv = 1;
	while (b--)
		jv *= a;
	return jv;
}

int m(int a, int k) {
	TEZ;
	int _k = k;

	map<int, int> aa, kk;

	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			int s = 0;
			while (a % i == 0)
				s++, a /= i;

			aa[i] = s;
		}
	}

	if (a > 1) aa[a] = 1;

	for (int i = 2; i * i <= k; i++) {
		if (k % i == 0) {
			int s = 0;
			while (k % i == 0)
				s++, k /= i;

			kk[i] = s;
		}
	}

	if (k > 1) kk[k] = 1;
	int jv = 1;
	for (auto [f, s] : kk) {
		if (aa[f] != s) jv *= pw(f, s);
	}

	return min(jv, _k);
}

signed main() {
	int a, k;
	cin >> a >> k;

	assert(a * m(a, k) / __gcd(a, m(a, k)) == k);

	cout << m(a, k) << endl;

	return 0;
}
