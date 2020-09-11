
// Problem: B2. Village (Maximum)
// Contest: Codeforces - Baltic Olympiad in Informatics 2020, Day 2 (IOI,
// Unofficial Mirror Contest, Unrated) URL:
// https://codeforces.com/contest/1387/problem/B2 Memory Limit: 256 MB Time
// Limit: 500 ms Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

	int n;
	cin >> n;

	vector<vi> g(n + 1, vi()), gg;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	gg = g;
	vi ish(n + 1, 0);

	bool to = n & 1;

	ll jv = 0;
	int ic = n - to;
	for (int i = 1; i <= n && ic; i++) {
		if (ish[i]) continue;

		vi mas(n + 1, 0);
		queue<int> q;

		mas[i] = 1;
		q.push(i);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : g[u]) {
				if (mas[v] == 0 && !g[v].empty()) {
					mas[v] = mas[u] + 1;
					q.push(v);
				}
			}
		}
		// xtp(mas);
		auto it = max_element(ALL(mas));
		int di = it - mas.begin();
		int nr = *it;
		xtp(di);
		xtp(i);
		ish[i] = di;
		ish[di] = i;
		jv += 2 * (nr - 1);

		ic -= 2;

		g[i].clear();
		g[di].clear();
	}

	if (to) {
		int t;
		for (int i = 1; i <= n; i++) {
			if (ish[i] == 0) {
				t = i;
				break;
			}
		}

		vi mas(n + 1, 0);
		queue<int> q;

		mas[t] = 1;
		q.push(t);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : gg[u]) {
				if (mas[v] == 0 && !gg[v].empty()) {
					mas[v] = mas[u] + 1;
					q.push(v);
				}
			}
		}
		auto it = max_element(ALL(mas));
		int di = it - mas.begin();
		int nr = *it;
		// ish[i] = di;
		// ish[di] = i;

		// jv += 2;
		// xtp(t);
		// xtp(gg[t]);
		ish[t] = di;
		int ff = ish[di];
		ish[di] = t;
		ish[ff] = t;
	}

	cout << jv << endl;
	for (int i = 1; i <= n; i++) {
		cout << ish[i] << " ";
	}

	return 0;
}
