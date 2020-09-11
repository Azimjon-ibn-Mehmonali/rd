
// Problem : Chessboard and Queens
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1624
// Memory Limit : 512 MB
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
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

#define xatop(a) cerr << #a << " = " << a << endl;
#define jsatr xatop(__LINE__)

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1000000000;

int jv = 0;
int a[8][8];
int col[8] = {0};
int diag1[16] = {0};
int diag2[16] = {0};

void bajar(int n) {
	if (n == 8) {
		jv++;
		return;
	}

	for (int m = 0; m < 8; m++) {
		if (a[n][m] || col[m] || diag1[n + m] || diag2[m - n + 7]) continue;
		col[m] = diag1[n + m] = diag2[m - n + 7] = 1;
		bajar(n + 1);
		col[m] = diag1[n + m] = diag2[m - n + 7] = 0;
	}
}

int main() {
	TEZ;

	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < 8; j++) {
			a[i][j] = s[j] == '*';
		}
	}

	// for (int i = 0; i < 8; i++) {
	// for (int j = 0; j < 8; j++) {
	// cout << a[i][j];
	// }
	// cout << endl;
	// }
	bajar(0);

	cout << jv << endl;

	return 0;
}
