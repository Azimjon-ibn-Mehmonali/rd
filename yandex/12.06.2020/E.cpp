
// Problem : E. Stipendiyaga navbat
// Contest : Yandex - Uyda qoling - zavq oling #3
// URL : https://contest.yandex.ru/contest/18414/problems/E/
// Memory Limit : 64 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
			 tree_order_statistics_node_update>
	indexed_set;

#define lsb(x) ((x) & (-x))

int n;
int ft[100005] = {0};

vi almashtir(vi a) {
	vi t = a;
	SORT(t);

	for (int i = 0; i < a.size(); i++) {
		a[i] = lower_bound(ALL(t), a[i]) - t.begin() + 1;
	}

	return a;
}

void qosh(int i, int k) {
	while (i <= n) {
		ft[i] += k;
		i += lsb(i);
	}
}

ll yig(int i) {
	ll jv = 0;
	while (i > 0) {
		jv += ft[i];
		i -= lsb(i);
	}

	return jv;
}

int nav[100005];

int main() {
	TEZ;

	cin >> n;

	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		nav[t] = i;
	}

	vi a;
	for (int i = 1; i <= n; i++) {
		cin >> t;

		a.pb(nav[t]);
	}

	// for (int i : a)
	// cout << i << " ";

	ll jv = 0;
	for (int i = n - 1; i >= 0; i--) {
		jv += yig(a[i] - 1);
		qosh(a[i], 1);
	}

	cout << jv << endl;

	return 0;
}
