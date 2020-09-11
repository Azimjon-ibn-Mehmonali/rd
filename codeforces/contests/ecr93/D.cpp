
// Problem: D. Colored Rectangles
// Contest: Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1398/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

signed main() {
	TEZ;

	int R, G, B;
	cin >> R >> G >> B;

	vi r, g, b;

	int t;
	for (int i = 0; i < R; i++) {
		cin >> t;
		r.pb(t);
	}

	for (int i = 0; i < G; i++) {
		cin >> t;
		g.pb(t);
	}

	for (int i = 0; i < B; i++) {
		cin >> t;
		b.pb(t);
	}

	int jj = 0;

	{
		vi rr(r), gg(g), bb(b);
		int jv = 0;

		rSORT(rr), rSORT(gg), rSORT(bb);
		while (1) {
			int rg = -1;
			if (!rr.empty() && !gg.empty()) rg = rr[0] * gg[0];
			int rb = -1;
			if (!rr.empty() && !bb.empty()) rb = rr[0] * bb[0];
			int gb = -1;
			if (!gg.empty() && !bb.empty()) gb = gg[0] * bb[0];

			int ka = max({rg, rb, gb});
			if (ka == -1) break;
			if (ka == rg) {
				rr.erase(rr.begin());
				gg.erase(gg.begin());
				jv += rg;
			} else if (ka == rb) {
				rr.erase(rr.begin());
				bb.erase(bb.begin());
				jv += rb;
			} else {
				bb.erase(bb.begin());
				gg.erase(gg.begin());
				jv += gb;
			}
		}
		jj = max(jv, jj);
	}

	{
		vi rr(r), gg(g), bb(b);
		int jv = 0;

		rSORT(rr), rSORT(gg), rSORT(bb);
		while (1) {
			int rg = -1;
			if (!rr.empty() && !gg.empty()) rg = rr[0] * gg[0];
			int rb = -1;
			if (!rr.empty() && !bb.empty()) rb = rr[0] * bb[0];
			int gb = -1;
			if (!gg.empty() && !bb.empty()) gb = gg[0] * bb[0];

			int ka = max({rg, rb, gb});
			if (ka == -1) break;
			if (ka == rg) {
				rr.erase(rr.begin());
				gg.erase(gg.begin());
				jv += rg;
			} else if (ka == gb) {
				bb.erase(bb.begin());
				gg.erase(gg.begin());
				jv += gb;
			} else if (ka == rb) {
				rr.erase(rr.begin());
				bb.erase(bb.begin());
				jv += rb;
			}
		}
		jj = max(jv, jj);
	}

	{
		vi rr(r), gg(g), bb(b);
		int jv = 0;

		rSORT(rr), rSORT(gg), rSORT(bb);
		while (1) {
			int rg = -1;
			if (!rr.empty() && !gg.empty()) rg = rr[0] * gg[0];
			int rb = -1;
			if (!rr.empty() && !bb.empty()) rb = rr[0] * bb[0];
			int gb = -1;
			if (!gg.empty() && !bb.empty()) gb = gg[0] * bb[0];

			int ka = max({rg, rb, gb});
			if (ka == -1) break;
			if (ka == rb) {
				rr.erase(rr.begin());
				bb.erase(bb.begin());
				jv += rb;
			} else if (ka == rg) {
				rr.erase(rr.begin());
				gg.erase(gg.begin());
				jv += rg;
			} else {
				bb.erase(bb.begin());
				gg.erase(gg.begin());
				jv += gb;
			}
		}
		jj = max(jv, jj);
	}

	{
		vi rr(r), gg(g), bb(b);
		int jv = 0;

		rSORT(rr), rSORT(gg), rSORT(bb);
		while (1) {
			int rg = -1;
			if (!rr.empty() && !gg.empty()) rg = rr[0] * gg[0];
			int rb = -1;
			if (!rr.empty() && !bb.empty()) rb = rr[0] * bb[0];
			int gb = -1;
			if (!gg.empty() && !bb.empty()) gb = gg[0] * bb[0];

			int ka = max({rg, rb, gb});
			if (ka == -1) break;
			if (ka == rb) {
				rr.erase(rr.begin());
				bb.erase(bb.begin());
				jv += rb;
			} else if (ka == gb) {
				bb.erase(bb.begin());
				gg.erase(gg.begin());
				jv += gb;
			} else if (ka == rg) {
				rr.erase(rr.begin());
				gg.erase(gg.begin());
				jv += rg;
			}
		}
		jj = max(jv, jj);
	}

	{
		vi rr(r), gg(g), bb(b);
		int jv = 0;

		rSORT(rr), rSORT(gg), rSORT(bb);
		while (1) {
			int rg = -1;
			if (!rr.empty() && !gg.empty()) rg = rr[0] * gg[0];
			int rb = -1;
			if (!rr.empty() && !bb.empty()) rb = rr[0] * bb[0];
			int gb = -1;
			if (!gg.empty() && !bb.empty()) gb = gg[0] * bb[0];

			int ka = max({rg, rb, gb});
			if (ka == -1) break;
			if (ka == gb) {
				bb.erase(bb.begin());
				gg.erase(gg.begin());
				jv += gb;
			} else if (ka == rg) {
				rr.erase(rr.begin());
				gg.erase(gg.begin());
				jv += rg;
			} else if (ka == rb) {
				rr.erase(rr.begin());
				bb.erase(bb.begin());
				jv += rb;
			}
		}
		jj = max(jv, jj);
	}

	{
		vi rr(r), gg(g), bb(b);
		int jv = 0;

		rSORT(rr), rSORT(gg), rSORT(bb);
		while (1) {
			int rg = -1;
			if (!rr.empty() && !gg.empty()) rg = rr[0] * gg[0];
			int rb = -1;
			if (!rr.empty() && !bb.empty()) rb = rr[0] * bb[0];
			int gb = -1;
			if (!gg.empty() && !bb.empty()) gb = gg[0] * bb[0];

			int ka = max({rg, rb, gb});
			if (ka == -1) break;
			if (ka == gb) {
				bb.erase(bb.begin());
				gg.erase(gg.begin());
				jv += gb;
			}
			if (ka == rg) {
				rr.erase(rr.begin());
				gg.erase(gg.begin());
				jv += rg;
			} else if (ka == rb) {
				rr.erase(rr.begin());
				bb.erase(bb.begin());
				jv += rb;
			}
		}
		jj = max(jv, jj);
	}

	cout << jj << endl;

	return 0;
}
