#include <stdio.h>
#include <stdbool.h>

int ex8() {
	char arr[] = {'!', '(', 'k', '2', '6', '*', 'U', 'g', 'w', '^'};
	// correct output: !, k, U, w

	int arrLength = sizeof(arr) / sizeof(arr[0]);
	bool firstFound = false;
	for (int i = 0; i < arrLength; i++) {
        unsigned int number = arr[i]; // take arr[i] char as an integer
        int bitCount = 0; // how many bits the number occupies(-1) excluding all leftmost 0s
        for (int j = 0; j < sizeof(number) * 8; j++) {
            if (number & 1) {
                bitCount = j; // this way we get the index of the leftest 1, and the values to the left of it are all 0s
            }
            number >>= 1;
        }

        int reverse = 0;
        number = arr[i];
        for (int j = bitCount; j >= 0; j--) {
            reverse |= (number & 1) << j; // puts the last binary number of [number] in the corresponding place in [reverse]
            /*
                [number & 1] gives the rightmost binary value of [number] and [j]
                represents its original index in the initial arr[i]. And as we need
                that value to be placed in the opposite side(bitCount - j) we shift it
                to left by [j]
            */
            number >>= 1;
        }
        if (arr[i] == reverse) {
            if (firstFound) printf(", ");
            printf("%c", arr[i]);
            firstFound = true;
        }
	}

    printf("\n");
	return 0;
}