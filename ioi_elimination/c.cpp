// Muallif: Azimjon Mehmonali o'g'li

//=========================================================

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

//=========================================================
#ifdef DEBUG
#define xtp xtp1
#else
#define xtp(x)
#endif
//=========================================================

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

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

int diam(vector<vi> g) {
	int n = g.size();
	vi ma(n, 0);

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : g[u]) {
			if (ma[v] || v == 0) continue;
			ma[v] = ma[u] + 1;
			q.push(v);
		}
	}

	int ke = max_element(ALL(ma)) - ma.begin();
xtp(ma);
	q.push(ke);
	ma.clear();
	ma.assign(n, 0);
        while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
			if (ma[v] || v == ke) continue;
                        ma[v] = ma[u] + 1;
                        q.push(v);
                }
        }

	return *max_element(ALL(ma));
}

signed main() {
	TEZ;

	int n;
	cin >> n;

	vector<vi> gn(n, vi());
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		gn[a].pb(b);
		gn[b].pb(a);
	}

	int m;
        cin >> m;

        vector<vi> gm(m, vi());
        for (int i = 0; i < m - 1; i++) {
                cin >> a >> b;
		a--;
		b--;
                gm[a].pb(b);
                gm[b].pb(a);
        }
	int dn = diam(gn);
	int dm = diam(gm);
xtp(gn);
	xtp(dn);
	xtp(dm);

	int jv = 1;
	
	if (dn & 1)
		jv += dn / 2 + 1;
	else
		jv += dn / 2;
	if (dm & 1)
		jv += dm / 2  +1;
	else
		jv += dm / 2;
	jv = max({jv, dn, dm});
	cout << jv << endl;
	return 0;
}
