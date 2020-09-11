
// Problem: A. Colors
// Contest: Codeforces - Baltic Olympiad in Informatics 2020, Day 1 (IOI,
// Unofficial Mirror Contest, Unrated) URL:
// https://codeforces.com/contest/1386/problem/A Memory Limit: 256 MB Time
// Limit: 1000 ms Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

ll n;

void g() {
	bool b, i;
	cout << "? " << 1 << endl;
	cin >> b;

	cout << "? " << 2 << endl;
	cin >> i;

	if (i) {
		cout << "= " << 1 << endl;
	} else {
		cout << "= " << 2 << endl;
	}
}

void f() {
	if (n == 2) {
		g();
		return;
	}

	cout << "? " << 1 << endl;

	ll t;
	cin >> t;

	ll hs = 1, del = 1;
	ll l, r;
	l = 2;
	r = n;
	ll jv = n;
	bool rr = 1;
	bool ox;
	while (l <= r) {
		jv--;
		cout << "? " << (rr ? r : l) << endl;
		cin >> t;
		if (rr)
			r--;
		else
			l++;
		rr = !rr;
		ox = t;
		if (!t) {
			if (jv == n - 1)
				cout << "= " << n << endl;
			else
				cout << "= " << jv + 1 << endl;
			return;
		}
	}
	cout << "= " << 1 << endl;
}

void y() {
	if (n == 2) {
		g();
		return;
	}

	cout << "? " << 1 << endl;

	ll t;
	cin >> t;

	ll hs = 1, del = 1;
	ll l, r;
	l = 2;
	r = n;
	ll jv = n;
	bool rr = 1;
	bool ox;
	while (l <= r) {
		jv -= 4;
		cout << "? " << (rr ? r : l) << endl;
		cin >> t;
		if (rr)
			r -= 4;
		else
			l += 4;
		rr = !rr;
		ox = t;
		if (!t) {
			return;
		}
	}
	cout << "= " << 1 << endl;
}

void j() {
	cin >> n;

	if (n <= 64) {
		f();
		return;
	}

	cout << "? " << 1 << endl;

	bool t;
	cin >> t;

	ll l = 0;
	ll delta = n;
	ll yo = 1;
	ll jv = LINF;

	ll ch, on;
	ch = 1;
	on = n + 1;
	for (int i = 0; i < 63; i++) {
		l += delta * yo;

		if (ch < l && l < on) {
			///
		} else {
			cout << "= " << jv << endl;
			return;
		}

		cout << "? " << l << endl;
		cin >> t;

		if (llabs(ch - l) < llabs(on - l)) {
			ch = l;
		} else {
			on = l;
		}

		if (!t && i == 0) {
			cout << "= " << jv << endl;
			return;
		}

		if (t) {
			jv = min(jv, delta);
			delta = (ch + on) / 2 - ch;
			yo = -1;
		} else {
			jv = min(jv, delta);
			delta = (ch + on) / 2 - ch;
			yo = 1;
		}
	}

	cout << "= " << jv << endl;
}

int main() {
	TEZ;

	int t;
	cin >> t;

	while (t--)
		j();

	return 0;
}
