#include <iostream>
#include <vector>

struct Point {
    long long x, y;
};

int orientation(Point a, Point b, Point c) {
    long long val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

std::vector<Point> JarvisconvexHull(std::vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    std::vector<Point> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    do {
        hull.push_back(points[p]);

        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;

    } while (p != l);

    return hull;
}

bool LeftCheck(Point& a, Point& b, Point& c) {
    return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) > 0;
}

bool PointOnSegment(Point& p, Point& q, Point& r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;
    return false;
}

bool PointInPolygonCheck(Point& p, std::vector<Point>& polygon) {
    int n = polygon.size();
    int turns = 0;

    for (int i = 0; i < n; i++) {
        Point v1 = polygon[i];
        Point v2 = polygon[(i + 1) % n];
        if (orientation(v1, v2, p) == 0 && PointOnSegment(v1, p, v2)) {
            return false;
        }
        if (v1.y <= p.y) {
            if (v2.y > p.y && LeftCheck(v1, v2, p))
                turns++;
        } else {
            if (v2.y <= p.y && !LeftCheck(v1, v2, p))
                turns--;
        }
    }
    return turns != 0;
}

int main() {
    int numberofVertices, numberofAllies;
    std::cin >> numberofVertices;

    std::vector<Point> points(numberofVertices);
    for (int i = 0; i < numberofVertices; i++) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::vector<Point> fortress = JarvisconvexHull(points);

    std::cin >> numberofAllies;
    std::vector<Point> allies(numberofAllies);
    for (int i = 0; i < numberofAllies; i++) {
        std::cin >> allies[i].x >> allies[i].y;
    }

    bool allInside = true;
    for (Point& ally : allies) {
        if (!PointInPolygonCheck(ally, fortress)) {
            allInside = false;
            break;
        }
    }

    if (allInside) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
