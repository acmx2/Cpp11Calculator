Cpp11Calculator
===============

Recursive descent calculator in C++11 (CalculatorEx)

The CalculatorEx is a proof of concept for an extensible calculator written on C++11. Well known 'recursive descent' method is used.

Input data is a console expression like the following: 45 +676446- (43 -3 +3) +78+12-(-(7+5))= 
Note, trailing '=' is required. Output data is a resulting number or a diagnostics message printed onto the console.

Note, since it's a proof of concept only, it for sure has some errors and may sometimes be unpredictable. Also, some its features could be coded more elegantly in C++11, however it's coded 'as is' just to start from something.

The CalculatorEx evaluates the input expression left to right by 'digging' syntax tree via the recursive calls (thus, the available input expression tree height is limited by the C++ call stack size). 

