# Q2 - infix to postfix + evaluation

two separate stacks here, one for operators during conversion and one for numbers during evaluation. conversion uses the shunting yard algorithm basically.

## stacks

`cstack` is a char array for operators, `nstack` is a double array for the numbers when evaluating. both have their own push/pop functions so they dont interfere.

## functions

- cpush cpop cpeek cisEmpty - operator stack ops
- npush npop - number stack ops
- precedence - returns a number for operator priority. + and - are 1, * and / are 2, ^ is 3
- isOperator - just checks if a char is one of the 5 operators
- infixToPostfix - loops through the input. digits go straight to output. ( gets pushed. ) causes popping until we hit the matching (. operators get pushed but first we pop anything with higher or equal precedence. whatever's left on the stack at the end gets popped to output
- evaluate - reads the postfix string. digits get pushed as numbers. when we hit an operator we pop two numbers, do the operation, push the result back

## main

asks user for an infix expression (single digit numbers only, limitation of the current impl), converts it, prints postfix, evaluates and prints the answer

## output

```
Enter infix expression (single digit numbers only): (3+5)*2
Postfix: 3 5 + 2 * 
Result: 16.00
```
