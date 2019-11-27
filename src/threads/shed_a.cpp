#include <pthread.h>
#include <unistd.h>
#include <iostream>

void* prime(void* arg) {
  int i = 2;
  int n = 2;

  while (n++ < 1e6) {
    for (i = 2; i <= n; ++i) {
      if (n % i == 0) {
        break;
      }
    }
    if (i == n) {
      std::cout << n << " " << std::flush;
    }
  }
}

void* clock(void* arg) {
  long long seconds = 0;
  while (1) {
    std::cout << std::endl << "Time passed: " << seconds++ << "s" << std::endl;
    sleep(1);
  }
}

int configure_scheduling(pthread_attr_t* thread_attributes, int priority) {
  sched_param sched_params = {.sched_priority = priority};
  pthread_attr_init(thread_attributes);
  pthread_attr_setinheritsched(thread_attributes, PTHREAD_INHERIT_SCHED);
  pthread_attr_setschedpolicy(thread_attributes, SCHED_FIFO);
  pthread_attr_setschedparam(thread_attributes, &sched_params);

  return 0;
}

int configure_core(pthread_t* thread, int core_id) {
  int cores = sysconf(_SC_NPROCESSORS_ONLN);
  if (core_id < 0 || core_id >= cores) {
    return EINVAL;
  }

  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(core_id, &cpuset);

  return pthread_setaffinity_np(*thread, sizeof(cpu_set_t), &cpuset);
}

int main(void) {
  pthread_t thread_prime;
  pthread_attr_t thread_attributes_prime;
  configure_scheduling(&thread_attributes_prime, 19);
  pthread_create(&thread_prime, &thread_attributes_prime, &prime, NULL);
  configure_core(&thread_prime, 0);

  pthread_t thread_clock;
  pthread_attr_t thread_attributes_clock;
  configure_scheduling(&thread_attributes_clock, 20);
  pthread_create(&thread_clock, &thread_attributes_clock, &clock, NULL);
  configure_core(&thread_clock, 0);

  pthread_join(thread_prime, NULL);
  pthread_join(thread_clock, NULL);

  return 0;
};
