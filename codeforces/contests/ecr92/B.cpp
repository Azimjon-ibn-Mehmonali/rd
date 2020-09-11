
// Problem: B. Array Walk
// Contest: Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1389/problem/B
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

void f() {
	int n, k, z;
	cin >> n >> k >> z;

	vll a(++k);
	for (ll& i : a)
		cin >> i;

	vll t(n - k);
	for (ll& i : t)
		cin >> i;
	xtp(t);

	vll b;
	b.pb(0ll);
	for (ll i : a)
		b.pb(b.back() + i);
	xtp(b);
	priority_queue<ll> pq;
	pq.push(b.back());

	for (int i = 1; i <= z; i++) {
		for (int j = 0; j < k - 2 * i; j++) {
			ll s = a[j] + a[j + 1];
			xtp(s);
			xtp(i);
			xtp(b[k - 2 * i]);
			pq.push(b[k - 2 * i] + i * s);
		}
	}

	cout << pq.top() << endl;
}

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
