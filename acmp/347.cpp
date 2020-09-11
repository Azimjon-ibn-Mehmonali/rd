// Problem : Покер
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=137&id_problem=858
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

	vi a(5);
	map<int, int> m;
	for (int& i : a)
		cin >> i, m[i]++;

	if (m.begin()->S == 5) return cout << "Impossible", 0;

	if (m.begin()->S == 4 || next(m.begin())->S == 4)
		return cout << "Four of a Kind", 0;

	if ((m.begin()->S == 3 && next(m.begin())->S == 2)
		|| (m.begin()->S == 2 && next(m.begin())->S == 3))
		return cout << "Full House", 0;

	SORT(a);
	bool kk = 1;
	for (int i = 1; i < 5; i++)
		kk &= a[i] == a[i - 1] + 1;

	if (kk) return cout << "Straight", 0;

	if (m.begin()->S == 3 || next(m.begin())->S == 3
		|| (next(m.begin(), 2) != m.end() && next(m.begin(), 2)->S == 3))
		return cout << "Three of a Kind", 0;

	int bx = 0;
	for (auto [f, s] : m)
		bx += s == 2;

	if (bx == 2) return cout << "Two Pairs", 0;
	if (bx == 1) return cout << "One Pair", 0;

	cout << "Nothing";

	return 0;
}
