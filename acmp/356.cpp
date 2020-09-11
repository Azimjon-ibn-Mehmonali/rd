
// Problem: Копилка
// Contest: ACMP
// URL:
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=139&id_problem=867
// Memory Limit: 16 MB
// Time Limit: 1000 ms
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
#define rALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define rSORT(a) sort(rALL(a))
#define REV(a) reverse(ALL(a))
#define sqr(x) ((x) * (x))

//===========================================================

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
//===========================================================

#define TEZ                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);

const long double PI = 3.1415926535897932384626433832795;
const ll mod = 1000000007LL;
const int INF = 1000000000;
const ll LINF = 1000000000000000000LL;

int main() {
	TEZ;

	int b, t;
	cin >> b >> t;

	b = t - b;

	int n;
	cin >> n;

	vii c(n);

	for (auto& [f, s] : c) {
		cin >> f >> s;
	}

	int dp[10050] = {0};
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= b; i++) {
		for (auto [f, s] : c) {
			if (s <= i && dp[i - s] != -1) {
				if (dp[i] == -1) dp[i] = dp[i - s] + f;
				dp[i] = min(dp[i], dp[i - s] + f);
			}
		}
	}

	int dp1[10050] = {0};
	memset(dp1, -1, sizeof(dp1));
	dp1[0] = 0;
	for (int i = 1; i <= b; i++) {
		for (auto [f, s] : c) {
			if (s <= i && dp1[i - s] != -1) {
				if (dp1[i] == -1) dp1[i] = dp1[i - s] + f;
				dp1[i] = max(dp1[i], dp1[i - s] + f);
			}
		}
	}
	if (dp[b] != -1 && dp1[b] != -1) {
		cout << dp[b] << " " << dp1[b] << endl;
	} else {
		cout << "This is impossible." << endl;
	}

	return 0;
}
