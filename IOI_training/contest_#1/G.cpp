
// Problem : G. Pick Your Team
// Contest : Codeforces - Contest #1
// URL : https://codeforces.com/group/5mF1N2M956/contest/284955/problem/G
// Memory Limit : 64 MB
// Time Limit : 2000 ms
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
#define SORT(a) sort(ALL(a))
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

int main() {
	TEZ;

	int n;
	cin >> n;

	vi a(n), p(n);
	for (int& i : a)
		cin >> i;
	for (int& i : p)
		cin >> i;

	int yi1, yi2;
	yi1 = yi2 = 0;

	int oe = 0;
	if (n & 1) {
		oe = p.back();
		p.pop_back();
	}
	for (int i = 0; i < n - 1; i += 2) {
		yi1 += max(a[p[i] - 1], a[p[i + 1] - 1]);
		yi2 += min(a[p[i] - 1], a[p[i + 1] - 1]);
	}
	yi1 += oe;
	xtp(yi1);
	xtp(yi2);

	SORT(a);
	int jj1 = 0, jj2 = 0;
	for (int i = 0; i < n / 2; i++)
		jj1 += a[i];
	for (int i = n / 2; i < n; i++)
		jj2 += a[i];

	cout << max(yi1 - yi2, jj1 - jj2) << endl;

	return 0;
}
