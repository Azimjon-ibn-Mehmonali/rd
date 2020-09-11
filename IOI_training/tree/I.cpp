
// Problem: I. Valid BFS?
// Contest: Codeforces - Tree
// URL: https://codeforces.com/group/5mF1N2M956/contest/290453/problem/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

	int n;
	cin >> n;

	vector<vi> g(n + 1, vi());
	vi bf;
	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		g[a].pb(b);
		g[b].pb(a);
	}

	queue<int> q;
	vi jv, c(n), l(n + 1, -1);
	int e[200005];
	memset(e, -1, sizeof(e));

	for (int i = 0; i < n; i++) {
		cin >> c[i];

		e[c[i]] = i;
	}

	auto cmp = [&](int x, int y) { return e[x] < e[y]; };

	for (int i = 1; i <= n; i++)
		sort(ALL(g[i]), cmp);

	l[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int u = q.front();
		jv.pb(u);
		q.pop();

		for (int v : g[u]) {
			if (l[v] != -1) continue;
			l[v] = l[u] + 1;
			q.push(v);
		}
	}

	if (jv == c)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}
