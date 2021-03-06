
// Problem: День рождения - 2
// Contest: ACMP
// URL:
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=142&id_problem=893
// Memory Limit: 16 MB
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

int oy[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	TEZ;

	int tk, to;
	cin >> tk >> to;

	int hk, ho, hy;
	cin >> hk >> ho >> hy;

	int jv = 0;
	while (hk != tk || ho != to) {
		// xtp(hk);
		// xtp(ho);
		// xtp(hy);

		if ((hy % 400 == 0) || (hy % 100 != 0 && hy % 4 == 0))
			oy[2] = 29;
		else
			oy[2] = 28;

		hk++;
		jv++;

		if (hk > oy[ho]) {
			ho++;
			hk = 1;
		}

		if (ho > 12) {
			hy++;
			ho = 1;
		}
	}

	cout << jv << endl;

	return 0;
}
