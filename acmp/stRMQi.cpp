
// Problem : RMQ s izmeneniem elementa
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=47&id_problem=605
// Memory Limit : 32 MB
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

class SegmentTree {
   private:
	vll st, a;
	int n;

	void build(int v, int l, int r) {
		if (l == r) {
			st[v] = l;
		} else {
			int m = (l + r) / 2;

			build(v << 1, l, m);
			build((v << 1) + 1, m + 1, r);

			int b1, b2;
			b1 = st[v << 1];
			b2 = st[(v << 1) + 1];

			st[v] = a[b1] < a[b2] ? b2 : b1;
		}
	}

	void update(int v, int l, int r, int i, ll val) {
		if (l == r) {
			a[l] = val;
			st[v] = l;
		} else {
			int m = (l + r) >> 1;

			if (i <= m)
				update(v << 1, l, m, i, val);
			else
				update((v << 1) + 1, m + 1, r, i, val);

			int b1, b2;
			b1 = st[v << 1];
			b2 = st[(v << 1) + 1];

			st[v] = a[b1] < a[b2] ? b2 : b1;
		}
	}

	ll get(int v, int l, int r, int b, int o) {
		if (o < l || r < b) return -LINF;

		if (b <= l && r <= o) return st[v];

		int m = (l + r) / 2;

		auto b1 = get(v << 1, l, m, b, o);
		auto b2 = get((v << 1) + 1, m + 1, r, b, o);

		if (b1 == -LINF) return b2;
		if (b2 == -LINF) return b1;

		return (a[b1] < a[b2] ? b2 : b1);
	}

   public:
	SegmentTree(vll& _a) {
		a = _a;
		a.insert(a.begin(), -LINF);
		n = _a.size();
		st.assign(4 * n, -LINF);
		build(1, 1, n);
	}
	void update(int i, ll val) { update(1, 1, n, i, val); }
	pair<ll, int> get(int l, int r) {
		int x = get(1, 1, n, l, r);
		return {x, a[x]};
	};
};

int main() {
	TEZ;

	int n;
	cin >> n;

	vll a(n);
	for (ll& i : a)
		cin >> i;

	SegmentTree qd(a);

	int m;
	cin >> m;

	ll l, r;
	while (m--) {
		cin >> l >> r;

		auto x = qd.get(l, r);
		cout << x.S << " " << x.F << endl;
	}

	return 0;
}
