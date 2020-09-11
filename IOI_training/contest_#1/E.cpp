
// Problem : E. Secret Passage
// Contest : Codeforces - Contest #1
// URL : https://codeforces.com/group/5mF1N2M956/contest/284955/problem/E
// Memory Limit : 512 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define pb push_back
#define endl "\n"

#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
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
	os << "\n[";
	for (auto& x : v) {
		os << x << ", ";
	}
	return os << "]\n'";
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

#define int long long

int m1[510][510] = {0};
int m2[510][510] = {0};

int n, m, k;
bool mum(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

signed main() {
	TEZ;

	cin >> n >> m >> k;

	vector<vector<int>> a(n, vector<int>(m)), b;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			if (s[j] == '.')
				a[i][j] = true;
			else
				a[i][j] = false;
		}
	}

	b = a;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		b[x][y] = true;
	}

	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	queue<ii> q1;
	q1.push({0, 0});
	m1[0][0] = 1;

	while (!q1.empty()) {
		ii r = q1.front();
		int x = r.F;
		int y = r.S;
		q1.pop();

		for (int i = 0; i < 4; i++) {
			int x_, y_;
			x_ = x + dx[i];
			y_ = y + dy[i];

			if (mum(x_, y_) && a[x_][y_] == 1 && m1[x_][y_] == 0) {
				m1[x_][y_] = m1[x][y] + 1;
				q1.push({x_, y_});
			}
		}
	}

	queue<ii> q2;
	q2.push({0, 0});
	m2[0][0] = 1;
	while (!q2.empty()) {
		ii r = q2.front();
		int x = r.F;
		int y = r.S;
		q2.pop();

		for (int i = 0; i < 4; i++) {
			int x_, y_;
			x_ = x + dx[i];
			y_ = y + dy[i];

			if (mum(x_, y_) && b[x_][y_] == 1 && m2[x_][y_] == 0) {
				m2[x_][y_] = m2[x][y] + 1;
				q2.push({x_, y_});
			}
		}
	}

	xtp(m1[n - 1][m - 1]);
	xtp(m2[n - 1][m - 1]);
	xtp(a);
	xtp(b);

	if (m2[n - 1][m - 1] < m1[n - 1][m - 1] - 5
		|| (m2[n - 1][m - 1] && !m1[n - 1][m - 1]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
