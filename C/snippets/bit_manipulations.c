#include <stdio.h>
#include <stdbool.h>
// Will comeback to this Later, I just wrote implementations for some.

/*
•   Check if the k‑th bit is set — Given an integer and a bit position, determine if that bit is  or .
• 	Set the k‑th bit of a number — Modify the number so that the specified bit becomes .
• 	Clear the k‑th bit of a number — Modify the number so that the specified bit becomes .
• 	Toggle the k‑th bit of a number — Flip the specified bit from  to  or vice versa.
• 	Turn off the rightmost set bit — Remove the lowest  bit from a number.
• 	Get the rightmost set bit — Extract the lowest  bit as a separate value.
• 	Count trailing zeros — Determine how many zeros appear at the end of the binary representation.
• 	Reverse the bits of a 32‑bit integer — Produce a number whose bits are in the opposite order.
• 	Compute XOR of all numbers from 1 to N — Use XOR patterns to compute the result efficiently.
• 	Find the missing number in 1..N — Given N−1 numbers, find the missing one using XOR.
• 	Find the element that appears once when others appear thrice — Identify the unique element when all others appear exactly three times. • 	Add two integers without using + or - — Use bitwise operations to simulate addition.
• 	Multiply two integers using bit operations only — Implement multiplication using shifts and adds.
• 	Divide two integers using bit operations only — Implement division using shifts and subtraction logic.
• 	Rotate bits left or right — Perform circular bit rotation on an integer.
• 	Check if two integers have opposite signs — Use bitwise operations to detect sign differences.
• 	Find parity of a number — Determine whether the count of set bits is even or odd.
• 	Generate all subsets of a set using bitmasks — Use bit patterns to represent subset inclusion.
• 	Find the next higher number with the same number of set bits — Compute the next permutation of bits.
• 	Merge two numbers between bit positions i and j — Replace bits i..j of one number with bits from another.

🔍 More Advanced or Niche Problems
• 	Implement a bitset data structure — Support operations like set, clear, toggle, and test.
• 	Detect overflow in integer addition using bits — Determine if adding two integers would overflow.
• 	Compute absolute value without branching — Use bitwise operations to remove conditional logic.
• 	Sign extend a number from n bits — Convert an n‑bit signed value to a full integer.
• 	Pack multiple small integers into a single 32‑bit value — Use bit fields to store compact data.
• 	Extract fields from a packed integer — Retrieve specific bit ranges.
• 	Simulate a simple CPU instruction using bit operations — Implement AND, OR, XOR, NOT, shifts, etc.
• 	Implement a fast exponentiation using bit decomposition — Use binary exponentiation logic.
• 	Find the longest sequence of 1s after flipping one bit — Compute the maximum run of 1s with one allowed flip.
• 	Compute Hamming distance between two integers — Count differing bits.
• 	Find the position of the only set bit — Given a number with exactly one set bit, return its index.
• 	Check if a number is sparse — Ensure no two adjacent bits are set.
• 	Convert an integer to Gray code — Apply the Gray code transformation.
• 	Convert Gray code back to binary — Reverse the transformation.
• 	Simulate bitwise operations using only arithmetic — Recreate AND/OR/XOR using +, -, and *.
*/


// 1. Find the number of set bits in an integer

int find_set_bits(int number){
    int n = number; 
    int count = 0;
    while(n){
        n = n & (n-1);
        // It will remove the rightmost set bit.
        count++; 
    }
    return count;
}

// 2. Check if a number is a power of two
bool is_power_of_2(int n){
    int last_bit = n & 0x01;
    if(last_bit)
    {
        return false;             
    }
    else{ return true;}
}

// 3. Swap two numbers without using a temporary variable 
void swap(int* a, int* b){
    // use XOR
    *a = *a ^ *b; // a now holds the result of a XOR b
    *b = *a ^ *b; // b now holds the original value of a
    *a = *a ^ *b; // a now holds the original value of b
}

