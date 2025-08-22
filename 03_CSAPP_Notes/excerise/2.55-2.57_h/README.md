# CSAPP Practice: Exercises 2.55 - 2.57

This C code is a hands-on exercise for understanding the concepts covered in Chapter 2 of "Computer Systems: A Programmer's Perspective" (CSAPP), specifically focusing on exercises 2.55, 2.56, and 2.57.

The primary goal of these exercises is to visualize and understand how different data types are represented at the byte level in memory.

## Core Concepts

### 1. Data Representation
This program demonstrates how fundamental C data types are stored in memory. By printing the sequence of bytes for types like `int`, `float`, `short`, `long`, `double`, and even pointers, you can observe their raw byte patterns.

### 2. Endianness (Byte Order)
The order in which bytes are arranged in memory for multi-byte data types is known as **endianness**.
- **Little-Endian:** The least significant byte is stored at the lowest memory address.
- **Big-Endian:** The most significant byte is stored at the lowest memory address.

This program, particularly the `show_bytes` function, is a practical tool to determine the endianness of any machine you compile and run it on. For example, if you run `show_int(1)` on a little-endian machine, it will print `01 00 00 00`, while a big-endian machine would print `00 00 00 01`.

### 3. Type Casting and Representation
The `test_value` function illustrates a crucial concept: casting a value from one type to another (e.g., `(float)ival`) can dramatically change its underlying byte representation. An integer and a floating-point number that represent the same numerical value have completely different byte patterns according to IEEE 754 floating-point standards.

