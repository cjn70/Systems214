# Systems214Asst0
Abstract
    Of all the tasks you will need to complete in time or behaviors to encode, scanning and parsing tend to crop up over and over again in some form. When scanning you take a sequence of characters and break them in to tokens and when parsing you evaluate the tokens based on some rule set in order to determine if they are not only used correctly, but also what computations they represent. In this assignment you'll get some practice with C by scanning and doing some simple parsing. This should also give you some insight in to interpreting what the C compiler tells you when it finds problems.

    
    
Introduction    
    The language you are working with consists of two kinds of operators: logical and arithmetic. The logical operators are: {AND, OR, NOT} and are applied to the values: {true, false}. The arithmetic operators are: {-, +, *, /} and are applied to the values: {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}.

    You'll receive all your tokens in a single command line argument, and your code should take exactly one argument. You can count on whitespace (e.g. ' ') to divide tokens, however it may behoove you to make your delimiter parameterizable for future use. The null terminator ('\0') will end your input and the line you are evaluating.
    
    Once you have detected all the tokens, you next should make sure the tokens make sense. This language is an infix language, meaning all binary operators appear between their operands:
        Legal expressions:        Illegal expressions:
        1 + 2                               1 +2
        4 - 9                                4 -
        true AND false                True AND false
        false OR true                  fals OR 1
