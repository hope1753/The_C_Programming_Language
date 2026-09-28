#include <stdio.h>

#define XMAX 320
#define YMAX 200

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct Point
{
    int x;
    int y;
};

struct rect {
    struct Point pt1;
    struct Point pt2;
};

struct Point makepoint (int x, int y) {
    struct Point temp;

    temp.x = x;
    temp.y = y;
    
    return temp;
}

struct Point addpoint(struct Point p1, struct Point p2) {
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}

int ptinrect(struct Point p, struct rect r) {
    return p.x > r.pt1.x && p.x < r.pt2.x && p.y > r.pt1.y && p.y < r.pt2.y;
}

struct rect screen;
struct Point middle;
struct Point makepoint(int, int);

struct rect canonrect(struct rect r) {
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);

    return temp;
}

int main() {
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);

    struct Point *pp;
    pp = &screen.pt2;

    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);

    printf("x : %d y : %d Address : %#x\n", pp->x, pp->y, pp);

    return 0;
}
