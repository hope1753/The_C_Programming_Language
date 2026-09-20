#include <stdio.h>
//v 는 오름차순
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int x = 5;
    int v[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = binsearch(x, v, 10);
    printf("find x = %d, location : %d, result : %d\n", x, n, v[n]);

    return 0;
}