Algorithm Infix_Postfix(String iexp)
// Initialize stack S
Begin
    pos1 = 0; pos2 = 0;

    while (iexp(pos1) != NULL) do
        if (iexp(pos1) is an operand) // Operand
            pexp(pos2) = iexp(pos1)
            pos2 = pos2 + 1
        else if (iexp(pos1) == '(') // Open parenthesis
            push(S, iexp(pos1))
        else if (iexp(pos1) == ')') // Closed parenthesis
            while (peek(S) != '(') do
                pexp(pos2) = pop(S)
                pos2 = pos2 + 1
            end while
            pop(S) // Remove the open parenthesis
        else // Operator
            if (is_empty(S) or precedence(peek(S)) < precedence(iexp(pos1)))
                push(S, iexp(pos1))
            else
                while (!is_empty(S) and precedence(peek(S)) >= precedence(iexp(pos1))) do
                    pexp(pos2) = pop(S)
                    pos2 = pos2 + 1
                end while
                push(S, iexp(pos1)) // Push the current operator onto the stack
            end if
        end if
        pos1 = pos1 + 1
    end while

    // Pop all remaining operators from the stack
    while (!is_empty(S)) do
        pexp(pos2) = pop(S)
        pos2 = pos2 + 1
    end while

    pexp(pos2) = NULL // Null-terminate the postfix expression
End
