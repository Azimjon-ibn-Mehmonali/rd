
// Problem: A. XXXXX
// Contest: Codeforces - Contest #4
// URL: https://codeforces.com/group/5mF1N2M956/contest/289033/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

void f() {
	int n, x;
	cin >> n >> x;

	vi a(n);
	bool m1 = 1;
	ll s = 0;
	for (int& i : a) {
		cin >> i;
		m1 &= i % x == 0;
		s += i;
	}

	if (m1) {
		cout << -1 << endl;
		return;
	}

	if (s % x) {
		cout << n << endl;
		return;
	}

	int l = 0;
	int r = n - 1;

	for (int i = 0; i < n; i++)
		if (a[i] % x) {
			l = i;
			break;
		}

	for (int i = n - 1; i >= 0; i--)
		if (a[i] % x) {
			r = i;
			break;
		}

	cout << n - min(l + 1, n - r) << endl;
}

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
