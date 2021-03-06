
// Problem: Покраска лабиринта
// Contest: ACMP
// URL:
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=144&id_problem=903
// Memory Limit: 16 MB
// Time Limit: 1000 ms
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
	return os << "]\n";
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

	int n, m;
	cin >> n >> m;

	vector<vi> g(n, vi(m)), v(n, vi(m, 0));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			g[i][j] = s[j] == '#';
		}
	}

	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	auto mum = [&](ii l) {
		return 0 <= l.F && 0 <= l.S && l.F < n && l.S < m && g[l.F][l.S]
			   && !v[l.F][l.S];
	};

	int jv = 0;
	queue<ii> q;

	for (int k = 0; k < n; k++)
		for (int j = 0; j < m; j++) {
			if (v[k][j] || !g[k][j]) continue;
			jv++;

			q.push({k, j});
			v[k][j] = 1;

			while (!q.empty()) {
				ii u = q.front();
				q.pop();

				ii h;
				for (int i = 0; i < 4; i++) {
					h = {u.F + dx[i], u.S + dy[i]};

					if (mum(h)) {
						v[h.F][h.S] = 1;
						q.push(h);
					}
				}
			}
		}

	cout << jv << endl;

	return 0;
}
