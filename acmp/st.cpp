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

class SegmentTree {
   private:
	vll st, a;
	int n;

	void build(int v, int l, int r) {
		if (l == r) {
			st[v] = a[l];
			return;
		}

		int m = (l + r) / 2;
		build(v << 1, l, m);
		build((v << 1) + 1, m + 1, r);

		st[v] = gcd(st[v << 1], st[(v << 1) + 1]);
	}

	ll get(int v, int l, int r, int b, int o) {
		if (o < l || r < b) return -1;

		if (b <= l && r <= o) return st[v];

		int m = (l + r) / 2;
		ll j1 = get(v << 1, l, m, b, o);
		ll j2 = get((v << 1) + 1, m + 1, r, b, o);

		if (j1 == -1) return j2;
		if (j2 == -1) return j1;

		return gcd(j1, j2);
	}

   public:
	SegmentTree(vll _a) {
		a.pb(0);
		a.insert(a.end()--, ALL(_a));
		n = a.size();
		st.assign(4 * n, 0);
		build(1, 1, n);
	}

	ll get(int l, int r) { return get(1, 1, n, l, r); }
};

int main() {
	TEZ;

	int n;
	cin >> n;

	vll a(n);
	for (ll& i : a)
		cin >> i;

	SegmentTree at(a);

	int m;
	cin >> m;

	int l, r;
	while (m--) {
		cin >> l >> r;

		cout << at.get(l, r) << " ";
	}

	return 0;
}
