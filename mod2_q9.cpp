    #include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Point { double x; double y; };

double distanceBetween(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double bruteForce(const vector<Point> &pts, int left, int right) {
    double best = numeric_limits<double>::infinity();
    for (int i = left; i <= right; ++i)
        for (int j = i + 1; j <= right; ++j)
            best = min(best, distanceBetween(pts[i], pts[j]));
    return best;
}

double stripClosest(vector<Point> &strip, double d) {
    sort(strip.begin(), strip.end(), [](const Point &a, const Point &b){ return a.y < b.y; });
    double best = d;
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < best; ++j)
            best = min(best, distanceBetween(strip[i], strip[j]));
    }
    return best;
}

double closestRec(vector<Point> &ptsSortedX, int left, int right) {
    if (right - left <= 3) return bruteForce(ptsSortedX, left, right);
    int mid = left + (right - left) / 2;
    double midx = ptsSortedX[mid].x;
    double dl = closestRec(ptsSortedX, left, mid);
    double dr = closestRec(ptsSortedX, mid + 1, right);
    double d = min(dl, dr);
    vector<Point> strip;
    for (int i = left; i <= right; ++i)
        if (fabs(ptsSortedX[i].x - midx) < d) strip.push_back(ptsSortedX[i]);
    return min(d, stripClosest(strip, d));
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<Point> pts(n);
    cout << "Enter points as x y per line:\n";
    for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;
    sort(pts.begin(), pts.end(), [](const Point &a, const Point &b){ return a.x < b.x; });
    double answer = closestRec(pts, 0, n - 1);
    cout << "Minimum distance: " << answer << "\n";
    return 0;
}