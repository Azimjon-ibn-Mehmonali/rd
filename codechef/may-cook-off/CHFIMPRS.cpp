
// Problem : Impressing Chefina
// Contest : CodeChef - May Cook-Off 2020 Division 2
// URL : https://www.codechef.com/COOK118B/problems/CHFIMPRS
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

#define sqr(x) (x) * (x)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define rALL(a) a.rbegin(), a.rend()
#define SORT(a) sort(ALL(a))
#define sc scanf
#define pr printf
#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)
#define INF 1000000000
#define mod 1000000007

const double PI = 3.1415926535897932384626433832795;

void bajar() {
	int n, m;
	sc("%d%d", &n, &m);

	int s = n * m;
	int tt;

	int a[100010] = {0};

	while (s--) {
		// cin >> t;
		sc("%d", &tt);
		a[tt]++;
	}

	int j[n][m];
	if (m & 1) {
		int oq = 0;
		for (int i = 1; i <= 100005; i++) {
			if (a[i] & 1) {
				if (oq >= n) {
					cout << -1 << endl;
					return;
				}

				j[oq][(m / 2)] = i;
				// xatop(m / 2 + 1);
				oq++;
				a[i]--;
			}
		}

		oq = 0;
		int us = 0;
		for (int i = 1; i <= 100005; i++) {
			if (a[i]) {
				int nc = a[i] / 2;
				while (nc) {
					j[oq][us] = j[oq][m - us - 1] = i;
					oq++;
					nc--;
					if (oq >= n) oq = 0, us++;
				}
			}
		}
	} else {
		int oq = 0;
		int us = 0;
		for (int i = 1; i <= 100005; i++) {
			if (a[i] % 2 == 0) {
				int nc = a[i] / 2;
				while (nc) {
					j[oq][us] = j[oq][m - us - 1] = i;
					oq++;
					nc--;
					if (oq >= n) oq = 0, us++;
				}
			} else {
				cout << -1 << endl;
				return;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++)
			cout << j[i][k] << " ";
		cout << endl;
	}
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	//
	int t;
	sc("%d", &t);

	while (t--)
		bajar();

	return 0;
}
