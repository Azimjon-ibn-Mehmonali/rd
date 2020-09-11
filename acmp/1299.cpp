
// Problem: Длинная сумма
// Contest: ACMP
// URL:
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=138&id_problem=863
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

void input(int* x) {
	string s;
	cin >> s;

	x[0] = s.size();
	for (int i = 1; i <= x[0]; i++) {
		x[i] = s[x[0] - i] - '0';
	}
}

void output(int* x) {
	for (int i = x[0]; i >= 1; i--)
		cout << x[i];
}

void add(int* x, int* y, int* z) {
	int dilda = 0;
	z[0] = max(x[0], y[0]);
	for (int i = 1; i <= z[0]; i++) {
		int t = x[i] + y[i] + dilda;
		z[i] = t % 10;

		dilda = t / 10;
	}

	if (dilda) {
		z[++z[0]] = dilda;
	}
}

int main() {
	TEZ;

	int x[30010] = {0}, y[30010] = {0}, z[30010];

	input(x);
	input(y);

	add(x, y, z);

	output(z);

	return 0;
}
