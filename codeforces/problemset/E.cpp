
// Problem: E. Deleting Numbers
// Contest: Codeforces - Codeforces Round #670 (Div. 2)
// URL: https://codeforces.com/contest/1406/problem/E
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

vi tub = {2,   3,	5,	 7,	  11,  13,	17,	 19,  23,  29,	31,	 37,  41,  43,
		  47,  53,	59,	 61,  67,  71,	73,	 79,  83,  89,	97,	 101, 103, 107,
		  109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
		  191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
		  269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
		  353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
		  439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
		  523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
		  617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
		  709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
		  811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
		  907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

signed main() {
	TEZ;

	int n;
	cin >> n;

	function<int(int, int)> sora(int c, int y) {
		int t;
		cout << (char)c << " " << y << endl;
		cout.flush();
		cin >> t;

		return t;
	};

	int jv = 1;
	for (int i : tub) {
		if (i * i > n) break;

		if (sora('B', i)) }

	return 0;
}
