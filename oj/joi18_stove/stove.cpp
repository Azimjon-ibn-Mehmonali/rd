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

signed main() {
	TEZ;

    int n, k;
    cin >> n >> k;

    vi t(n);
    for (int &i : t)
        cin >> i;
    
    int jv = t.back() - t[0] + 1;

    vi b;
    for (int i = 1; i < n; i++)
        b.push_back(t[i] - t[i - 1] - 1);
    
    rSORT(b);
    for (int i = 0; i < k - 1; i++)
        jv -= b[i];
    
    cout << jv << endl;

	return 0;
}
