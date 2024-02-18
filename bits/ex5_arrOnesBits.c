#include <stdio.h>
#include <stdbool.h>

int ex5() {
	int arr[10] = {150, 2710, 2966, 2198, 6806, 856, 101, 90006, 352662, 4};
	// correct output: 2710, 2966, 6806, 856, 90006

	int arrLength = sizeof(arr) / sizeof(arr[0]);
	bool firstFound = false;
	for (int i = 0; i < arrLength; i++) {
		int count = 0;
		int current = arr[i] >> 8;		// we don't need the first 8 anyway
		for (int j = 8; j <= 12; j++) { // could be 0 to 5
			count += current & 1;		// current & 1 gives the rightmost binary value of [current]
			if (count == 2) {
				if (firstFound) printf(", ");
				printf("%d", arr[i]);
				firstFound = true;
				break;
			}
			current >>= 1;
		}
	}

	printf("\n");
	return 0;
}