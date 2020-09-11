
// Problem : C1. Simple Polygon Embedding
// Contest : Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1354/problem/C1
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
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		if (n == 2) {
			cout << 1 << endl;
			continue;
		}

		ld ldi = 1. / sin(PI / (2 * n));
		ld al = PI * (n - 2) / (2 * n);

		ld r = sqrt(ldi * ldi - 1);

		cout << setprecision(9) << r << endl;
	}

	return 0;
}
