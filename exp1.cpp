Name:Manav Uttekar
Rollno:11
TItle: Write C++ program to draw a concave polygon and fill it with desired color using scan fill algorithm

#include <graphics.h>
#include <iostream>
using namespace std;

void scanFill(int x[], int y[], int n, int fillColor) {
    int ymin = y[0], ymax = y[0];
    
    for (int i = 1; i < n; i++) {
        ymin = min(ymin, y[i]);
        ymax = max(ymax, y[i]);
    }

    for (int sy = ymin; sy <= ymax; sy++) {
        int intersections[20], count = 0;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            int x1 = x[i], y1 = y[i], x2 = x[next], y2 = y[next];
            if (y1 > y2) swap(y1, y2), swap(x1, x2);

            if (sy >= y1 && sy < y2)
                intersections[count++] = x1 + (sy - y1) * (x2 - x1) / (y2 - y1);
        }

        for (int i = 0; i < count - 1; i += 2)
            line(intersections[i], sy, intersections[i + 1], sy);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int x[20], y[20];
    for (int i = 0; i < n; i++) {
        cout << "Enter x and y for vertex " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    int fillColor;
    cout << "Enter fill color code (1 to 15): ";
    cin >> fillColor;
    setcolor(fillColor);

    for (int i = 0; i < n; i++)
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);

    scanFill(x, y, n, fillColor);

    getch();
    closegraph();
    return 0;
}

