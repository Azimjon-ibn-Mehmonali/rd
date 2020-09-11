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

#define int long long

int g(string s) {
	int j = 0;
	for (char c : s)
		j += c - '0';

	return j;
}

set<int> tub = {2, 3, 5, 7, 11, 13};

int h(int r) {
	int u = 1, r_ = r;
	r--;
	while (r--)
		u *= 10;
	for (int i = u;; i++) {
		string s = to_string(i);
		// cout << g(s) << endl;
		// xtp(tub.count(g(s.substr(0, 5))));
		for (int k = 0; k <= r_ - 5; k++) {
			if (!tub.count(g(s.substr(k, 5)))) {
				s = "t";
				break;
			}
		}
		if (s == "t") continue;

		for (int k = 0; k <= r_ - 4; k++) {
			if (!tub.count(g(s.substr(k, 4)))) {
				s = "t";
				break;
			}
		}
		if (s == "t") continue;
		for (int k = 0; k <= r_ - 3; k++) {
			if (!tub.count(g(s.substr(k, 3)))) {
				s = "t";
				break;
			}
		}

		if (s != "t") {
			cout << s << endl;
			return 0;
		}
	}
}

signed main() {
	TEZ;

	int n;
	cin >> n;
	// h(5);
	// h(6);
	// h(7);
	// h(10);
	int a[] = {0, 1, 10, 101, 1011, 10110, 101101};

	if (n < 7)
		cout << a[n];
	else {
		cout << 10;
		n -= 2;

		int ik = 1;
		while (n) {
			if (ik) {
				cout << 2;
			} else {
				cout << 3;
			}
			n--;
			ik = 1 - ik;

			if (n) cout << 0, n--;
			if (n) cout << 0, n--;
		}
	}

	return 0;
}
