#include <stdio.h>
#include <string.h>

// Function to find the longest valid parentheses substring
int longestValidParentheses(char *s) {
    int maxLength = 0; // To store the maximum length
    int n = strlen(s);
    
    // Stack to store indices
    int stack[n + 1];
    int top = -1; // Initialize stack as empty

    // Push -1 onto the stack as a base for the first valid substring
    stack[++top] = -1;

    // Traverse the string
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            // Push the index of the open parenthesis
            stack[++top] = i;
        } else {
            // Pop the top of the stack
            top--;

            if (top == -1) {
                // If the stack is empty, push the current index
                stack[++top] = i;
            } else {
                // Calculate the length of the current valid substring
                int length = i - stack[top];
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }

    return maxLength;
}

// Driver code
int main() {
    char s1[] = "(()))())("; // Example input
    printf("Longest valid parentheses length: %d\n", longestValidParentheses(s1));

    char s2[] = "((()))";
    printf("Longest valid parentheses length: %d\n", longestValidParentheses(s2));

    return 0;
}
