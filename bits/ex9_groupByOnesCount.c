#include <stdio.h>

int ex9() {
	int arr[10] = {225, 12, 68, 435, 275, 19, 553, 36, 119, 9};
	/* correct output:
	* 
	* 2: 12, 68, 19, 9, 36
	* 4: 275, 39, 225, 553
	* 6: 619, 435, 119
	* 
	*/


	int length = sizeof(arr) / sizeof(arr[0]);

	int** matrix = (int **)malloc(length * sizeof(int*));
	for (int i = 0; i < length; i++) {
		matrix[i] = (int*)malloc((length + 1) * sizeof(int));
		for (int j = 0; j < length + 1; j++) {
			matrix[i][j] = -1; // assign -1 to all elements of the matrix
		}
	}
	
	for (int i = 0; i < length; i++) {
		int current = arr[i];
		int count = 0;
		for (int j = 0; j < sizeof(arr[i]); j++) {
			count += current & 1;
			current >>= 1;
		}
		int rowIndex = 0;
		for (int j = 0; j < length; j++) {
			if (matrix[j][0] == count) {
				rowIndex = j;
				break;
			}else if (matrix[j][0] == -1) {
				rowIndex = j;
			}
		}
		for (int j = 1; j < length; j++) {
			if (matrix[rowIndex][j] == -1) {
				matrix[rowIndex][j] = arr[i];
			}
		}
	}

	for (int i = 0; i < length; i++) {
		if (matrix[i][0] == -1) continue;
		printf("%d: ", matrix[i][0]);
		for (int j = 1; j < length; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}

	return 0;
}