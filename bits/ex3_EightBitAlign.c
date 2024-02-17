#include <stdio.h>

int ex3() {
    // 48059 (1011101110111011) -> true
    int input;
    scanf_s("%d", &input);
    int first8 = (input & 0b1111111100000000) >> 8; // take first 8 as they are and shift right by 8, because without shifting we would have 8 0s at the end
    int second8 = (input & 0b11111111); // take last 8

    printf(first8 == second8 ? "true\n" : "false\n");

    return 0;
}