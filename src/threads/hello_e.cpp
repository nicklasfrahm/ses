#include <pthread.h>
#include <iostream>

class Screen {
 public:
  Screen(void) {}
  void print_string(const char* string, bool keep = false) {
    pthread_mutex_lock(&this->ready);
    std::cout << string << std::flush;
    if (!keep) {
      pthread_mutex_unlock(&this->ready);
    }
  }

 private:
  pthread_mutex_t ready = PTHREAD_MUTEX_INITIALIZER;
};

Screen screen;

void* hi(void* arg) {
  while (true) {
    screen.print_string("hi");
  }
}

void* bye(void* arg) {
  while (true) {
    screen.print_string("bye");
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
