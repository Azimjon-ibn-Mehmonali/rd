
// Problem: Lines
// Contest: ACMP
// URL:
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=144&id_problem=902
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

	int n;
	cin >> n;

	vector<vi> g(n, vi(n, 1));

	ii b, o;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < n; j++) {
			if (s[j] == '@')
				b = {i, j};
			else if (s[j] == 'X')
				o = {i, j};
			else if (s[j] == 'O')
				g[i][j] = 0;
		}
	}

	// xtp(g);

	vector<vii> v(n, vii(n, {-1, -1}));

	queue<ii> q;
	q.push(b);

	v[b.F][b.S] = {-2, -2};

	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	auto mum = [&](ii l) {
		return 0 <= l.F && 0 <= l.S && l.F < n && l.S < n
			   && v[l.F][l.S] == ii{-1, -1} && g[l.F][l.S];
	};

	while (!q.empty()) {
		ii u = q.front();
		q.pop();

		ii e;
		for (int i = 0; i < 4; i++) {
			e = {u.F + dx[i], u.S + dy[i]};

			if (mum(e)) {
				v[e.F][e.S] = u;
				q.push(e);
			}
		}
	}

	// xtp(v);

	vii y;
	ii e = v[o.F][o.S];

	if (e == ii{-1, -1}) {
		cout << "N\n";
		return 0;
	}

	while (e != ii{-2, -2}) {
		g[e.F][e.S] = 2;
		e = v[e.F][e.S];
	}

	cout << "Y\n";
	g[o.F][o.S] = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ii{i, j} == b)
				cout << "@";
			else if (g[i][j] == 0)
				cout << "O";
			else if (g[i][j] == 1)
				cout << ".";
			else
				cout << "+";
		}
		cout << endl;
	}

	return 0;
}
