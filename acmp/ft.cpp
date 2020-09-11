
// Problem : Derevo Fenvika
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=46&id_problem=288
// Memory Limit : 16 MB
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

vll ft;

void qosh(int i, ll x) {
	while (i <= ft.size()) {
		ft[i] += x;
		i += i & -i;
	}
}

ll yig(int i) {
	ll jv = 0;
	while (i > 0) {
		jv += ft[i];
		i -= i & -i;
	}

	return jv;
}

int main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	ft.assign(n + 1, 0);

	string s;
	int a, b;
	while (m--) {
		cin >> s >> a >> b;

		if (s == "add") {
			qosh(a, b);
		} else {
			cout << yig(b) - yig(a - 1) << endl;
		}
	}

	return 0;
}