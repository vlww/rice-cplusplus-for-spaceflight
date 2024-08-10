#include<iostream>

int main() {
  // 1 and 2 are given :)
  std::cout << "1 is " << "Composite" << std::endl;
  std::cout << "2 is " << "Prime" << std::endl;
  if (3 % 2 != 0) {
    std::cout << "3 is " << "Prime" << std::endl;
  } else {
    std::cout << "3 is " << "Composite" << std::endl;
  }
  if (4 % 2 != 0 && 4 % 3 != 0) {
    std::cout << "4 is " << "Prime" << std::endl;
  } else {
    std::cout << "4 is " << "Composite" << std::endl;
  }
  if (5 % 2 != 0 && 5 % 3 != 0 && 5 % 4 != 0) {
    std::cout << "5 is " << "Prime" << std::endl;
  } else {
    std::cout << "5 is " << "Composite" << std::endl;
  }
  if (6 % 2 != 0 && 6 % 3 != 0 && 6 % 4 != 0 && 6 % 5 != 0) {
    std::cout << "6 is " << "Prime" << std::endl;
  } else {
    std::cout << "6 is " << "Composite" << std::endl;
  }
  if (7 % 2 != 0 && 7 % 3 != 0 && 7 % 4 != 0 && 7 % 5 != 0 && 7 % 6 != 0) {
    std::cout << "7 is " << "Prime" << std::endl;
  } else {
    std::cout << "7 is " << "Composite" << std::endl;
  }
  if (8 % 2 != 0 && 8 % 3 != 0 && 8 % 4 != 0 && 8 % 5 != 0 && 8 % 6 != 0 && 8 % 7 != 0) {
    std::cout << "8 is " << "Prime" << std::endl;
  } else {
    std::cout << "8 is " << "Composite" << std::endl;
  }
  if (9 % 2 != 0 && 9 % 3 != 0 && 9 % 4 != 0 && 9 % 5 != 0 && 9 % 6 != 0 && 9 % 7 != 0 && 9 % 8 != 0) {
    std::cout << "9 is " << "Prime" << std::endl;
  } else {
    std::cout << "9 is " << "Composite" << std::endl;
  }
  if (10 % 2 != 0 && 10 % 3 != 0 && 10 % 4 != 0 && 10 % 5 != 0 && 10 % 6 != 0 && 10 % 7 != 0 && 10 % 8 != 0 && 10 % 9 != 0) {
    std::cout << "10 is " << "Prime" << std::endl;
  } else {
    std::cout << "10 is " << "Composite" << std::endl;
  }
  return 0;
}