Begin
    int pos = 0; // Initialize position pointer
    bool balanced = true; // A flag to indicate if the expression is balanced

    while (exp(pos) != NULL) do
        if (exp(pos) == '(') // If an open parenthesis is found
            push(S, pos) // Push its position onto the stack
        elseif (exp(pos) == ')') // If a closing parenthesis is found
            if (is_empty(S)) // No matching open parenthesis in the stack
                print("Extra close brace at position " + (pos + 1))
                balanced = false // Mark the expression as unbalanced
            else
                pop(S) // Remove the matching open parenthesis from the stack
            end if
        end if
        pos = pos + 1 // Move to the next character
    end while

    // Check remaining unmatched open parentheses
    if (!is_empty(S)) // If stack is not empty, there are unmatched open parentheses
        balanced = false // Mark the expression as unbalanced
        while (!is_empty(S)) do
            pos = pop(S)
            print("Extra open brace at position " + (pos + 1))
        end while
    end if

    // Final output
    if (balanced)
        print("Balanced")
    else
        print("Unbalanced")
End