// 4. Find the only non-repeating element in an array where every other element repeats twice
int find_non_repeating(int arr[], int size){
    int result = 0;
    for(int i = 0; i < size; i++){
        result = result ^ arr[i]; // XOR will cancel out the repeating elements
                                  // how does this work
    // For example, if we have an array [2, 3, 2, 4, 3], the XOR operation will work as follows:
    // result = 0 ^ 2 ^ 3 ^ 2 ^ 4 ^ 3
    // = (0 ^ 2) ^ 3 ^ 2 ^ 4 ^ 3
    // = 2 ^ 3 ^ 2 ^ 4 ^ 3
    // = (2 ^ 2) ^ 3 ^ 4 ^ 3
    // = 0 ^ 3 ^ 4 ^ 3
    // = (3 ^ 3) ^ 4
    // = 0 ^ 4
    // = 4
    //
    //
    // XOR properties to remember
    // 1. a ^ a = 0 (XOR of a number with itself is 0)
    // 2. a ^ 0 = a (XOR of a number with 0 is the number itself)
    // 3. XOR is commutative and associative, meaning the order of operations does not matter.
    //
    }
    return result; // The remaining value will be the non-repeating element
}


// 5. Find the only repeating element in an array where every other element is unique

int find_repeating(int arr[], int size){
    
// int arr[] = { 2,3,5,2};
// The XOR operation will work as follows:
// result = 0 ^ 2 ^ 3 ^ 5 ^ 2
// = (0 ^ 2) ^ 3 ^ 5 ^ 2
// = 2 ^ 3 ^ 5 ^ 2
// = (2 ^ 2) ^ 3 ^ 5
// = 0 ^ 3 ^ 5
// = 3 ^ 5
// = 6 (which is not the repeating element, but we can use this result to find the repeating element)
// We can use the result of the XOR operation to find the repeating element by XORing it with each element in the array again. 
// The repeating element will be the one that cancels out the result.
// For example, if we take the result (6) and XOR it with each element in the array:
// 6 ^ 2 = 4
// 4 ^ 3 = 7
// 7 ^ 5 = 2
// 2 ^ 2 = 0
// The final result will be 0, which means that the repeating element is 2.
// This approach works because the XOR operation will cancel out all the unique elements,
// leaving only the repeating element.

int result = 0;
for(int i = 0; i < size; i++){
   result = result ^ arr[i];
   // So you just find the result of the entire array XORed together, and then you XOR that result with each element in the array again.
}
for(int i = 0; i < size; i++){
    result = result ^ arr[i];
    if(result == 0){
        return arr[i]; // The repeating element will be the one that cancels out the result.
    }
}
return -1; // If there is no repeating element, return -1 or some indicator value.

}



// 6. Check if the k‑th bit is set — Given an integer and a bit position, determine if that bit is 1 or 0.
bool check_k_th_bit(int number, int k){
    // K is kth bit.
    int result = number & (0x1 << k);
    if(result) return true;
    return false;
}

// 7. Set the k‑th bit of a number — Modify the number so that the specified bit becomes 1.
void set_k_th_bit(int* number, int k){
    *number = *number | (0x1 << k);
}



// 	8. Clear the k‑th bit of a number — Modify the number so that the specified bit becomes 0.
int* clear_kth_bit(int *number, int k){
    // clearin the kth bit of a number. 
    // Create a mask = ~(0x1 << k) and then AND it with the number. SO ,it is like 111110111 if k = 3, and then AND it with the number to clear the kth bit.
    *number = *number & ~(0x1 << k);  
    return number;
}


// 9. Toggle the k‑th bit of a number — Flip the specified bit from  to  or vice versa.
int * togle_kth_bit(int *number, int k){
// Toggling the kth bit.
    *number = *number ^ (0x1 << k); // Basially good for bit negation, if the bit is 1, it will become 0, and if it is 0, it will become 1.
    return number;
}


