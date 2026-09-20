#include <stdio.h>

// int atoi(char s[]) {
//     int n = 0;

//     for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
//         n = 10 * n + (s[i] - '0');
//     }

//     return n;
// }

int power(int base, int n) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        num *= base;
    }

    return num;
}

int strlen_custom(char s[]) {
    int i;
    for (i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != EOF; i++);

    return i;
}

int htoi(char s[]) {
    int n = 0;
    if (s[0] != '0' && s[1] != 'x') {
        return -1;
    }
    int len = strlen_custom(s) - 1;

    for (int i = len; s[i] >= '0' && s[i] <= 'f' && i > 1; i--) {
        if (s[i] <= '9') {
            n = n + power(16, len - i) * (s[i] - '0');
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            n = n + power(16, len - i) * (s[i] - 'A' + 10);
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            n = n + power(16, len - i) * (s[i] - 'a' + 10);
        }
        else {
            return -1;
        }
    }

    return n;
}
int main() {
    char string[10];
    char c;

    for (int i = 0; i < 10 && (c = getchar()) != EOF && c != '\n'; i++) {
        string[i] = c;
    }

    // printf("%s + 10 = %d\n", string, string + 10); // 301 + 10 = -555746380
    // int num = atoi(string);
    // printf("%d + 10 = %d\n", num, num + 10); // 301 + 10 = 311
    printf("%s = %d\n", string, htoi(string));

    return 0;
}