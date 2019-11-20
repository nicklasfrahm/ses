#include <iostream>
#include <unistd.h>
#include <signal.h>

int main(void) {
  // Prepare variables for animations.
  const char animationCharacters[] = { '-', '\\', '|', '/' };
  int counter = 0;

  // Run eternal animation.
  while (true) {
    // Display animation characters.
    std::cout << "\r" << animationCharacters[counter] << " Running...";

    // Increment counter, while keeping the number within the boundaries of the array.
    counter = ++counter % 4;

    // Delay next run of the loop.
    usleep(250000);
  }

  return 0;
}
