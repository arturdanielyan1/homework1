#include <stdio.h>
#include <stdbool.h>

int ex6() {
	int arr[10] = { 134034, 135058, 134546, 132498, 133778, 14742, 63903, 1426, 2962, 1};
	// correct output: 134034, 134546, 132498, 133778, 1426, 2962

	int target = 0b101;

	int arrLength = sizeof(arr) / sizeof(arr[0]);
	bool firstFound = false;
	for (int i = 0; i < arrLength; i++) {
		int current = arr[i] >> 8;
		for (int j = 8; j <= 12 - 3; j++) {
			// [input & 0b111] gives the rightmost 3 binary values of input
			if ((current & 0b111) == target) { // check if rightmost 3 is 101
				if (firstFound) printf(", ");
				printf("%d", arr[i]);
				firstFound = true;
			}
			current >>= 1;
		}
	}

	printf("\n");
	return 0;
}