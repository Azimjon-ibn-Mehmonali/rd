
// Problem : C. Game On Leaves
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sc scanf
#define pr printf

#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sqr(x) ((x) * (x))

#define sci(n) sc("%d", &n);
#define sci2(n, m) sc("%d%d", &n, &m);
#define scl(n) sc("%I64d", &n);
#define scl2(n, m) sc("%I64d%I64d", &n, &m);

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

void bajar() {
	int n, x;
	cin >> n >> x;

	vector<vector<int>> g(n + 1, vector<int>());

	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	queue<int> q, qat;
	q.push(x);

	vi bor(n + 1, 0);
	vi qatlam(n + 1, INF);
	bor[x] = 1;
	qatlam[x] = 0;

	while (!q.empty()) {
		int ht = q.front();
		q.pop();

		for (int i = 0; i < g[ht].size(); i++) {
			int bt = g[ht][i];
			if (bor[bt]) continue;

			bor[bt] = true;
			q.push(bt);
			qatlam[bt] = qatlam[ht] + 1;
		}
		// jsatr;
	}

	/*for (int i = 1; i <= n; i++) {
		cout << i << "->" << qatlam[i] << endl;
	}*/

	if (g[x].empty()) {
		cout << "Ayush" << endl;
		return;
	}

	int jv = INF;
	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1) {
			jv = min(jv, qatlam[i]);
		}
	}

	if (jv & 1) {
		cout << "Ashish" << endl;
		return;
	}

	cout << "Ayush" << endl;
}

int main() {
	int t;
	cin >> t;

	while (t--)
		bajar();

	return 0;
}
