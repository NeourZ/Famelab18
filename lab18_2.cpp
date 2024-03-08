#include <iostream>
#include <algorithm>
using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(const Rect *r1,const Rect *r2) {
    double left = max(r1 -> x, r2 -> x);
    double right = min(r1 -> x + r1 -> w, r2 -> x + r2 -> w);
    double top = min(r1 -> y, r2 -> y);
    double bottom = max(r1 -> y - r1 -> h, r2 -> y - r2 -> h);

    double width = max(0.0, right - left);
    double height = max(0.0, top - bottom);

    return width * height;
}

int main() {
    Rect R1 = {1, 1, 5, 5};
    Rect R2 = {2, 2, 5, 5};
    cout << overlap(&R1, &R2) << endl; // Output: 12

    Rect R3 = {1, 1, 5, 5};
    Rect R4 = {7, 2, 3, 3};
    cout << overlap(&R3, &R4) << endl; // Output: 0

    Rect R5 = {-1, 2, 6.9, 9.6};
    Rect R6 = {0, 0, 1.2, 2.5};
    cout << overlap(&R5, &R6) << endl; // Output: 3

    return 0;
}