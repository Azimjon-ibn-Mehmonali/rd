
// Problem : D. a-Good String
// Contest : Codeforces - Codeforces Round #656 (Div. 3)
// URL : https://codeforces.com/contest/1385/problem/D
// Memory Limit : 256 MB
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

int g(string s, char c) {
	xtp(s);
	if (s.size() == 1) return s[0] != c;

	int n = s.size() / 2;

	int jv, j1, j2;
	jv = j1 = j2 = 0;
	for (int i = 0; i < n; i++)
		j1 += s[i] != c;
	for (int i = n; i < 2 * n; i++)
		j2 += s[i] != c;

	j1 += g(s.substr(n, n), c + 1);
	j2 += g(s.substr(0, n), c + 1);

	return min(j1, j2);
}

void f() {
	int n;
	string s;

	cin >> n >> s;

	cout << g(s, 'a') << endl;
}

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