// 10. Turn off the rightmost set bit — Remove the lowest set  bit from a number.
int turn_off_rightmost_set_bit(int number){
    return number & (number - 1); // This will turn off the rightmost set bit. Basically will remove the lowest set bit from the number. For example, if we have a number 6 (110 in binary), the rightmost set bit is the 2nd bit (from the right). When we subtract 1 from 6, we get 5 (101 in binary). When we AND 6 and 5, we get 4 (100 in binary), which is the result of turning off the rightmost set bit.
}


// 11. Get the rightmost set bit — Extract the lowest  bit as a separate value.
int get_rightmost_set_bit(int number){
    return number & (-number); 
    // This will return the rightmost set bit as a separate value. 
    // For example, if we have a number 6 (110 in binary), the rightmost set bit is the 2nd bit (from the right). 
    // When we negate 6, we get -6 (which is represented in two's complement as 11111111111111111111111111111010 in binary). 
    // How is -6 represented in binary? In two's complement, to get the negative of a number, we invert the bits and add 1. 
    // So, for 6 (00000000000000000000000000000110 in binary), 
    // we invert the bits to get 11111111111111111111111111111001,
    // and then we add 1 to get 11111111111111111111111111111010, which is -6 in two's complement.
    //
    //
    //By looking at a bit sequence how do we know if it is negative or positive? If the leftmost bit (most significant bit) is 1, then the number is negative. If the leftmost bit is 0, then the number is positive. In the case of -6, the leftmost bit is 1, which indicates that it is a negative number.
    // How do I know that it is -6, by looking at 11111111111111111111111111111010?
    // We can calculate the value of this binary number by using the two's complement method. 
    // To get the value of a negative number in two's complement, we can invert the bits and add 1. 
    // So, if we take 11111111111111111111111111111010 and invert the bits, we get 00000000000000000000000000000101. 
    // Then, we add 1 to get 00000000000000000000000000000110, which is 6 in decimal.
    // Since the original number had a leftmost bit of 1, it is negative, so the value is -6.
    //
    // When we AND 6 and -6, we get 2 (10 in binary), which is the rightmost set bit.
    //
    // We can also do this
    return number & ~(number - 1) ;  
    // For example, if we have a number 6 (110 in binary), the rightmost set bit is the 2nd bit (from the right). 
    // When we subtract 1 from 6, we get 5 (101 in binary). 
    // When we negate 5, we get -5 (which is represented in two's complement as 11111111111111111111111111111011 in binary).
    // When we AND 6 and -5, we get 2 (10 in binary), which is the rightmost set bit.
}



//12. Count trailing zeros — Determine how many zeros appear at the end of the binary representation.
int count_trailing_zeros(int number){
    int count = 0;
    while((number & 0x1) == 0 && number != 0){
        count++;
        number = number >> 1; // Right shift the number to check the next bit.
    }
    return count;
}



// 13. Reverse the bits of a 32‑bit integer — Produce a number whose bits are in the opposite order.
int reverse_bits(int number){
    int result = 0;
    for(int i = 0; i < 32; i++){
        result = result << 1;
        result = result | (number & 0x1); 
        // Basically OR between 0 and the rightmost bit of the number. 
        // This will add the rightmost bit of the number to the result.
        // Get the rightmost bit of the number and add it to the result.
        number = number >> 1; // Right shift the number to check the next bit.
        // So, for example, if we have a number 6 (110 in binary), the reverse of the bits would be 011 in binary, which is 3 in decimal.
        // The process works as follows:
        // 1. Start with result = 0 and number = 6 (110 in binary).
        // 2. For the first iteration (i = 0):
        //   - result = result << 1; // result is still 0 (000 in binary).
        //   - result = result | (number & 0x1); // number & 0x1 gives us the rightmost bit of number, 
        //     which is 0. So result remains 0 (000 in binary).
        //  - number = number >> 1; // Right shift number to get 3 (11 in binary).
        //  3. For the second iteration (i = 1):
        //  - result = result << 1; // result is still 0 (000 in binary).
        //  - result = result | (number & 0x1); // number & 0x1 gives us the rightmost bit of number,
        //   which is 1. So result becomes 1 (001 in binary).
        //   number = number >> 1; // Right shift number to get 1 (1 in binary).
        //   4. For the third iteration (i = 2):
        //   - result = result << 1; // result becomes 2 (010 in binary).
        //   - result = result | (number & 0x1); // number & 0x1 gives us the rightmost bit of number,
        //   which is 1. So result becomes 3 (011 in binary).
        //   number = number >> 1; // Right shift number to get 0 (0 in binary).
        //   5. For the remaining iterations (i = 3 to 31), 
        //   result will be left shifted and ORed with 0 (since number is now 0), so result will remain 3 (011 in binary).

    }
    return result;
}


