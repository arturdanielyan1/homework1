#include <stdio.h>
#include <stdbool.h>

int ex7() {
	int arr[10] = { 45752, 47545, 18, 38550, 8738, 55034, 46003, 59110, 59704, 65535 };
	// correct output: 47545, 38550, 46003, 59110, 65535

	int arrLength = sizeof(arr) / sizeof(arr[0]);
	bool firstFound = false;
	for (int i = 0; i < arrLength; i++) {
		int current = arr[i];
		int first8 = (current & 0b1111111100000000) >> 8; // take first 8 as they are and shift right by 8, because without shifting we would have 8 0s at the end
		int second8 = (current & 0b11111111); // take last 8
		if (first8 == second8) {
			if (firstFound) printf(", ");
			printf("%d", arr[i]);
			firstFound = true;
		}
	}

	printf("\n");
	return 0;
}