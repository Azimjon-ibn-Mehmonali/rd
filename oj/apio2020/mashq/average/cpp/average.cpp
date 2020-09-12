#include "average.h"

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

bool ki;
vll a;
vll p;

void init() {
	ki = 1;
	p.pb(0);
}

void addMonth(int K) {
	if (!a.empty()) ki &= a.back() >= K;
	a.pb(K);
	p.pb(p.back() + K);
}

double maximumAverage(int L, int R) {
	double jv = -1;

	ll yi, so;
	yi = so = 0;

	if (ki) {
		yi = p.back() - p[L];
		so = a.size() - L;

		return 1. * yi / so;
	}

	for (int i = a.size() - 1; i >= L; i--) {
		yi += a[i];
		so++;
		if (i <= R) jv = max(jv, 1. * yi / so);
	}

	return jv;
}
