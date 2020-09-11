#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define INF 1000000021
#define MOD 1000000007
#define pb push_back
#define sqr(a) (a) * (a)
#define M(a, b) make_pair(a, b)
#define T(a, b, c) make_pair(a, make_pair(b, c))
#define F first
#define S second
#define all(x) (x.begin(), x.end())
#define deb(x) cerr << #x << " = " << x << '\n'
#define N 222222

using namespace std;
// using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;

const ld pi = 2 * acos(0.0);
template <class T>
bool umin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
bool umax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T, class TT>
bool pal(T a, TT n) {
	int k = 0;
	for (int i = 0; i <= n / 2; i++) {
		if (a[i] != a[n - i - 1]) {
			k = 1;
			break;
		}
	}
	return k ? 0 : 1;
}

// int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

vi v[N];
ll c[N];
vll g;
ll n;
void dfs(int u, int e) {
	c[u] = 1;
	for (auto it : v[u]) {
		if (it == e) continue;
		dfs(it, u);
		ll o = c[it];
		ll oo = n - o;
		g.pb(o * oo);
		c[u] += c[it];
	}
}
ll f[N];
void solve() {
	g.clear();
	cin >> n;
	for (int i = 1; i <= n; i++)
		v[i].clear(), c[i] = 0;
	for (int i = 2; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> f[i];
	sort(f + 1, f + m + 1);
	reverse(f + 1, f + min((int)n - 1, m) + 1);
	for (int i = n; i <= m; i++)
		f[1] = (f[1] * f[i]) % MOD;
	for (int i = m + 1; i <= n; i++)
		f[i] = 1;
	dfs(1, 0);
	ll ans = 0;
	sort all(g);
	reverse all(g);
	for (int i = 1; i <= n - 1; i++) {
		ll o = (g[i - 1] * f[i]) % MOD;
		ans = (ans + o) % MOD;
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();

	getchar();
	getchar();
	return 0;
	// ios::sync_with_stdio(false);
	// cin.tie(0);
}