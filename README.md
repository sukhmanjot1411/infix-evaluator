# infix-evaluator

Infix to Postfix Conversion and Evaluation

**Overview:**

This program converts an infix expression (mathematical expression with operators between operands) to a postfix expression (Reverse Polish Notation) and evaluates the resulting postfix expression.

**Features**

1) Converts infix expressions to postfix notation

2) Supports basic arithmetic operators: +, -, *, /, ^

3) Handles operator precedence and associativity

4) Evaluates the postfix expression to compute the result

**Implementation Details**

**Stack Implementation**

1) A custom Stack class is used to manage operators during conversion.

2) It supports operations like push, pop, and peek.

**Infix to Postfix Conversion**

1) Operands are directly added to the postfix expression.

2) Operators are pushed onto the stack based on precedence.

3) Parentheses are handled to enforce correct order of operations.

**Postfix Evaluation**

1) Uses a standard stack-based approach.

2) Operands are pushed onto the stack.

3) Operators pop operands, perform the operation, and push the result
