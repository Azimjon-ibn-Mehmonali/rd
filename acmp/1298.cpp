
// Problem : Возрастающая подпоследовательность
// Contest : ACMP
// URL :
// https://acmp.ru/asp/do/index.asp?main=task&id_course=5&id_section=29&id_topic=137&id_problem=855
// Memory Limit : 16 MB
// Time Limit : 2000 ms
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

	int n;
	cin >> n;

	vi a(n);
	for (int& i : a)
		cin >> i;

	vi lis(n + 1, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (lis[i] < lis[j] + 1 && a[i] > a[j]) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	vi jv;
	int h = *max_element(ALL(lis));
	int i = n - 1;

	while (h && i >= 0) {
		if (lis[i] == h) {
			jv.pb(a[i]);
			h--;
		}
		i--;
	}

	cout << jv.size() << endl;
	for (i = jv.size() - 1; i >= 0; i--)
		cout << jv[i] << " ";

	return 0;
}
