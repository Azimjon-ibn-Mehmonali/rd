
// Problem : B. Young Explorers
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/contest/1355/problem/B
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
#define jsatr debug(__LINE__)
#define INF 1000000000
#define mod 1000000007

int main() {
	int T;
	sc("%d", &T);

	while (T--) {
		int n;
		sc("%d", &n);

		vi a(n);
		for (int &i : a)
			sc("%d", &i);

		SORT(a);
		// a.pb(INF);
		int jv = 0;
		for (int i = 0; i < n;) {
			int h = a[i];

			if (h > n) {
				break;
			}

			int s = 0;
			int j;
			for (j = i; j < n && s < h; j++, s++) {
				h = max(h, a[j]);
			}

			if (s >= h) {
				jv++;
			}
			// xatop(i);
			// xatop(j);
			// xatop()
			i = j;
		}
		pr("%d\n", jv);
	}

	return 0;
}
