// Bit Manipulation Revision Notes

// 1. Swapping Two Numbers (XOR)
int a = 5, b = 9;
a = a ^ b;
b = a ^ b;
a = a ^ b;
// => Swapped successfully
// Binary Example:
// a = 0000101, b = 0001001
// Step 1: a = 0001100
// Step 2: b = 0000101
// Step 3: a = 0001001

// ------------------------------------------------------------

// 2. Check if i-th Bit is Set
int num = 5, i = 2;
if ((num & (1 << i)) != 0)
    std::cout << "SET";
else
    std::cout << "NOT SET";
// 0000101 & 0000100 = 0000100 => SET

// ------------------------------------------------------------

// 3. Set i-th Bit
num = 5, i = 1;
num = num | (1 << i);
// 0000101 | 0000010 = 0000111 => Bit set

// ------------------------------------------------------------

// 4. Clear i-th Bit
num = 5, i = 2;
num = num & ~(1 << i);
// ~(0000100) = 1111011
// 0000101 & 1111011 = 0000001 => Bit cleared

// ------------------------------------------------------------

// 5. Toggle i-th Bit
num = 5, i = 2;
num = num ^ (1 << i);
// 0000101 ^ 0000100 = 0000001 => Bit toggled

// ------------------------------------------------------------

// 6. Remove Rightmost Set Bit
num = 5;
num = num & (num - 1);
// 0000101 & 0000100 = 0000100 => Rightmost set bit removed

// ------------------------------------------------------------

// 7. Check Power of 2
num = 5;
if ((num & (num - 1)) == 0)
    std::cout << "Power of 2";
else
    std::cout << "Not a power of 2";
// 0000101 & 0000100 = 0000100 => Not a power of 2

// ------------------------------------------------------------

// 8. Check Odd or Even
num = 5;
if ((num & 1) == 1)
    std::cout << "Odd";
else
    std::cout << "Even";

// num = 6
num = 6;
if ((num & 1) == 1)
    std::cout << "Odd";
else
    std::cout << "Even";
// 5 & 1 = 1 → Odd
// 6 & 1 = 0 → Even

// ------------------------------------------------------------

// 9. Divide Number by 2
num = 5;
int result = num >> 1;  // result = 2

// ------------------------------------------------------------

// 10. Count Set Bits (Loop)
int count = 0;
num = 5;
while (num != 0) {
    num = num & (num - 1); // removes last set bit
    count++;
}
// 5 → 0000101
// 4 → 0000100
// 3 → 0000011
// => 2 set bits

// ------------------------------------------------------------

// 11. Count Set Bits (Built-in)
num = 5;
int ans = __builtin_popcount(num);  // ans = 2

// ------------------------------------------------------------

// Tips:
// - &  => Check bit
// - |  => Set bit
// - ~  => Clear bit
// - ^  => Toggle bit
// - << => Multiply by 2
// - >> => Divide by 2 (Integer)

// ------------------------------------------------------------
