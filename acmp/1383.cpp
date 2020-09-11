
// Problem : Дейкстра за O(M log N)
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=32&id_topic=54&id_problem=1038
// Memory Limit : 32 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

#define int long long

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

signed main() {
	TEZ;

	int n, m, s;
	cin >> n >> m >> s;

	vector<vii> g(n, vii());

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}

	vi mas(n, 2009000999LL), pr(n, 0);
	priority_queue<ii> q;

	mas[s] = 0;
	q.push({0, s});

	while (!q.empty()) {
		a = q.top().S;
		q.pop();

		if (pr[a]) continue;
		pr[a] = 1;

		for (ii o : g[a]) {
			tie(b, c) = o;

			if (mas[b] > mas[a] + c) {
				mas[b] = mas[a] + c;
				q.push({-mas[b], b});
			}
		}
	}

	for (int i : mas)
		cout << i << " ";

	return 0;
}
