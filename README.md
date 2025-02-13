# Run-Length Encoding (RLE), Huffman Encoding, and Shannon-Fano Encoding

This repository contains implementations of three well-known encoding algorithms: Run-Length Encoding (RLE), Huffman Encoding, and Shannon-Fano Encoding. Each algorithm processes an input sequence and generates a compressed representation based on its unique encoding logic.

---

## **Run-Length Encoding (RLE)**
### **Overview**
Run-Length Encoding (RLE) is a simple lossless data compression technique that replaces consecutive occurrences of the same character with a single instance of that character followed by its count.

### **Encoding Logic**
1. Iterate through the input sequence and identify consecutive occurrences of characters.
2. Store unique characters along with their respective frequencies.
3. Construct the encoded sequence by appending each unique character followed by its occurrence count.

### **Example**
**Input:** `AAABBBCCDAA`  
**Output:** `A3B3C2D1A2`

### **Code Execution**
```bash
$ g++ rle.cpp -o rle
$ ./rle
Enter the sequence to be encoded: AAABBBCCDAA
Character frequencies:
A: 3
B: 3
C: 2
D: 1
A: 2
Code:
A3B3C2D1A2
```

---

## **Huffman Encoding**
### **Overview**
Huffman Encoding is a variable-length encoding algorithm that assigns shorter binary codes to more frequent characters and longer codes to less frequent characters.

### **Encoding Logic**
1. Count the frequency of each unique character in the input sequence.
2. Sort characters by descending frequency.
3. Assign binary codes starting from `0` and incrementing in a systematic manner.
4. Construct the encoded sequence using the generated binary codes.

### **Example**
**Input:** `ABABACD`  
**Output (Binary Codes):**
```
A: 0
B: 10
C: 110
D: 111
```
**Encoded Sequence:** `0100100110111`

### **Code Execution**
```bash
$ g++ huffman_encoding.cpp -o he
$ ./he
Enter the sequence to be encoded: ABABACD
Character frequencies:
A: 3
B: 2
C: 1
D: 1
Unique characters sorted by frequency (descending): A B C D
Code:
0100100110111
```

---

## **Shannon-Fano Encoding**
### **Overview**
Shannon-Fano Encoding is another variable-length encoding method based on character frequency, where the character set is split recursively into two parts of approximately equal total probability.

### **Encoding Logic**
1. Count the frequency of each unique character.
2. Sort characters by descending frequency.
3. Recursively split the sorted list into two halves of nearly equal total frequency.
4. Assign binary codes (`0` to the first half, `1` to the second half) and continue recursively.
5. Construct the encoded sequence using the generated binary codes.

### **Example**
**Input:** `ABABACD`  
**Output (Binary Codes):**
```
A: 0
B: 10
C: 110
D: 111
```
**Encoded Sequence:** `0100100110111`

### **Code Execution**
```bash
$ g++ shannon_encoding.cpp -o se
$ ./e
Enter the sequence to be encoded: ABABACD
Character frequencies:
A: 3
B: 2
C: 1
D: 1
Unique characters sorted by frequency (descending): A B C D
Code:
0100100110111
```

---

## **How to Run the Code**
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/encoding-algorithms.git
   cd encoding-algorithms
   ```
2. Compile the desired encoding program:
   ```bash
   g++ <algorithm>.cpp -o <algorithm>
   ```
   Replace `<algorithm>` with `rle`, `huffman`, or `shannon`.
3. Run the compiled program:
   ```bash
   ./<algorithm>
   ```
4. Enter the sequence to be encoded and observe the output.
## **Debugging using gdb**
### **Typical layout**
1. In the terminal enter command: g++ -g program.cpp -o program
2. gdb program
3. file program
4. set break point at a particular line(eg: break 12) or at a function(eg: break func_name)
5. then continue with pressing 's' to go through each step in the function,and use 'n' to skip out of a function
---

## **Conclusion**
This project demonstrates the implementation of RLE, Huffman, and Shannon-Fano encoding techniques, each with its unique approach to data compression. These algorithms can be useful in reducing data storage and transmission costs in various applications.

