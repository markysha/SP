#include <iostream>

using namespace std;

int readNumber(int radix);
int charToDigit(char c, int radix);
char digitToChar(int digit, int radix);

int main() {
  cout << "Enter base of numeral system (should be >= 2 and <= 36)" << endl;
  int radix;
  cin >> radix;
  cin.get(); // remove '\n' left after reading radix
  if (radix < 2 || radix > 36) return 1;
  cout << "Enter number" << endl;
  int number = readNumber(radix);
  cout << number << endl;
  return 0;
}

int readNumber(int radix) {
  int number = 0;
  char c;
  while (true) {
    cin.get(c);
    if (c == '\n') break;
    number *= radix;
    number += charToDigit(c, radix);
  }
  return number;
}

int charToDigit(char c, int radix) {
  int digit = 36;
  if ('0' <= c && c <= '9') {
    digit = c - '0';
  } else if ('a' <= c && c <= 'z') {
    digit = c - 'a' + 10;
  }
  if (digit >= radix) {
    cout << "Illegal digit: " << c << endl;
    std::exit(1);
  }
  return digit;
}

char digitToChar(int digit, int radix) {
  if (digit <= 9) return digit + '0';
  return digit - 10 + 'a';
}
