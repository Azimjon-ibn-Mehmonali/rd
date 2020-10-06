
// Problem: C. Cold War
// Contest: Yandex - RuCode Championship 2020 Div C
// URL:
// https://official.contest.yandex.com/rucode2020autumn/contest/20369/problems/C/
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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

typedef std::pair<double, double> TriPoint;

inline double Det2D(TriPoint &p1, TriPoint &p2, TriPoint &p3) {
	return +p1.first * (p2.second - p3.second)
		   + p2.first * (p3.second - p1.second)
		   + p3.first * (p1.second - p2.second);
}

void CheckTriWinding(TriPoint &p1, TriPoint &p2, TriPoint &p3,
					 bool allowReversed) {
	double detTri = Det2D(p1, p2, p3);
	if (detTri < 0.0) {
		if (allowReversed) {
			TriPoint a = p3;
			p3 = p2;
			p2 = a;
		} else
			throw std::runtime_error("triangle has wrong winding direction");
	}
}

bool BoundaryCollideChk(TriPoint &p1, TriPoint &p2, TriPoint &p3, double eps) {
	return Det2D(p1, p2, p3) < eps;
}

bool BoundaryDoesntCollideChk(TriPoint &p1, TriPoint &p2, TriPoint &p3,
							  double eps) {
	return Det2D(p1, p2, p3) <= eps;
}

bool TriTri2D(TriPoint *t1, TriPoint *t2, double eps = 0.0,
			  bool allowReversed = true, bool onBoundary = true) {
	// Trangles must be expressed anti-clockwise
	CheckTriWinding(t1[0], t1[1], t1[2], allowReversed);
	CheckTriWinding(t2[0], t2[1], t2[2], allowReversed);

	bool (*chkEdge)(TriPoint &, TriPoint &, TriPoint &, double) = NULL;
	if (onBoundary)	 // Points on the boundary are considered as colliding
		chkEdge = BoundaryCollideChk;
	else  // Points on the boundary are not considered as colliding
		chkEdge = BoundaryDoesntCollideChk;

	// For edge E of trangle 1,
	for (int i = 0; i < 3; i++) {
		int j = (i + 1) % 3;

		// Check all points of trangle 2 lay on the external side of the edge E.
		// If they do, the triangles do not collide.
		if (chkEdge(t1[i], t1[j], t2[0], eps)
			&& chkEdge(t1[i], t1[j], t2[1], eps)
			&& chkEdge(t1[i], t1[j], t2[2], eps))
			return false;
	}

	// For edge E of trangle 2,
	for (int i = 0; i < 3; i++) {
		int j = (i + 1) % 3;

		// Check all points of trangle 1 lay on the external side of the edge E.
		// If they do, the triangles do not collide.
		if (chkEdge(t2[i], t2[j], t1[0], eps)
			&& chkEdge(t2[i], t2[j], t1[1], eps)
			&& chkEdge(t2[i], t2[j], t1[2], eps))
			return false;
	}

	// The triangles collide
	return true;
}

signed main() {
	TEZ;

	TriPoint a, b, c, aa, bb, cc, o;
	int x, y;

	cin >> x >> y;
	a = TriPoint(x, y);
	aa = TriPoint(-x, -y);

	cin >> x >> y;
	b = TriPoint(x, y);
	bb = TriPoint(-x, -y);

	cin >> x >> y;
	c = TriPoint(x, y);
	cc = TriPoint(-x, -y);

	TriPoint t1[] = {a, b, c}, t2[] = {aa, bb, cc};

	if (TriTri2D(t1, t2)) {
		cout << 987654321 << endl;
	} else {
		cout << aa.F << " " << aa.S << " " << bb.F << " " << bb.S << " " << cc.F
			 << " " << cc.S << endl;
	}
	return 0;
}
