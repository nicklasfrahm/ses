#include <pthread.h>
#include <iostream>

pthread_mutex_t screen_free = PTHREAD_MUTEX_INITIALIZER;

void* hi(void* arg) {
  while (true) {
    pthread_mutex_lock(&screen_free);
    std::cout << "h" << std::flush;
    std::cout << "i" << std::flush;
    pthread_mutex_unlock(&screen_free);
  }
}

void* bye(void* arg) {
  while (true) {
    pthread_mutex_lock(&screen_free);
    std::cout << "b" << std::flush;
    std::cout << "y" << std::flush;
    std::cout << "e" << std::flush;
    pthread_mutex_unlock(&screen_free);
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
