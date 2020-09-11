
// Problem : Выражение
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=137&id_problem=854
// Memory Limit : 16 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

#define int long long

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

ll n, s;
ll a[30];

bool top;
string jv, tt;

void f(ll i, ll hs) {
	if (top) return;

	if (i == n) {
		if (hs == s) {
			top = true;
			jv = tt;
		}

		return;
	}

	/*nt.pb('+');
	f(i + 1, hs + a[i]);

	nt.pop_back();
	nt.pb('-');
	f(i + 1, hs - a[i]);*/

	tt[i - 1] = '+';
	f(i + 1, hs + a[i]);

	tt[i - 1] = '-';
	f(i + 1, hs - a[i]);
}

signed main() {
	TEZ;

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	top = 0;
	tt.assign(30, '+');
	f(1, a[0]);

	if (!top) {
		cout << "No solution" << endl;
		return 0;
	}
	// xtp(jv);
	cout << a[0];
	for (int i = 1; i < n; i++)
		cout << jv[i - 1] << a[i];
	cout << "=" << s << endl;

	return 0;
}
