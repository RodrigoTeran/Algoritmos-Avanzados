#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

struct Triangle {
    Point p1, p2, p3;
    Triangle(const Point& p1, const Point& p2, const Point& p3) : p1(p1), p2(p2), p3(p3) {}
};

vector<Triangle> delaunayTriangulation(const vector<Point>& points) {
    vector<Triangle> triangles;

    // Caso base:
    /**
     * Si hay 3 puntos entonces generamos
     * un triángulo
    */
    if (points.size() == 3) {
        triangles.push_back(Triangle(points[0], points[1], points[2]));
        return triangles;
    }

    // Aquí dividimos los puntos en dos conjuntos
    int mid = points.size() / 2;
    vector<Point> leftPoints(points.begin(), points.begin() + mid);
    vector<Point> rightPoints(points.begin() + mid, points.end());

    // Triangular recursivamente ambos conjuntos
    vector<Triangle> leftTriangles = delaunayTriangulation(leftPoints);
    vector<Triangle> rightTriangles = delaunayTriangulation(rightPoints);

    // Finalmente combinamos las triangulaciones parciales
    triangles.insert(triangles.end(), leftTriangles.begin(), leftTriangles.end());
    triangles.insert(triangles.end(), rightTriangles.begin(), rightTriangles.end());

    return triangles;
}

int main() {
    vector<Point> points = {
        Point(1, 1),
        Point(2, 4),
        Point(5, 2),
        Point(7, 5),
        Point(9, 3)
    };

    vector<Triangle> triangles = delaunayTriangulation(points);

    cout << "Triángulos generados:" << endl;
    for (const Triangle& triangle : triangles) {
        cout << "(" << triangle.p1.x << "," << triangle.p1.y << ") ";
        cout << "(" << triangle.p2.x << "," << triangle.p2.y << ") ";
        cout << "(" << triangle.p3.x << "," << triangle.p3.y << ")" << endl;
    }

    return 0;
}
