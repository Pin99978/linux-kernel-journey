# CSAPP Practice: Exercise 2.6 - Integer vs. Float Representation

This C code is a tool for exploring the concepts covered in Chapter 2 of "Computer Systems: A Programmer's Perspective" (CSAPP). The primary goal is to understand that a single bit pattern can represent vastly different numerical values depending on whether it is interpreted as an integer or a floating-point number.

## Core Concept: Bit-level Representation

In a computer's memory, everything is stored as a sequence of bits. The meaning of a bit sequence is determined by the context and the data type used to interpret it.

-   **Integers:** Typically represented using the **Two's Complement** encoding. This is a straightforward binary representation for both positive and negative numbers.

-   **Floating-Point Numbers:** Represented using the **IEEE 754 standard**. A 32-bit float is divided into three parts:
    1.  **Sign (1 bit):** Determines if the number is positive or negative.
    2.  **Exponent (8 bits):** Represents the scale or magnitude of the number.
    3.  **Fraction/Mantissa (23 bits):** Represents the precision or significant digits.

Because these two systems are fundamentally different, the same 32-bit pattern will be interpreted as two completely different numbers.

## About This Code

This program provides a `print_binary` function to visualize the 32-bit pattern of a given number. It also includes the `show_bytes` family of functions to inspect the raw byte values in hexadecimal.

### How to Explore the Concept

The current `main` function in the file initializes an integer and a float with separate values. To truly see the core concept in action, you should investigate how the **exact same bit pattern** is interpreted differently.

You can modify your `main` function to do this. For example:

```c
int main() {
    // An integer holding a specific 32-bit pattern.
    int int_val = 0x4A1F23E0;

    // A pointer to interpret the same bit pattern as a float.
    float float_val = *(float *)&int_val;

    printf("Original hex: 0x%X\n\n", int_val);

    printf("Interpreted as an integer:\n");
    printf("Binary: ");
    print_binary(int_val);
    printf("Decimal: %d\n\n", int_val);

    printf("Interpreted as a float:\n");
    printf("Binary: ");
    print_binary(int_val); // Print the same bits
    printf("Decimal: %f\n", float_val);

    return 0;
}
```

**To Use:**

1.  **Compile the code:**
    ```bash
    gcc -o main 2.6_matchbytewithintandfloat.c
    ```
2.  **Run the executable:**
    ```bash
    ./main
    ```
3.  **Analyze the Output:**
    When you run the modified code, you will see that the integer `0x4A1F23E0` corresponds to the decimal value `1243550688`, while the exact same bit pattern, when interpreted as a float, represents the value `255.155991`.
