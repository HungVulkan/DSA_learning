#include <stdio.h>
#include <stdlib.h>
struct V1 {
    int i;
    float f;
};
union V2 {
    int i;
    float f;
};
int main() {
    struct V1 x;
    union V2 y;
    x.i = 21;
    printf("i: %d\n", x.i);
    x.f = 88.5;
    printf("f: %.2f\n", x.f);
    printf("Size of Struc: %d bytes\n", sizeof(x));
    y.i = 21;
    printf("i: %d\n", y.i);
    y.f = 88.5;
    printf("f: %.2f\n", y.f);
    printf("Size of Union: %d bytes\n", sizeof(y));
    return 0;
}
