
// Problem : Алгоритм Дейкстры
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=topic&id_course=2&id_section=32&id_topic=54
// Memory Limit : 16 MB
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
const ll LINF = 1000000000000000000LL;

int main() {
	TEZ;

	int n, s, f;
	cin >> n >> s >> f;

	vector<vi> g(n + 1, vi(n + 1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
			if (g[i][j] == -1) g[i][j] = INF;
		}

	vi m(n + 1, INF), p(n + 1, 0);
	priority_queue<ii> pq;

	m[s] = 0;
	pq.push({0, s});

	int b, c;
	while (!pq.empty()) {
		tie(b, c) = pq.top();
		pq.pop();

		if (p[c]) continue;

		p[c] = 1;

		for (int i = 1; i <= n; i++) {
			b = g[c][i];

			if (m[i] > m[c] + b) {
				m[i] = m[c] + b;
				pq.push({-m[i], i});
			}
		}
	}

	cout << (m[f] == INF ? -1 : m[f]) << endl;

	return 0;
}
