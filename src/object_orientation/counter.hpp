#include <iostream>

class Counter {
 public:
  Counter(void) : value(0) {}
  void tick(void) { this->value += 1; }
  void reset(void) { this->value = 0; }
  void print(void) const { std::cout << this->value << std::endl; }
  int get(void) const { return this->value; }

 private:
  int value;
};
