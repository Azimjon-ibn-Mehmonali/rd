// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
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

//=========================================================
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
//=========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

signed main() {
	TEZ;

	int n, p;
	cin >> n >> p;

	vector<vi> a(n + 1, vi(n + 1, '`'));

	vector<string> u(n + 1), l(n + 1), r(n + 1), d(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> u[i];

	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];

	for (int i = 1; i <= n; i++)
		cin >> d[i];

	for (int i = 1; i <= n; i++) {
		string s = u[i];
		if (s.size() > 1) {
			int t = stoi(s.substr(0, s.size() - 1));
			char c = s.back();

			for (int k = 1; k < t; k++)
				a[k][i] = '-';
			a[t][i] = c;
		}

		if (s[0] == '0') {
			for (int k = 1; k <= n; k++)
				a[k][i] = '-';
		}
	}

	for (int i = 1; i <= n; i++) {
		string s = r[i];
		if (s.size() > 1) {
			int t = stoi(s.substr(0, s.size() - 1));
			char c = s.back();

			for (int k = 1; k < t; k++)
				a[i][n - k + 1] = '-';

			a[i][n - t + 1] = c;
		}

		if (s[0] == '0') {
			for (int k = 1; k <= n; k++)
				a[i][k] = '-';
		}
	}

	for (int i = 1; i <= n; i++) {
		string s = l[i];
		if (s.size() > 1) {
			int t = stoi(s.substr(0, s.size() - 1));
			char c = s.back();

			for (int k = 1; k < t; k++)
				a[i][k] = '-';

			a[i][t] = c;
		}

		if (s[0] == '0') {
			for (int k = 1; k <= n; k++)
				a[i][k] = '-';
		}
	}

	for (int i = 1; i <= n; i++) {
		string s = d[i];
		if (s.size() > 1) {
			int t = stoi(s.substr(0, s.size() - 1));
			char c = s.back();

			for (int k = 1; k < t; k++)
				a[n - k + 1][i] = '-';

			a[n - t + 1][i] = c;
		}

		if (s[0] == '0') {
			for (int k = 1; k <= n; k++)
				a[k][i] = '-';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '`') a[i][j] = 'M';
			cout << (char)a[i][j];
		}
		cout << endl;
	}

	/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//
			}
		}
	*/
	return 0;
}
