
// Problem : Derevo s izmeneniem otrezka
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=47&id_problem=608
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

class SegmentTree {
	vll st, a;
	int n;

	void build(int v, int tl, int tr) {
		if (tl == tr) {
			st[v] = a[tl];
		} else {
			int tm = (tl + tr) / 2;
			build(v * 2, tl, tm);
			build(v * 2 + 1, tm + 1, tr);
			st[v] = 0;
		}
	}

	void update(int v, int tl, int tr, int l, int r, ll add) {
		if (l > r) return;
		if (l == tl && r == tr) {
			st[v] += add;
		} else {
			int tm = (tl + tr) / 2;
			update(v * 2, tl, tm, l, min(r, tm), add);
			update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
		}
	}

	ll get(int v, int tl, int tr, int pos) {
		if (tl == tr) return st[v];
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			return st[v] + get(v * 2, tl, tm, pos);
		else
			return st[v] + get(v * 2 + 1, tm + 1, tr, pos);
	}

   public:
	SegmentTree(vll _a) {
		a.pb(0);
		a.insert(a.end()--, ALL(_a));
		n = _a.size();
		st.assign(4 * n, 0);

		build(1, 1, n);
	}
	ll get(int i) { return get(1, 1, n, i); };
	void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
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

	char c;
	int l, r, q;
	while (m--) {
		cin >> c;
		if (c == 'g') {
			cin >> r;
			cout << at.get(r) << " ";
		} else {
			cin >> l >> r >> q;
			at.update(l, r, q);
		}
	}

	return 0;
}
