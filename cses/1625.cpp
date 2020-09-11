
// Problem : Grid Paths
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1625
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
string s;
int bor[7][7] = {0};

bool mum(int x, int y) {
	return 0 <= x && x < 7 && 0 <= y && y < 7 && !bor[x][y];
}

void bajar(int x, int y, int jo) {
	if (x == 6 && y == 0) {
		jv += jo == 48;
		// if (jv > 100) cout << jv << endl;
		return;
	}

	if (((x == 0 || (bor[x - 1][y] && bor[x + 1][y])) && (y > 0 && y < 7)
		 && (!bor[x][y - 1] && !bor[x][y + 1]))
		|| ((y == 6 || (bor[x][y - 1] && bor[x][y + 1])) && (x > 0 && x < 7)
			&& (!bor[x - 1][y] && !bor[x + 1][y]))
		|| ((x == 6 || (bor[x - 1][y] && bor[x + 1][y])) && (y > 0 && y < 6)
			&& (!bor[x][y - 1] && !bor[x][y + 1]))
		|| ((y == 0 || (bor[x][y - 1] && bor[x][y + 1])) && (x > 0 && x < 7)
			&& (!bor[x - 1][y] && !bor[x + 1][y])))
		return;

	bool sor = s[jo] == '?';

	int xx, yy;

	if (sor || s[jo] == 'R') {
		xx = x;
		yy = y + 1;
		if (mum(xx, yy)) {
			bor[xx][yy] = 1;
			bajar(xx, yy, jo + 1);
			bor[xx][yy] = 0;
		}
	}

	if (sor || s[jo] == 'D') {
		xx = x + 1;
		yy = y;
		if (mum(xx, yy)) {
			bor[xx][yy] = 1;
			bajar(xx, yy, jo + 1);
			bor[xx][yy] = 0;
		}
	}

	if (sor || s[jo] == 'L') {
		xx = x;
		yy = y - 1;
		if (mum(xx, yy)) {
			bor[xx][yy] = 1;
			bajar(xx, yy, jo + 1);
			bor[xx][yy] = 0;
		}
	}

	if (sor || s[jo] == 'U') {
		xx = x - 1;
		yy = y;
		if (mum(xx, yy)) {
			bor[xx][yy] = 1;
			bajar(xx, yy, jo + 1);
			bor[xx][yy] = 0;
		}
	}
}

int main() {
	TEZ;

	cin >> s;

	bor[0][0] = 1;
	bajar(0, 0, 0);

	cout << jv << endl;

	return 0;
}
