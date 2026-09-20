#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main() {
    float fahr;
    
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3.0f\t%6.1f\n", fahr, 5 * (fahr - 32) / 9);
    }

    return 0;
}