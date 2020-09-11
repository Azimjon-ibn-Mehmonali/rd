
// Problem : D. Alice, Bob and Candies
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/D
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
#define jsatr xatop(__LINE__)
#define INF 1000000000
#define mod 1000000007

const double PI = 3.1415926535897932384626433832795;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vi a(n);
		for (int &i : a)
			cin >> i;

		int al, bo;
		al = 0;
		bo = n - 1;

		ll aly, boy;
		aly = boy = 0;

		bool yb = true;

		al = 1;
		aly += a[0];

		ll at, bt;
		at = a[0];

		int ys = 1;
		bool bm = 0;
		while (al <= bo) {
			ys++;
			if (bm) break;
			if (al == bo) bm = true;
			if (yb) {
				ll hy = 0;
				while (hy <= at && al <= bo)
					hy += a[bo--];

				boy += hy;
				if (hy > at) bt = hy;
				// else
				// break;
			} else {
				ll hy = 0;
				while (hy <= bt && al <= bo)
					hy += a[al++];

				aly += hy;
				if (hy > bt) at = hy;
				// else
				// break;
			}
			yb = !yb;
		}

		cout << ys << " " << aly << " " << boy << endl;
	}

	return 0;
}
