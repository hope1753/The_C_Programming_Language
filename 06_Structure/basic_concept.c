#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main() {
    struct Point p = {1, 2};

    printf("%d %d", p.x, p.y);

    return 0;
}