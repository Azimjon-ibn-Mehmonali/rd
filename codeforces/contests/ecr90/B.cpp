
// Problem : B. 01 Game
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : http://codeforces.com/contest/1373/problem/B
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

int f(int x, string s) { return (x >= 0 && x < s.size()); }
string fun(string s) {
	int t = 0, y = 1;
	while (s.size() && y) {
		int x = s.find("01"), z = s.find("10");
		if (f(x, s))
			s.erase(x, 2), y = 1, t++;
		else if (f(z, s))
			s.erase(z, 2), y = 1, t++;
		else
			y = 0;
	}
	if (t & 1)
		return "DA";
	else
		return "NET";
}

string funm(string s) {
	if (s.size() == 1) {
		return "NET";
	}

	int jv = 0;
	int bir, nol;
	bir = nol = 0;

	for (char c : s)
		if (c == '1')
			bir++;
		else
			nol++;
	jv = min(bir, nol);
	if (jv & 1)
		return "DA";
	else
		return "NET";
}

string func(string s) {
	ll a, c, t, b, i, j, l = 0, r = 0, k = 0, kk = 0, z = 0, ans = 0, sum = 0,
						 y = 0, x, s1, sk, n, m;
	vector<ll> v;

	n = s.size();

	while (1) {
		string ss;

		for (i = 0; i < s.size(); i++) {
			if (s[i] == '0' && s[i + 1] == '1') {
				s[i] = '#';
				s[i + 1] = '#';
				k++;
				z = 1;
				break;
			} else if (s[i] == '1' && s[i + 1] == '0') {
				s[i] = '#';
				s[i + 1] = '#';
				k++;
				z = 1;
				break;
			}
		}

		for (i = 0; i < s.size(); i++) {
			if (s[i] != '#') {
				ss += s[i];
			}
		}

		s = ss;

		if (z == 1) {
			z = 0;
			continue;
		} else {
			break;
		}
	}

	if (k % 2 == 1) {
		return "DA";
	} else {
		return "NET";
	}
}

int main() {
	TEZ;

	string s;
	cin >> s;

	cout << funm(s) << " " << func(s) << endl;

	return 0;
}