// 14. Compute XOR of all numbers from 1 to N — Use XOR patterns to compute the result efficiently.
int compute_xor_1_to_n(int n){
    // The XOR of all numbers from 1 to N can be computed using the following pattern:
    // If n % 4 == 0, then the result is n.
    // If n % 4 == 1, then the result is 1.
    // If n % 4 == 2, then the result is n + 1.
    // If n % 4 == 3, then the result is 0.
    // Proof: 
    // 1. For n = 1, XOR(1) = 1, which matches the pattern (n % 4 == 1).
    // 2. For n = 2, XOR(1, 2) = 1 ^ 2 = 3, which matches the pattern (n % 4 == 2).
    // 3. For n = 3, XOR(1, 2, 3) = 1 ^ 2 ^ 3 = 0, which matches the pattern (n % 4 == 3).
    // 4. For n = 4, XOR(1, 2, 3, 4) = 1 ^ 2 ^ 3 ^ 4 = 4, which matches the pattern (n % 4 == 0).
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0;
}



// 15. Add two integers without using + or - — Use bitwise operations to simulate addition.
int add(int a, int b){
    while(b != 0){
        int carry = a & b; // Calculate the carry
        // Basically, wherever 1+1 happens, we will have a carry. 
        // So, we can use AND operation to find out where the carry will happen.
        a = a ^ b; // Sum of bits of a and b where at least one of the bits is not set. Why XOR tho?
        // XOR will give us the sum of bits where at least one of the bits is not set.
        // For example, if we have a = 5 (101 in binary) and b = 3 (011 in binary), the addition would work as follows:
        // 1. Calculate the carry: carry = a & b = 101 & 011 = 001 (which is 1 in decimal).
        // 2. Calculate the sum without carry: a = a ^ b = 101 ^ 011 = 110 (which is 6 in decimal).
        // 3. Shift the carry to the left: b = carry << 1 = 001 << 1 = 010 (which is 2 in decimal).
        // 4. Now we have a = 6 and b = 2, we repeat the process:
        //   - Calculate the carry: carry = a & b = 110 & 010 = 010 (which is 2 in decimal).
        //   - Calculate the sum without carry: a = a ^ b = 110 ^ 010 = 100 (which is 4 in decimal).
        //   - Shift the carry to the left: b = carry << 1 = 010 << 1 = 100 (which is 4 in decimal).
        //   Now we have a = 4 and b = 4, we repeat the process:
        //   - Calculate the carry: carry = a & b = 100 & 100 = 100 (which is 4 in decimal).
        //   - Calculate the sum without carry: a = a ^ b = 100 ^ 100 = 000 (which is 0 in decimal).
        //   - Shift the carry to the left: b = carry << 1 = 100 << 1 = 1000 (which is 8 in decimal).
        //   Now we have a = 0 and b = 8, we repeat the process:
        //   - Calculate the carry: carry = a & b = 000 & 1000 = 000 (which is 0 in decimal).
        //   - Calculate the sum without carry: a = a ^ b = 000 ^ 1000 = 1000 (which is 8 in decimal).
        //   - Shift the carry to the left: b = carry << 1 = 000 << 1 = 000 (which is 0 in decimal).
        //   Now we have a = 8 and b = 0, we stop the process and return a, which is 8.
        b = carry << 1; // Carry is shifted by one so that it can be added to a in the next iteration
    }
    // Pretty genius, right? 
    return a;
}



// 16.Check if two integers have opposite signs — Use bitwise operations to detect sign differences.

