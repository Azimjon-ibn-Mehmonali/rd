
// Problem : Получи дерево
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=topic&id_course=2&id_section=32&id_topic=55
// Memory Limit : 16 MB
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

class UnionFind {
   private:
	vi link, size;

   public:
	UnionFind(int n) {
		link.assign(n, 0);
		size.assign(n, 1);

		for (int i = 0; i < n; i++)
			link[i] = i;
	}

	int find(int x) {
		if (x == link[x]) return x;

		return link[x] = find(link[x]);
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) return;

		if (size[a] < size[b]) swap(a, b);

		size[a] += size[b];
		link[b] = a;
	}
};

int main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> el;
	UnionFind uf(n * m + 1);
	vii en(n * m + 1);

	int t, sa = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> t;

			if (i < n) el.pb({1, sa, sa + m});
			if (j < m) el.pb({2, sa, sa + 1});

			if ((t & 1) && i < n) uf.unite(sa, sa + m);
			if ((t == 2 || t == 3) && j < m) uf.unite(sa, sa + 1);

			en[sa++] = {i, j};
		}
	}

	SORT(el);

	ll jv = 0;
	vector<tuple<int, int, int>> jj;

	for (auto [c, u, v] : el) {
		if (uf.find(u) != uf.find(v)) {
			jv += c;
			jj.pb({u, v, c});
			uf.unite(u, v);
		}
	}

	cout << jj.size() << " " << jv << endl;
	for (auto [u, v, c] : jj)
		cout << en[u].F << " " << en[u].S << " " << c << endl;

	return 0;
}
