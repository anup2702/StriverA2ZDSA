# Bit Manipulation Notes (DSA Perspective)

## 📌 Introduction

Bit Manipulation is one of the most powerful techniques in Data Structures and Algorithms. It allows you to perform operations directly on bits — enabling extremely fast and memory-efficient solutions.

Mastering bitwise operations is essential for solving:

* Subset generation
* Dynamic Programming with bitmasks
* Bitwise tricks (XOR, AND, OR)
* Mathematical optimizations
* Pattern-based problems

---

# 📘 Basics of Bits

Every number is represented in **binary**. Bit Manipulation works on this binary form.

### Common terms:

* **Bit:** 0 or 1
* **LSB:** Least Significant Bit (rightmost)
* **MSB:** Most Significant Bit (leftmost)
* **Bitmask:** A pattern of bits used for masking operations

---

# 📘 Bitwise Operators

## 1. AND (`&`)

```
1 & 1 = 1
1 & 0 = 0
0 & 0 = 0
```

**Use cases:**

* Checking if a bit is set
* Clearing bits
* Filtering

## 2. OR (`|`)

```
1 | 0 = 1
0 | 0 = 0
```

**Use cases:**

* Setting bits
* Combining values

## 3. XOR (`^`)

```
1 ^ 1 = 0
1 ^ 0 = 1
```

**Use cases:**

* Finding unique numbers
* Toggling bits
* Swapping without temp variable

## 4. NOT (`~`)

Inverts bits.

## 5. Left Shift (`<<`)

Shifts bits to left → multiplies by 2.

## 6. Right Shift (`>>`)

Shifts bits right → divides by 2.

---

# 📘 Checking & Setting Bits

## ✔ Check if the i-th bit is set

```
if (n & (1 << i))
```

## ✔ Set the i-th bit

```
n |= (1 << i)
```

## ✔ Clear the i-th bit

```
n &= ~(1 << i)
```

## ✔ Toggle the i-th bit

```
n ^= (1 << i)
```

---

# 📘 Counting Bits

## ✔ Count number of set bits (1s)

### 1. Built-in

```
__builtin_popcount(n)
__builtin_popcountll(n)
```

### 2. Brian Kernighan’s Algorithm

```
while(n){
    n &= (n-1);
    count++;
}
```

Each iteration removes the last set bit.

---

# 📘 Common Bit Manipulation Tricks

## ✔ Check if number is power of 2

```
n > 0 && (n & (n-1)) == 0
```

## ✔ Swap two numbers without temp

```
a ^= b;
b ^= a;
a ^= b;
```

## ✔ Remove last set bit

```
n & (n-1)
```

## ✔ Get last set bit (LSB)

```
n & (-n)
```

## ✔ Turn off rightmost set bit

```
n & (n-1)
```

## ✔ Turn on rightmost unset bit

```
n | (n+1)
```

---

# 📘 Bitmasking

Used to represent subsets using bits.

## ✔ Generate all subsets

```
for (int mask = 0; mask < (1<<n); mask++){
    for(int i=0; i<n; i++){
        if(mask & (1<<i)) include element i;
    }
}
```

## ✔ Applications

* DP with bitmask
* Traveling Salesman Problem (TSP)
* Subset DP
* Strings & graphs problems

---

# 📘 XOR Properties (Important!)

```
x ^ 0 = x
x ^ x = 0
(a ^ b ^ a) = b
```

**Popular use:** find the unique element in array.

---

# 📘 Important Problems in DSA

## ✔ Single Number (LC 136)

Use XOR to find unique number.

## ✔ Power of Two (LC 231)

Use `n & (n-1)`.

## ✔ Subsets (LC 78)

Use bitmask from 0 → 2^n - 1.

## ✔ Counting Bits (LC 338)

DP using lowest set bit.

## ✔ Reverse Bits (LC 190)

Use shifting & masking.

## ✔ Bitwise AND of Range (LC 201)

Shift until both numbers equal.

## ✔ Find Two Missing Numbers

Use XOR partitioning.

---

# 📘 Advanced Concepts

## ✔ Trie of Bits (Binary Trie)

Used for:

* Maximum XOR Pair
* XOR Queries

## ✔ Gray Code

Sequence of bits where only one bit changes.

## ✔ Fenwick Tree (BIT)

Uses bit manipulation in index operations.

---

# 📘 Tips for Interviews

* Think in **binary**.
* Try **XOR** whenever you see words like *unique*, *odd number of times*.
* Use bitmasking for subsets.
* Use `n & (n-1)` for powers of two.
* Practice bitwise DP & bitmasks frequently.

---

# 📘 Summary Sheet

* Set bit → `n |= (1<<i)`
* Clear bit → `n &= ~(1<<i)`
* Toggle bit → `n ^= (1<<i)`
* Check bit → `n & (1<<i)`
* Count bits → `__builtin_popcount(n)`
* Last set bit → `n & -n`
* Remove last set bit → `n & (n-1)`
* Power of two → `n>0 && !(n&(n-1))`
* Generate subsets → `0 to (1<<n)-1`

---

# 🎯 Conclusion

Bit Manipulation is a core pillar of competitive programming and DSA. These techniques allow optimizations that are impossible using high-level arithmetic alone. Mastering these bit tricks will greatly improve your problem-solving ability.

Want separate notes on **Bitmask DP**, **XOR tricks**, or **Binary Trie**? Let me know!
