// Muallif: Azimjon Mehmonali o'g'li

#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

//=========================================================
int recur_depth = 0;
#ifdef DEBUG
#define xtp(x)                                                           \
	{                                                                    \
		++recur_depth;                                                   \
		auto x_ = x;                                                     \
		--recur_depth;                                                   \
		cerr << string(recur_depth, '\t') << __func__ << ":" << __LINE__ \
			 << "\t" << #x << " = " << x_ << endl;                       \
	}
#else
#define xtp(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(
	Ostream& os, const Cont& v) {
	os << "[";
	for (auto& x : v) {
		os << x << ", ";
	}
	return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
	return os << "{" << p.first << ", " << p.second << "}";
}
//=========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897;
const int mod = 1000000007LL;
const int INF = 1e18;

signed main() {
	TEZ;

	int n;
	cin >> n;

	vi a(n);
	for (int& i : a)
		cin >> i;

	vector<pair<ii, ii>> jv, jj;
	SORT(a);
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++) {
				if (a[i] + a[j] > a[k] && a[i] + a[k] > a[j]
					&& a[k] + a[j] > a[i]) {
					jv.pb({{a[i] + a[j] + a[k], a[k]}, {a[i], a[j]}});
				}
			}

	if (jv.empty()) {
		cout << -1 << endl;
		return 0;
	}

	rSORT(jv);
	jj.pb(jv[0]);
	jv.erase(jv.begin());
	for (auto i : jv) {
		if (jj.back().F == i.F && jj.back().S.F == i.S.F
			&& jj.back().S.S != i.S.S)
			jj.pb(i);
	}

	if (jj.empty()) {
		cout << -1 << endl;
		return 0;
	}

	for (auto i : jj)
		cout << i.S.F << " " << i.S.S << " " << i.F.S << endl;

	return 0;
}
