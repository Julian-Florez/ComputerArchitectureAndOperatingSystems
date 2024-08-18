## Workshop 1. Part One: Numbering Systems and Arithmetic Operations

**Objective**: To evaluate and reinforce knowledge in conversions between number systems, use of BCD and Gray codes, understanding of data structure (byte, nibble, word), and basic arithmetic operations with binary numbers, including two's complement.

### Decimal to Binary, Octal and Hexadecimal Conversion
- Implements a Python function that converts a decimal number to its binary, octal, and hexadecimal representations.

### Binary to Decimal Conversion
- Write a Python function that converts a binary number (as a string) to its decimal equivalent.

### Hexadecimal to Decimal and Binary Conversion
- Implements a function that converts a hexadecimal number (as a string) to its decimal and binary equivalent.

### Conversion to BCD Code
- Implements a function that converts a decimal number to its BCD code representation.

### Binary to Gray Code Conversion
- Write a Python function that converts a binary number to Gray Code.

### Data Structure Identification
- Implement a Python function that identifies whether a binary string corresponds to a nibble, byte, or word.

### Operation with Nibbles
- Implement a function that performs the binary addition of two nibbles and returns the result as a byte.

### Character to ASCII and EBCDIC Code Conversion
- Implement functions that convert one character to its ASCII code and another to its EBCDIC equivalent (you can use a fixed conversion table for EBCDIC).

### Sum of Binary Numbers
- Write a Python function that adds two binary numbers.

### Subtract with Two's Complement:

- Implement a function subtracting two binary numbers using the two's complement method.



## Workshop 1. Part Two: Number Systems in Different Bases

Imagine that you work at a technology company that has developed a new storage system that uses an unusual number base: **base 13**. Your task is to build software that can convert numbers between base 10 (decimal) and this new base 13, and perform additional conversions between other bases.

### 1. Digit Identification in Base 13 (1 point)
- Before performing the conversions, it is essential to understand how numbers are represented in base 13. In this system, the digits range from 0 to 9, and three additional symbols are added to represent the values 10, 11, and 12.
**Question**: What are the valid digits in a base 13 system? Describe how you would represent the numbers 10, 11, and 12 in this system.

### 2. Decimal to Base 13 Conversion (2 points):

- Implement a Python function that converts a base 10 number to its base 13 equivalent.
- **Exercise**: Convert the decimal number 255 to base 13. What is the representation of this number in base 13?

### 3. Base 13 to Decimal Conversion (2 points).
- Now, implement a function that converts a base 13 number to its base ten equivalent.
- **Exercise**: Convert the number 1A2 in base 13 to decimal. What is the value in base 10?

### Base 13 to Binary Conversion (2 points):

- Write a function that converts a base 13 number to its binary equivalent by first going through the conversion to base 10.
- **Exercise**: Convert the number B3 from base 13 to binary.


### Binary to Base 13 Conversion (2 points):
- Write a function that converts a binary number to its base 13 equivalent by first going through the conversion to base 10.
- **Exercise**: Convert the binary number 1101011 to base 13.

### Base 13 to Hexadecimal Conversion (1 point):

- Implement a function that converts a base 13 number to hexadecimal, using base 10 as an intermediate step.
- **Exercise**: Convert the number 9C from base 13 to hexadecimal.

### Application in Data Storage (2 points):

- Imagine that your company decides to store specific identifiers using base 13 because of its efficiency. If an identifier in base 10 is 3456, what would this identifier look like in base 13? 
- Also, convert this base 13 identifier to binary to show how it would be stored in a digital system.

**Exercise**: Perform the conversions and explain why using unconventional number bases in certain systems might be advantageous.