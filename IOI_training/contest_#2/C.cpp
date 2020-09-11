
// Problem : C. Dreamoon and WiFi
// Contest : Codeforces - Contest #2 (Bitmasks)
// URL : https://codeforces.com/group/5mF1N2M956/contest/285505/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

string a, b;
vi t;
int n;

void f(int hq = 0, int jr = 0) {
	if (jr == n) {
		t.pb(hq);
		return;
	}
	xtp(jr);
	if (b[jr] == '-' || b[jr] == '?') f(hq - 1, jr + 1);
	if (b[jr] == '+' || b[jr] == '?') f(hq + 1, jr + 1);
}

int main() {
	TEZ;
	cin >> a >> b;

	n = b.size();

	int jv = 0;
	for (char c : a)
		if (c == '+')
			jv++;
		else
			jv--;

	f(0, 0);
	xtp(t);

	ld ms = 0;
	for (int i : t)
		ms += (i == jv);

	cout << setprecision(12) << (ld)ms / t.size() << endl;

	return 0;
}
