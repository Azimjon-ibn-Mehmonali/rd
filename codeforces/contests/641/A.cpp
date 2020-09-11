
// Problem : A. Orac and Factors
// Contest : Codeforces - Codeforces Round #641 (Div. 2)
// URL : https://codeforces.com/contest/1350/problem/A
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
		int n, k;
		cin >> n >> k;

		ll jv = n + 2 * k;
		if (n & 1) {
			for (int i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					jv = n + i;
					n = 0;
					break;
				}
			}
			if (n) jv = 2 * n;
			jv += 2 * (k - 1);
		}

		cout << jv << endl;
	}

	return 0;
}
