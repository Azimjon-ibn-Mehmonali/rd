
// Problem: C. Cyclic Permutations
// Contest: Codeforces - Codeforces Round #663 (Div. 2)
// URL: https://codeforces.com/contest/1391/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
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

//=========================================================
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
//=========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

int f(int n) {
	int jv = 1;
	for (int i = 1; i <= n; i++)
		jv = (jv * i) % mod;

	return jv;
}

int id(int a, int b) {
	int jv = 1;
	while (b) {
		if (b & 1) jv = (jv * a) % mod;
		b /= 2;
		a = sqr(a) % mod;
	}
	return jv;
}

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

		if (size[a] < size[b]) swap(a, b);

		size[a] += size[b];
		link[b] = a;
	}
};

void g() {
	int jv = 0;
	vi a({1, 2, 3, 4, 5, 6});
	int n = 6;
	do {
		UnionFind uf(n);
		for (int i = 0; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[j] > a[i]) {
					if (uf.find(j) == uf.find(i)) {
						// xtp(a);
						jv++;
						i = n;
						break;
					}
					uf.unite(i, j);
					break;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (a[j] > a[i]) {
					if (uf.find(j) == uf.find(i)) {
						// xtp(a);
						jv++;
						i = n;
						break;
					}
					uf.unite(i, j);
					break;
				}
			}
		}
	} while (next_permutation(ALL(a)));
	xtp(jv);
}

signed main() {
	TEZ;

	// g();

	int n;
	cin >> n;

	int t = f(n) - id(2, n - 1);
	t %= mod;
	t += mod;
	t %= mod;

	cout << t << endl;

	// xtp(id(2, 4));
	// xtp(id(3, 3));

	// vi a({1, 2, 3});
	// next_permutation(ALL(a));

	// xtp(a);

	return 0;
}
