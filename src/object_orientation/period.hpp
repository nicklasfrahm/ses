#include <iostream>
#include "date.hpp"

class Period {
 public:
  Period(Date s, Date e) : start(s), end(e) {}
  void print(void) const {
    this->start.print();
    std::cout << "-";
    this->end.print();
  }

 private:
  Date start, end;
};
