#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int maxLength = 0; // To store the maximum length of valid parentheses
    int lastInvalidIndex = -1; // To track the last unmatched ')' index
    int length = strlen(s);
    int* stack = (int*)malloc(length * sizeof(int)); // Stack to store indices
    int top = -1; // Stack pointer

    for (int i = 0; i < length; i++) {
        if (s[i] == '(') {
            stack[++top] = i; // Push index of '(' onto the stack
        } else {
            if (top >= 0) {
                // Pop the matching '(' index from the stack
                top--;
                if (top >= 0) {
                    // Calculate the length of valid parentheses
                    maxLength = (maxLength > (i - stack[top])) ? maxLength : (i - stack[top]);
                } else {
                    // If stack is empty, calculate length from last invalid index
                    maxLength = (maxLength > (i - lastInvalidIndex)) ? maxLength : (i - lastInvalidIndex);
                }
            } else {
                // No matching '(', update last invalid index
                lastInvalidIndex = i;
            }
        }
    }

    free(stack); // Free the allocated memory for stack
    return maxLength;
}

int main() {
    // Test cases
    char s1[] = "(()";
    char s2[] = "(())";

    printf("Output 1: %d\n", longestValidParentheses(s1)); // Expected output: 2
    printf("Output 2: %d\n", longestValidParentheses(s2)); // Expected output: 4

    return 0;
}

