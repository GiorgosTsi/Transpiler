# Lambda Transpiler
---
## Project Description

The Lambda Transpiler is a tool designed to convert programs written in the Lambda programming language into C code. This allows developers to write high-level, structured code in Lambda and then compile it to efficient, low-level C code for execution.

This is a project made for **Computation Theory** 2024 Course in Technical University of Crete. 
## Features

- **Struct Definition**: Define complex data structures (comps) with various fields and methods.
- **Statements** : Define all the known statements (if-else , loops ..)
- **Comprehensions** : Define array comprehensions.
- **Expressions** : Define all type of expressions.
- **Transpiling to C**: Convert Lambda code to C code, making it possible to compile and run the code on any platform that supports C.

## Build


1. **Build the Transpiler**

    ```bash
    bash ./script.sh
    ```
    Make sure you have all the dependencies(flex , bison , gcc).

## Usage

1. **Write Lambda Code**

    Write your Lambda code in a `.la` file.Examples are given inside the project.


2. **Transpile to C**

    Use the Lambda Transpiler to convert your `.la` file to a C file.

    ```bash
    ./mycomp < input.lambda > output.c
    ```

3. **Compile the C Code**

    Compile the generated C code using a C compiler.

    ```bash
    gcc -std=c99 -Wall output.c
    ```

4. **Run the Program**

    Run the compiled program.

    ```bash
    ./a.out
    ```
