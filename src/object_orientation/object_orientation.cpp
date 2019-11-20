#include <iostream>
#include "adder.hpp"
#include "counter.hpp"
#include "period.hpp"

void linebreak(void) { std::cout << std::endl; }

int main(void) {
  // Dates.
  Date newYear, christmas(24, 12), today(4, 9), whenIGetMyStuffTogether(4, 9);

  newYear.print();
  linebreak();

  christmas.print();
  linebreak();

  today.print();
  linebreak();

  whenIGetMyStuffTogether.print();
  linebreak();
  whenIGetMyStuffTogether.set(11, 9);
  whenIGetMyStuffTogether.print();
  linebreak();

  // Periods.
  Period potatoHoliday(Date(14, 10), Date(20, 10));
  Period christmasHoliday(christmas, newYear);

  potatoHoliday.print();
  linebreak();

  christmasHoliday.print();
  linebreak();

  // Counters.
  Counter beers;
  beers.tick();
  beers.tick();
  std::cout << beers.get() << std::endl;
  beers.reset();
  beers.print();

  // Adders.
  Adder shopping;
  shopping.add(12);
  shopping.add(-8);
  std::cout << shopping.get() << std::endl;
  shopping.reset();
  shopping.print();

  return 0;
}
