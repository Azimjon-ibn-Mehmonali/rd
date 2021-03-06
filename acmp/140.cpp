
// Problem : Алгоритм Форда-Беллмана
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=topic&id_course=2&id_section=32&id_topic=53
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
const ll LINF = 1000000000000000000LL;

int main() {
	TEZ;

	ll n;
	cin >> n;

	vector<tuple<ll, ll, ll>> el;

	ll a, b, c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c != 100000) el.pb({i, j, c});
		}

	vll mas(n + 1, LINF);
	mas[1] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (auto& e : el) {
			tie(a, b, c) = e;

			mas[b] = min(mas[b], mas[a] + c);
		}
	}

	for (auto& e : el) {
		tie(a, b, c) = e;

		if (mas[a] != LINF) {
			if (mas[b] > mas[a] + c) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}
