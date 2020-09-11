
// Problem : B. Sequential Nim
// Contest : Codeforces - Codeforces Round #658 (Div. 2)
// URL : https://codeforces.com/contest/1382/problem/B
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
const ll LINF = 1000000000000000000LL;

void f() {
	int n;
	cin >> n;

	vi a(n);
	vi b(n + 1, 0);
	for (int& i : a)
		cin >> i;

	a.back() = 1;

	int ob = -1;
	for (int i = n - 1; i >= 0; i--) {
		b[i] += b[i + 1] + (a[i] != 1);
		if (a[i] != 1) ob = max(ob, i);
	}

	n--;
	int jv = 0;
	bool toq = n & 1;
	// xtp(ob);

	for (int i = 1; i <= n; i++) {
		if (i == n) break;
		if (toq) {
			if (a[i - 1] == 1) {
				jv = 1 - jv;
				continue;
			}

			if (i % 2 == 0) {
				// i++;
			} else {
				jv = 1 - jv;
			}
		} else {
			if (a[i] == 1) {
				jv = 1 - jv;
				continue;
			}

			if (i % 2 != 0) {
				xtp(i);
				// i++;
			} else {
				jv = 1 - jv;
			}
		}
	}

	cout << (jv ? "Second" : "First") << endl;
}

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		f();

	return 0;
}
