#include <stdio.h>
#include <math.h>

int ex4() {
    /*
        test examples:
            '!' (33, 100001) - symetrical,
            '(' (40, 101000) - not symetrical,
            'k' (107, 1101011) - symetrical,
    */
    char input;
    scanf_s("%c", &input);

    unsigned int number = input; // take input char as an integer
    int bitCount = 0; // how many bits the number occupies(-1) excluding all leftmost 0s
    for (int i = 0; i < sizeof(number) * 8; i++) {
        if (number & 1) {
            bitCount = i; // this way we get the index of the leftest 1, and the values to the left of it are all 0s
        }
        number >>= 1;
    }

    int reverse = 0;
    number = input;
    for (int i = bitCount; i >= 0; i--) {
        reverse |= (number & 1) << i; // puts the last binary number of [number] in the corresponding place in [reverse]
        /*
            [number & 1] gives the rightmost binary value of [number] and [i]
            represents its original index in the initial input. And as we need
            that value to be placed in the opposite side(bitCount - i) we shift it
            to left by [i]
        */
        number >>= 1;
    }

    printf("binary of entered char is%s symetrical\n", (input == reverse) ? "" : "n't");

    return 0;
}
