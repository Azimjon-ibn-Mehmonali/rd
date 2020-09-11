// Muallif: Azimjon Mehmonali o'g'li

#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                                                   \
	tree<long long, null_type, greater_equal<long long>, rb_tree_tag, \
		 tree_order_statistics_node_update>

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

	int n, d;
	cin >> n >> d;

	ordered_set s;

	vi a(n);
	for (int& i : a)
		cin >> i;

	int jv = 0;
	for (int i = 0; i < d; i++)
		s.insert(a[i]);

	for (int i = d; i < n; i++) {
		int med;
		if (d & 1) {
			med = 2 * *s.find_by_order(d / 2);
		} else {
			int h = *s.find_by_order(d / 2 - 1);
			int j = *s.find_by_order(d / 2);
			med = (h + j);
		}
		if (med <= a[i]) {
			xtp(a[i]);
			xtp(med);
			xtp(s);
			jv++;
		}
		s.erase(a[i - d]);
		s.insert(a[i]);
	}

	cout << jv << endl;

	return 0;
}
