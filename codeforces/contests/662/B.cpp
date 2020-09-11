
// Problem: B. Applejack and Storages
// Contest: Codeforces - Codeforces Round #662 (Div. 2)
// URL: https://codeforces.com/contest/1393/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Muallif: Azimjon Mehmonali o'g'li

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

int a[100010];

signed main() {
	TEZ;

	int n;
	cin >> n;

	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t]++;
	}

	int q;
	cin >> q;

	set<int> s[10];

	for (int i = 1; i < 100010; i++) {
		if (a[i]) s[min(a[i], 8ll)].insert(i);
	}

	char c;
	int x;
	while (q--) {
		cin >> c >> x;

		if (c == '+') {
			t = a[x]++;
			s[min(t, 8ll)].erase(x);
			s[min(t + 1, 8ll)].insert(x);
			xtp(t + 1);
		} else {
			t = a[x]--;
			s[min(t, 8ll)].erase(x);
			s[min(t - 1, 8ll)].insert(x);
		}

		bool kv, tr;
		kv = 0;
		tr = 0;

		for (int i = 4; i <= 8; i++) {
			if (!kv && s[i].size()) {
				kv = 1;
				if (s[i].size() > 1) tr = 1;
				xtp(i);
				continue;
			}
			if (s[i].size()) {
				tr = 1;
			}
		}
		// xtp(kv);
		// xtp(tr);
		xtp(s[4]);
		xtp(s[5]);

		tr = tr || s[2].size() >= 2 || (s[6].size() && s[2].size())
			 || (s[7].size() && s[2].size()) || (s[8].size() && s[2].size())
			 || (s[3].size() && s[2].size()) || s[8].size()
			 || (s[3].size() >= 2) || (s[3].size() && s[6].size())
			 || (s[3].size() && s[7].size()) || (s[3].size() && s[8].size());

		if (tr && kv)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
