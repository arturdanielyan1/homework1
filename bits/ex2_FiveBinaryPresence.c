#include <stdio.h>

int ex2() {
    /*
       test examples:
          65024 (1111111000000000) -> doesn't contain
          104448 (11001100000000000) -> doesn't contain
          48640 (1011111000000000) -> doesn't contain
          55808 (1101101000000000) -> contains
          38400 (1001011000000000) -> contains
    */
    int input;
    scanf_s("%d", &input);
    int target = 0b101; // decimal form of binary 101

    input >>= 8; // we don't need the first 8 anyway
    for (int i = 8; i <= 15 - 3; i++) {
        /*
            [input & 0b111] gives the rightmost 3 binary values of input
        */
        if ((input & 0b111) == target) { // check if rightmost 3 is 101
            printf("your input contains 101 in its 8..15 order\n");
            return 0;
        }
        input >>= 1;
    }

    printf("unfortunately your input doesn't contain 101 in its 8..15 order :(\n");

    return 0;
}