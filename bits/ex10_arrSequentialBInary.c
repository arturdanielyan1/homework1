#include <stdio.h>
#include <stdbool.h>

int ex10() {
	int arr[10] = {85, 1040, 865, 42, 35, 5461, 888, 341, 5, 105};
	//correct output: 85, 42, 5461, 341, 5

	int arrLength = sizeof(arr) / sizeof(arr[0]);
	bool firstFound = false;
	for (int i = 0; i < arrLength; i++) {
		int current = arr[i];
		int bitCount = 0; // how many bits the arr[i] occupies excluding all leftmost 0s
		for (int j = 0; j < sizeof(current) * 8; j++) {
			if (current & 1) {
				bitCount = j+1;
			}
			current >>= 1;
		}

		bool isSame = false;
		current = arr[i];
		while (!isSame && bitCount) {
			isSame = (current & 1) == ((current >> 1) & 1);
			bitCount--;
			current >>= 1;
		}
		if (!isSame) {
			if (firstFound) printf(", ");
			printf("%d", arr[i]);
			firstFound = true;
		}
	}

	printf("\n");
	return 0;
}