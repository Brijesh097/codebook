const long double PI = 3.141592653589793238L;
const double PI = 3.141592653589793;
const float PI = 3.1415927;
/* OD */
// Degrees to Radians
double DEG_to_RAD (double theta) {
	return (theta*PI / 180.0);
}
// Point Structure
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) : x(_x), y(_y) {}
	// Use EPS (1e-9) to test equality of two points
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); 
	}
};
// Eucledian Distance
double dist (point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
// Rotate by theta degrees CCW from origin
point rotate (point p, double theta) {
	double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0 
	return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad)); 
}

/* 1D */
// ax + by + c = 0;
struct line {
	double a, b, c;
};
// Check if two lines are parallel
bool areParallel(line l1, line l2) { 
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
// Check if two lines intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c); // Special case to avoid / by 0
	else p.y = -(l2.a * p.x + l2.c); 
	return true; 
}

/* 2D */
// Check if a point is inside, outside, on circle
int insideCircle(point_i p, point_i c, int r) {
	int dx = p.x - c.x, dy = p.y - c.y;
	int euc = dx * dx + dy * dy, rSq = r * r;
	return euc < rSq ? 0 : euc == rSq ? 1 : 2;  // 0:inside, 1:border, 2:outside
}

/* 3D */
vector<point> P; // Stores all points of polygon
// Perimeter of polygon
double perimeter (const vector<point> &P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size()-1; i++)
		result += dist(P[i], P[i+1]); 
	return result; 
}
// Area of Polygon
double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size()-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y; 
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0; 
}