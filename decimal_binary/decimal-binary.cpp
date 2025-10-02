/*
 * Base 10 to base 2
 */
#include <iostream>
#include <vector>

void base10to2(int base10, std::vector<int> &v_base2);

int main(void) {
  // Get base 10 number and store it into a variable
  // TODO: Add type safety for stupid users
  int base10;
  bool stupid_user;

  std::cout << "Enter base 10 number: ";
  std::cin >> base10;

  // Vector to store binary digits
  std::vector<int> v_base2;

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
 * to vector The values "rests" and the last "quotient" are added through insert
 * method
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
<<<<<<< HEAD

  }
  return base10to2(quotient);
}
=======
>>>>>>> cb1b4f6 (Just made it better)
