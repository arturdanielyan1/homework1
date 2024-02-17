#include <stdio.h>

int ex1() {
    /*
       test examples:
          7474 (1110100110010) -> 4
          5376 (1010100000000) -> 3
    */
    int input;
    scanf_s("%d", &input);
    int count = 0;
    input >>= 8; // we don't need the first 8 anyway
    while (input) { // while input is not 0
        count += input & 1; // input & 1 gives the rightmost binary value of [input]
        input >>= 1;
    }
    printf("%d\n", count);

    return 0;
}