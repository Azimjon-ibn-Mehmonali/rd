
// Problem: E. Replace To Make Regular Bracket Sequence
// Contest: Codeforces - Contest #5
// URL: https://codeforces.com/group/5mF1N2M956/contest/289850/problem/E
// Memory Limit: 256 MB
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

int main() {
	TEZ;

	string s;
	cin >> s;

	map<char, char> oc{
		{'<', '>'},
		{'[', ']'},
		{'(', ')'},
		{'{', '}'},
	};

	map<char, char> yo{
		{'>', '<'},
		{']', '['},
		{')', '('},
		{'}', '{'},
	};

	stack<char> st;
	ll jv = 0;
	for (char c : s) {
		if (yo[c]) {
			if (st.empty()) {
				cout << "Impossible\n";
				return 0;
			}

			char e = st.top();
			st.pop();

			if (yo[e]) {
				cout << "Impossible\n";
				return 0;
			}
			xtp(oc[e]);
			if (oc[e] != c) jv++;
		} else {
			st.push(c);
		}
	}

	if (!st.empty()) {
		cout << "Impossible\n";
		return 0;
	}

	cout << jv << endl;

	return 0;
}
