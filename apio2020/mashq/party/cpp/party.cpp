#include "party.h"

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
		cout << string(recur_depth, '\t') << __func__ << ":" << __LINE__ \
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

int findUnusualGuest(int N, int M, int Q) {
	vi c;
	for (int i = 0; i < N + M; i++)
		c.pb(i);

	vi v = ask(c);
	if (c != v) {
		if (v.empty()) return 0;
		set<int> s;
		for (int i : v)
			s.insert(i);
		for (int i = 0; i < N + M; i++)
			if (!s.count(i)) return i;
	}

	if (N < M) {
		int l = 0, r = N - 1;
		for (int i = 1; i <= 5 && l < r; i++) {
			int m = (l + r) / 2;

			vi on;
			for (int j = l; j <= m; j++)
				on.pb(j);

			vi onv = ask(on);
			if (on.size() < onv.size())
				r = m;
			else
				l = m + 1;
		}
		return l;
	} else {
		int l = N, r = M - 1;
		for (int i = 1; i <= 5 && l < r; i++) {
			int m = (l + r) / 2;

			vi on;
			for (int j = l; j <= m; j++)
				on.pb(j);

			vi onv = ask(on);
			if (on.size() < onv.size())
				r = m;
			else
				l = m + 1;
		}
		return l;
	}
}
