#include <iostream>

int number1 = 0;
int number2 = 1;
int number3;
int main() {
  std::cout << "Term 1: " << number1 << std::endl;
  std::cout << "Term 2: " << number2 << std::endl;
  for (int i = 3; i <= 30; i++) {
  	number3 = number1 + number2;
    number1 = number2;
    number2 = number3;
    std::cout << "Term " << i << ": " << number3 << std::endl;
  }
  return 0;
}