#include <stdio.h>

void integer_temperature_conversion(int lower, int upper, int step) {
    printf("Integer__\n");
    int fahr = 0;
    int celsius = 0;
    while (fahr <= upper) 
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d\t%6d\n", fahr, celsius); //왜 0이 출력 안되는 거지?
        fahr += step;
    }
}

void real_N_temperature_conversion(int lower, int upper, int step) {
    printf("Real_Number__\n");
    float fahr = 0;
    float celsius = 0;
    while (fahr <= upper) 
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
}
int main() {
    //char 문자형 1바이트 short 단정도 정수형 long 배정도 정수형 double 배정도 부동소수점형 각각 정밀도가 다름
    integer_temperature_conversion(0, 300, 20);
    real_N_temperature_conversion(0, 300, 20);

    return 0;
}