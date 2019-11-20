#include <iostream>

class Date {
 public:
  Date(int d, int m) : day(d), month(m) {}
  Date(void) : day(1), month(1) {}
  void set(int d, int m) {
    this->day = d;
    this->month = m;
  }
  void print(void) const { std::cout << this->day << "/" << this->month; }

 private:
  int day, month;
};