int have_opposite_signs(int a, int b){
    // If a and b have opposite signs, then the sign bit of a XOR b will be 1. 
    // The sign bit is the leftmost bit in the binary representation of a number. 
    // If the sign bit is 1, then the number is negative, and if it is 0, then the number is positive.
    return (a ^ b) < 0; // If the result of a XOR b is negative, then a and b have opposite signs.
}
// beutiful, right?


// 17. Find parity of a number — Determine whether the count of set bits is even or odd.

int find_parity(int n){
    // Is this right?
    int count = 0;
    while( n!=0){
    n = n & (n-1); // Remove the rightmost set bit
    count++;
    }
    if(count % 2 == 0) {
        return 0;
    }
    else{ 
        return 1;
    }
    // Basically checking if count is a multiple of 2 .
    // Return 1 if odd, 0 if even.
}


// 18. Detect overflow in integer addition using bits — Determine if adding two integers would overflow.

bool detect_overflow(int a, int b){
    // If a and b have the same sign and the result of a + b has a different sign, then there is an overflow.
    int sum = a + b;
    return ((a > 0 && b > 0 && sum < 0) || (a < 0 && b < 0 && sum > 0));
}
// Pretty simple, right? We just check if a and b have the same sign and if the sum has a different sign. 
// If both conditions are true, then there is an overflow.





int main() {

int number = 7;
int set_bits = find_set_bits(number);
printf("The number of set bits in %d, is %d \n",number, set_bits); 
int number2 = 4;
bool is_it_true_power_of_2 = is_power_of_2(number2);
bool is_it_true_power_of_2_another_one = is_power_of_2(number);
printf("%d is a power of 2? : %d\n" , number2, is_it_true_power_of_2);
printf("%d is a power of 2? : %d\n" , number, is_it_true_power_of_2_another_one);

printf("The numbers before swapping: a = %d, b = %d\n", number, number2);
swap(&number, &number2);
printf("The numbers after swapping: a = %d, b = %d\n", number, number2);

printf("Finding the non-repeating element in the array [2, 3, 2, 4, 3]:\n");
int arr[] = {2, 3, 2, 4, 3};
int size = sizeof(arr) / sizeof(arr[0]);
int non_repeating = find_non_repeating(arr, size);
printf("The non-repeating element is: %d\n", non_repeating);
printf("Finding the repeating element in the array [2, 3, 5, 2]:\n");
int arr2[] = { 2,3,5,2};
int size2 = sizeof(arr2) / sizeof(arr2[0]);
int only_repeating = find_repeating(arr2, size2);
printf("The repeating element is: %d\n", only_repeating);

printf("Checking if the 3rd bit of %d from the right is set: %d \n", number, check_k_th_bit(number, 2));


int hex_number = 0x3; // 3 in decimal

printf("Before setting the 3rd bit of %d from the right: %x\n", hex_number, hex_number);

printf("Setting the 3rd bit of %d from the right: \n", hex_number);
set_k_th_bit(&hex_number, 2);
printf("After setting the 3rd bit of %d from the right: %x\n", hex_number, hex_number);


printf("Clearing the 3rd bit of %d from the right: \n", hex_number);
clear_kth_bit(&hex_number, 2);
printf("After clearing the 3rd bit of %d from the right: %x\n", hex_number, hex_number);



int hex_number2 = 0x5; // 5 in decimal
printf("Before toggling the 3rd bit of %d from the right: %x\n", hex_number2, hex_number2);
printf("Toggling the 3rd bit of %d from the right: \n", hex_number2);
togle_kth_bit(&hex_number2, 2);
printf("After toggling the 3rd bit of %d from the right: %x\n", hex_number2, hex_number2);



printf("Turning off the rightmost set bit of %d: %d\n", hex_number2, turn_off_rightmost_set_bit(hex_number2));




// Findin parity
printf("The parity of %d is: %d\n", number, find_parity(number));
printf("The parity of 6 is: %d\n", find_parity(6));

return 0;

}

