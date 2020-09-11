// Problem : Counting Rooms
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1192
// Memory Limit : 512 MB
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

int g[1005][1005];
int n, m;

bool mum(int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; }

bool mumm(int i, int j) { return mum(i, j) && g[i][j] == INF; }

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	TEZ;

	cin >> n >> m;

	ii bo, ox;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			if (s[j] == '#')
				g[i][j] = -1;
			else
				g[i][j] = INF;
			if (s[j] == 'A') bo = {i, j};
			if (s[j] == 'B') ox = {i, j};
		}
	}

	queue<ii> q;
	q.push(bo);
	g[bo.F][bo.S] = 0;
	g[ox.F][ox.S] = INF;

	bool top = false;
	while (!q.empty()) {
		ii h = q.front();
		q.pop();
		// if (!mum(h.F, h.S)) continue;
		for (int i = 0; i < 4; i++) {
			int x = h.F + dx[i];
			int y = h.S + dy[i];

			if (mumm(x, y)) {
				g[x][y] = g[h.F][h.S] + 1;
				q.push({x, y});
			}
		}

		if (h == ox) {
			top = true;
			break;
		}
	}

	// for (int i = 0; i < n; i++) {
	// for (int j = 0; j < m; j++) {
	// cout << (char)g[i][j];
	// }
	// cout << endl;
	// }

	// top = true;
	if (top) {
		cout << "YES" << endl;
		cout << g[ox.F][ox.S] << endl;
		int x, y;
		string jv;
		while (g[ox.F][ox.S]) {
			// cout << g[ox.F][ox.S] << endl << flush;
			x = ox.F + dx[0];
			y = ox.S + dy[0];
			if (mum(x, y) && g[x][y] == g[ox.F][ox.S] - 1) {
				jv.pb('L');
				ox.F = x;
				ox.S = y;
				continue;
			}

			x = ox.F + dx[1];
			y = ox.S + dy[1];
			if (mum(x, y) && g[x][y] == g[ox.F][ox.S] - 1) {
				jv.pb('U');
				ox.F = x;
				ox.S = y;
				continue;
			}

			x = ox.F + dx[2];
			y = ox.S + dy[2];
			if (mum(x, y) && g[x][y] == g[ox.F][ox.S] - 1) {
				jv.pb('R');
				ox.F = x;
				ox.S = y;
				continue;
			}

			x = ox.F + dx[3];
			y = ox.S + dy[3];
			if (mum(x, y) && g[x][y] == g[ox.F][ox.S] - 1) {
				jv.pb('D');
				ox.F = x;
				ox.S = y;
				continue;
			}
		}
		REV(jv);
		cout << jv << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}