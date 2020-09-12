#include "fun.h"

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

vi f(int n) {
	vi l, r;
	int sa = 1;
	r.pb(0);
	for (int i = 2; sa < n; i *= 2) {
		for (int j = 0; j < i && sa < n; j++) {
			if (j < i / 2)
				l.pb(sa++);
			else
				r.pb(sa++);
		}
	}
	vi a;
	bool c = 1;
	while (l.size() || r.size()) {
		if (c) {
			if (a.empty()) {
				c = !c;
				continue;
			}
			a.pb(l.back());
			l.pop_back();
		} else {
			if (r.size())
				a.pb(r.back()), r.pop_back();
			else
				a.pb(l.back()), l.pop_back();

		}
		c = !c;
	}

	return a;
}

std::vector<int> createFunTour(int N, int Q) {
  if (N > 500) {
  	return f(N);
  }
  int ka, ki;
  ka = -1;
  for (int i = 1; i < N; i++) {
	int t = hoursRequired(0, i);
	if (ka < t) {
		ka = t;
		ki = i;
	}
  }

  vi a;
  set<int> s;

  a.pb(ki);
  s.emplace(ki);
  
  for (int r = 0; r < N - 1; r++) {
	  ka = -1;
	  for (int i = 0; i < N; i++) {
		if (s.count(i)) continue;
		int t = hoursRequired(a.back(), i);
		if (ka < t) {
			ka = t;
			ki = i;
		}
	  }
	  a.pb(ki);
	  s.insert(ki);
  }

  return a;
}
