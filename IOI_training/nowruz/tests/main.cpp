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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int m, n, k;
int d[1030][1030];

void dfs(int x, int y) {

}

signed main() {
	TEZ;

	cin >> m >> n >> k;

    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= n; j++) {
            d[i][j] = s[j - 1] == '.';
        }
    }

   for (int i = 1; i <= n; i++) {
   
   } 

	return 0;
}
