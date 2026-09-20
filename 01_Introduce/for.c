#include <stdio.h>

int main() {
    float fahr;
    float celsius;
    int upper, step;
    upper = 300;
    step = 20;
    for (fahr = 0; fahr <= upper; fahr += step) {
        celsius = 5 * (fahr -32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }

    return 0;
}