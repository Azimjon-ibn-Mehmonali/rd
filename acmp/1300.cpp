
// Problem: Змейка
// Contest: ACMP
// URL:
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=139&id_problem=870
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

int a[110][110];

int main() {
	TEZ;

	int n;
	cin >> n;

	bool p = 0;
	int i, j, s;
	i = j = 1;
	s = 1;

	while (s <= n * n) {
		a[i][j] = s++;

		if (p) {
			if (j == 1 && i < n) {
				i++;
				p = !p;
			} else if (i == n) {
				j++;
				p = !p;
			} else {
				i++;
				j--;
			}
		} else {
			if (i == 1 && j < n) {
				j++;
				p = !p;
			} else if (j == n) {
				i++;
				p = !p;
			} else {
				i--;
				j++;
			}
		}
	}
	xtp(i);
	xtp(j);
	xtp(p);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}

	return 0;
}
