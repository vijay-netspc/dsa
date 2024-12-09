def hasRedundantBraces(expression):
    # Stack to store characters of the expression
    stack = []

    for char in expression:
        if char == ')':
            # Check for redundant braces
            top = stack.pop()
            has_operator = False

            # Check the contents inside the parentheses
            while top != '(':
                if top in '+-*/':
                    has_operator = True  # Found an operator
                top = stack.pop()

            # If no operator was found inside the parentheses, they are redundant
            if not has_operator:
                return 1
        else:
            # Push operators, operands, and open parentheses onto the stack
            stack.append(char)

    return 0  # No redundant braces found
