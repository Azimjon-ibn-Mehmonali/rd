
// Problem : Dvumernyy Fenvik
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=20&id_topic=46&id_problem=602
// Memory Limit : 16 MB
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

vector<vll> ft;
int n, m;

void qosh(int x, int y, ll s) {
	for (int i = x; i < n; i = i | (i + 1))
		for (int j = y; j < m; j = j | (j + 1))
			ft[i][j] += s;
}

ll yig(int x, int y) {
	ll jv = 0;

	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			jv += ft[i][j];

	return jv;
}

int main() {
	TEZ;

	int q;
	cin >> n >> q;
	m = ++n;

	ft.assign(n + 1, vll(m + 1, 0));

	string s;
	while (q--) {
		cin >> s;

		if (s == "add") {
			int x, y;
			cin >> x >> y;
			qosh(x, y, 1);
		} else {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--, y1--;
			cout << yig(x1, y1) + yig(x2, y2) - yig(x2, y1) - yig(x1, y2)
				 << endl;
		}
	}

	return 0;
}
