
// Problem: H. Maze
// Contest: Codeforces - Contest #4
// URL: https://codeforces.com/group/5mF1N2M956/contest/289033/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

int a[550][550];

int main() {
	TEZ;

	int n, m, k;
	cin >> n >> m >> k;

	int x, y;
	int yg = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			a[i][j] = s[j] == '.';
			if (a[i][j]) {
				yg++;
				x = i;
				y = j;
			}
		}
	}
	// xtp(yg);
	k = yg - k;
	// xtp(k);

	queue<ii> q;

	q.push({x, y});
	a[x][y] = 2;
	k--;

	auto mum = [&](int w, int e) {
		return k > 0 && 0 <= w && 0 <= e && w < n && e < m && a[w][e] == 1;
	};

	while (!q.empty() && k > 0) {
		tie(x, y) = q.front();
		q.pop();

		if (mum(x + 1, y)) {
			q.push({x + 1, y});
			a[x + 1][y] = 2;
			k--;
		}

		if (mum(x, y - 1)) {
			q.push({x, y - 1});
			a[x][y - 1] = 2;
			k--;
		}

		if (mum(x - 1, y)) {
			q.push({x - 1, y});
			a[x - 1][y] = 2;
			k--;
		}

		if (mum(x, y + 1)) {
			q.push({x, y + 1});
			a[x][y + 1] = 2;
			k--;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)
				cout << '#';
			else if (a[i][j] == 1)
				cout << 'X';
			else
				cout << '.';
		}
		cout << endl;
	}

	return 0;
}
