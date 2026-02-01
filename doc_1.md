# Q1 - balanced parentheses

used a stack for this. the idea is pretty simple, push opening brackets and when you hit a closing one pop from the stack and check if they match. if they dont, or the stack runs out early, its unbalanced.

## the stack

just a char array with an int `top` that starts at -1. push increments top and stores the char, pop just returns the top and decrements. isEmpty checks if top is -1.

## functions

- push, pop, isEmpty - standard stack operations nothing special
- isMatch - checks if an open and close bracket are a valid pair like ( ) or [ ] or { }
- isBalanced - goes through the string char by char. opening brackets get pushed. closing brackets cause a pop and then isMatch is called. returns 0 if stack is empty when we try to pop, or if brackets dont match. returns 1 only if stack is empty at the very end

## main

put the 3 expressions in an array and ran them through isBalanced in a loop, printed the result each time

## output

```
Expression: a + (b - c) * (d
Result: Not Balanced

Expression: m + [a - b * (c + d * {m)]
Result: Not Balanced

Expression: a + (b - c)
Result: Balanced
```
