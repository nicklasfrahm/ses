#include <pthread.h>
#include <iostream>

int turn = 0;

void* hi(void* arg) {
  while (true) {
    if (turn == 0) {
      std::cout << "h" << std::flush;
      std::cout << "i" << std::flush;
      turn = 1;
    }
  }
}

void* bye(void* arg) {
  while (true) {
    if (turn == 1) {
      std::cout << "b" << std::flush;
      std::cout << "y" << std::flush;
      std::cout << "e" << std::flush;
      turn = 0;
    }
  }
}

int main(void) {
  std::cout << "The two threads will interfere without mutual exclusion:"
            << std::endl
            << std::flush;

  pthread_t hi_handle;
  pthread_t bye_handle;

  pthread_create(&hi_handle, NULL, &hi, NULL);
  pthread_create(&bye_handle, NULL, &bye, NULL);

  pthread_join(hi_handle, NULL);
  pthread_join(bye_handle, NULL);

  return 0;
}
