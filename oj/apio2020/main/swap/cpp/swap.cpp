#include "swap.h"

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
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

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const ll LINF = 1e18;

vector<vii> g;
vi u, v, w, mas, sm;
int n, m;

void init(int N, int M,
          std::vector<int> U, std::vector<int> V, std::vector<int> W) {

//	g.assign(N, vii());
	mas.assign(N, 2e9);
	u = U;
	v = V;
	w = W;
	n = N;
	m = M;

	for (int i = 0; i < M; i++) {
		mas[V[i]] = W[i];
//		g[U[i]].pb({V[i], W[i]});
//		g[V[i]].pb({U[i], W[i]});
	}
	sm = mas;
	SORT(sm);
}

int getMinimumFuelCapacity(int x, int y) {
	if (n <= 3)
		return -1;

	if (x > y)
		swap(x, y);
	
	int e, r, t;

	if (x == 0) {
		set<int> s;
		s.insert(sm[0]);
		s.insert(sm[1]);
		s.insert(sm[2]);
		r = sm[y];

		s.erase(r);

		t = *s.begin();
		r = *next(s.begin());
	} else {
		e = w[x];
		r = w[y];
		set<int> s;
		s.insert(sm[0]);
		s.insert(sm[1]);
		s.insert(sm[2]);

		s.erase(e);
		s.erase(r);

		t = *s.begin();
	}

	return max({e, r, t});
}
