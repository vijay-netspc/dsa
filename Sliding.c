#include <stdio.h>

#define MAX_SIZE 1000

void maxSlidingWindow(int nums[], int numsSize, int k, int result[], int *returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return;
    }

    int queue[MAX_SIZE];
    int front = 0, rear = 0;

    for (int i = 0; i < k; i++) {
        while (rear > front && nums[i] >= nums[queue[rear - 1]]) {
            rear--;
        }
        queue[rear++] = i;
    }

    result[0] = nums[queue[front]];

    for (int i = k; i < numsSize; i++) {
        while (front < rear && queue[front] <= i - k) {
            front++;
        }

        while (rear > front && nums[i] >= nums[queue[rear - 1]]) {
            rear--;
        }
        queue[rear++] = i;

        result[i - k + 1] = nums[queue[front]];
    }

    *returnSize = numsSize - k + 1;
}

int main() {
    int nums[MAX_SIZE];
    int result[MAX_SIZE];
    int numsSize, k;
    int returnSize;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &numsSize);

    if (numsSize > MAX_SIZE) {
        printf("Error: Number of elements exceeds the maximum allowed size.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter the size of the sliding window (k): ");
    scanf("%d", &k);

    if (k > numsSize || k <= 0) {
        printf("Error: Invalid window size.\n");
        return 1;
    }

    maxSlidingWindow(nums, numsSize, k, result, &returnSize);

    printf("Max sliding window: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
