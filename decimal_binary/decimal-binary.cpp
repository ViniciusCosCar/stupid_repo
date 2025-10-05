/*
 * Base 10 to base 2
 * TODO: Just base 10 is stupid! Modify it (or create another file, whatever) so
 * that it converts all letters too, add support for letters. Hexadecimals only
 * goes until 'F', maybe convert letters to int then convert to binary.
 * 'Segmentation fault' for input '0', fix this shit
 */
#include <iostream>
#include <vector>

void base10to2(int base10, std::vector<int> &v_base2);

int main(void) {
  // Get base 10 number and store it into a variable
  // TODO: Add type safety for stupid users
  int base10;

  std::cout << "Enter base 10 number: ";
  std::cin >> base10;

  // Vector to store binary digits
  std::vector<int> v_base2;
  for (int bit; std::cin >> bit;) {
    std::cin >> base10;
    base10to2(base10, v_base2);
  }

  // Void function convert base 10 number into base 2
  base10to2(base10, v_base2);

  // Get size of vector containing binary number
  int size = v_base2.size();

  // Output binary digits
  for (int i = 0; i < size; i++) {
    std::cout << v_base2[i];
  }
  std::cout << std::endl;
}

/* Void function convert base 10 number into base 2
 * by recursivily do integer divisions by 2 and adding the last "quotient" (1)
 * to vector. The values "rests" and the last "quotient" are added through
 * insert method.
 *
 * TODO: Excuse-me sir 🧐, do you think I have a shitload of RAM?
 * BECAUSE I DON'T!!! This recursive function looks cool but if the input is too
 * much then when are adding a bunch of stuff to stack. Maybe I should've used a
 * for loop instead. I don't know, I will make some tests...
 */

void base10to2(int base10, std::vector<int> &v_base2) {
  // If "base10" == 1, so no more operation is needed, just add it to vector
  if (base10 == 1) {
    v_base2.insert(v_base2.begin(), 1);
    return;
  }

  int base = 2;
  int rest = base10 % 2;
  int quotient = (base10 - (base10 % base)) / base; // It's just basic math, yo!

  v_base2.insert(v_base2.begin(), rest);

  // "Base case" should be reached once quotient == 1, unless "base10" is 1
  if (quotient == 1) {
    v_base2.insert(v_base2.begin(), 1);
    return;
  }
  return base10to2(quotient, v_base2);
}
