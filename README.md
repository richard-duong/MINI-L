# CS152 Compiler Design Project
A project that parses and compiles source code written in the MINI-L Language <br>
by Stephanie Cabrera and Richard Duong

------------------------------------------------------------------------------
<br>

## Phase 1: Lexical Analysis
The goal of this phase is to tokenize source code written in the MINI-L language
<br>

### Lexer Goals
+ Learn and understand the workings of Flex
+ Determine a priority for same length tokens (e.g. identifiers & keywords)
+ Be able to identify and log errors from invalid tokens
+ Provide the column and character count for errors
+ Successfully output tokens from parsing the input into a file
+ Develop and run tests on weird boundary cases and conditions
+ Produce unit and integration tests

### Testing
+ Keywords
+ Operators
+ Special Symbols
+ Identifiers
+ Numbers
+ Comments
+ Errors

<br><br>

## Phase 2: Syntax Analysis
The goal of this phase is to ensure the tokenized source code can translate into a functional MINI-L program
<br>

### Bison Goals
+ Learn and understand the workings of Bison
+ Plan and design a grammar given the MINI-L syntax diagram
+ Resolve potential shift-reduce and reduce-reduce conflicts
+ Produce unit and integration tests

### Testing
+ Bare Minimum Program
+ Declarations
  + Variable declarations
  + Single identifier
  + Multi identifiers
  + Function declarations
+ Statements
  + If-Else
  + While Loops
  + Do While Loops
  + For Loops
  + Read
  + Write
  + Continue
  + Return
+ Expressions
  + Relational
  + Compound
  + Precedence of Operators


