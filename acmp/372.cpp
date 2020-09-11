#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

bool g(string s) {
	stack<char> u;
	map<char, char> y{
		{')', '('},
		{'}', '{'},
		{']', '['},
	};

	for (char c : s) {
		if (y[c] && (u.empty() || u.top() != y[c])) {
			return 0;
		}

		if (y[c])
			u.pop();
		else
			u.push(c);
	}

	return u.empty();
}

char oc[] = {'(', '['};
char yo[] = {')', ']'};

int n;

unordered_set<string> t;

string s;

void f() {
	if ((int)s.size() == n) {
		// t.pb(s);
		if (t.emplace(s).S) {
			cout << s << endl;
		}
		return;
	}

	for (int i = 0; i < (int)s.size(); i++) {
		s = s.substr(0, i) + "()" + s.substr(i);
		f();

		s[i] = '[';
		s[i + 1] = ']';
		f();

		s = s.substr(0, i) + s.substr(i + 2);
	}
}

int main() {
	TEZ;

	cin >> n;

	s = "()";
	f();

	s = "[]";
	f();

	// for (auto& w : t)
	// cout << w << endl;

	return 0;
}
