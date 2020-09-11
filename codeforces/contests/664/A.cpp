
// Problem: A. Boboniu Likes to Color Balls
// Contest: Codeforces - Codeforces Round #664 (Div. 2)
// URL: https://codeforces.com/contest/1395/problem/A
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

signed main() {
	TEZ;

	int t;
	cin >> t;

	while (t--) {
		int r, g, b, w;
		cin >> r >> g >> b >> w;

		int jv = 0;
		jv += r & 1;
		jv += g & 1;
		jv += b & 1;
		jv += w & 1;

		if (jv <= 1) {
			cout << "Yes" << endl;
			continue;
		}

		if (0 < r && 0 < g && 0 < b) {
			r--, g--, b--, w += 3;
			jv = 0;
			jv += r & 1;
			jv += g & 1;
			jv += b & 1;
			jv += w & 1;

			if (jv <= 1) {
				cout << "Yes" << endl;
				continue;
			}
		}

		if (0 < r && 0 < g && 0 < b) {
			r--, g--, b--, w += 3;
			jv = 0;
			jv += r & 1;
			jv += g & 1;
			jv += b & 1;
			jv += w & 1;

			if (jv <= 1) {
				cout << "Yes" << endl;
				continue;
			}
		}

		cout << "No" << endl;
	}

	return 0;
}
