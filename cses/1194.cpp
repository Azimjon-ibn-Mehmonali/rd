
// Problem : Monsters
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1194
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

const int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
signed main() {
	TEZ;

	int n, m;
	cin >> n >> m;

	vector<vi> isSafe(n, vi(m)), vis(n, vi(m, 0));
	vii monsters;
	ii character;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j) {
			isSafe[i][j] = (str[j] != '#');
			if (str[j] == 'M') {
				monsters.pb({i, j});
				isSafe[i][j] = false;
			} else if (str[j] == 'A')
				character = {i, j};
		}
	}

	queue<pair<ii, bool>> q;

	for (auto& x : monsters)
		q.push({x, false});
	q.push({character, true});
	bool found = false;
	ii foundPos;
	vector<vii> lst(n, vii(m, {-1, -1}));
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		if (u.S) {
			if (!isSafe[u.F.F][u.F.S]) continue;
			vis[u.F.F][u.F.S] = 1;
			if (u.F.F == 0 || u.F.F == n - 1 || u.F.S == 0 || u.F.S == m - 1) {
				found = true;
				foundPos = {u.F.F, u.F.S};
				break;
			}
		} else
			isSafe[u.F.F][u.F.S] = 0;

		for (int i = 0; i < 4; ++i) {
			int newR = u.F.F + dr[i], newC = u.F.S + dc[i];
			if (newR >= 0 && newR < n && newC >= 0 && newC < m
				&& isSafe[newR][newC]) {
				if (!u.S || (u.S && !vis[newR][newC])) {
					q.push({{newR, newC}, u.S});
					if (u.S) lst[newR][newC] = {u.F.F, u.F.S};
				}
			}
		}
		if (found) break;
	}

	if (!found)
		cout << "NO\n";
	else {
		cout << "YES\n";
		ii prev = {-1, -1};
		string res;
		for (int i = foundPos.F, j = foundPos.S; i != -1 || j != -1;
			 tie(i, j) = lst[i][j]) {
			if (prev.F == -1 && prev.S == -1) {
				prev = {i, j};
				continue;
			}
			if (i == prev.F && j + 1 == prev.S)
				res += 'R';
			else if (i == prev.F && j - 1 == prev.S)
				res += 'L';
			else if (i + 1 == prev.F && j == prev.S)
				res += 'D';
			else if (i - 1 == prev.F && j == prev.S)
				res += 'U';
			prev = {i, j};
		}
		reverse(res.begin(), res.end());
		cout << res.size() << '\n' << res << '\n';
	}
	return 0;
}