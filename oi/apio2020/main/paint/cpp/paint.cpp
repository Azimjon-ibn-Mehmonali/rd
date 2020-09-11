#include "paint.h"

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

int minimumInstructions(
    int n, int m, int k, std::vector<int> c,
    std::vector<int> a, std::vector<std::vector<int>> b) {
	
	for (auto &i : b)
		SORT(i);

	auto is_valid = [&](int x, int y) {
		int xx, yy;
		for (int l = 0; l < m; l++) {
			xx = (x + l) % m;
			yy = y + l;
			if (!binary_search(ALL(b[xx]), c[yy]))
				return 0;
		}
		return 1;
	};

	int jv = 0;
	for (int x = 0; x < m; x++) {
		jv += is_valid(x, 0);
	}

	if (jv == 0)
		return -1;

	jv = 1;

	int ox = m - 1;
	for (;ox < n - 1;) {
		int w = 0;
		int baj = 0;
		int y = min(ox + 1, n - m);
		for (int j = 0; j < min(m, n - ox - 1); j++, y-- ) {
			w = 0;
			for (int x = 0; x < m; x++) {
				w += is_valid(x, y);
			}
			if (w) {
				baj = 1;
				ox = y + m - 1;
				jv++;
				break;
			}
		}
		if (baj == 0)
			return -1;
	}
	
	return jv;
}
