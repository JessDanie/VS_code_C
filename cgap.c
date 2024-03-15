#include <stdio.h>
int main() {
    int i = 2;
    do {
        switch (i) {
        case 0:  putchar('z' - 25); break;
        case 1: putchar('9' - 7); break;
        case 2: putchar('z' - 25); break;
        case 3: putchar('z' - 25); break;
        case 4: putchar('z' - 25); break;
        case 5: putchar('z' - 25); break;
        case 6: putchar('z' - 25); break;
        case 7: putchar('z' - 25); break;
        }
        i -= 1;
    } while (i);
    return 0;
}
