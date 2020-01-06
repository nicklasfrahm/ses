#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

pthread_mutex_t road_mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t parking_spaces;
const int CARS = 6;
const int PARKING_PLACES = 4;
pthread_t car[CARS];
int car_nums[CARS];

void column(int n) {
  int i = 0;
  for (i = 0; i < n; i++) cout << "            ";
}

void* car_body(void* vptr) {
  int car_id = *((int*)vptr);
  while (1) {
    sem_wait(&parking_spaces);
    pthread_mutex_lock(&road_mutex);
    column(car_id);
    cout << "car " << car_id << "parked" << endl;
    pthread_mutex_unlock(&road_mutex);
    sleep(car_id + 1);
    pthread_mutex_lock(&road_mutex);
    sem_post(&parking_spaces);
    column(car_id);
    cout << "car " << car_id << "to town" << endl;
    pthread_mutex_unlock(&road_mutex);
    sleep(car_id + 1);
  }

  return NULL;
}

int main(void) {
  sem_init(&parking_spaces, 0, PARKING_PLACES);

  // Create car numbers.
  for (int i = 0; i < CARS; ++i) {
    car_nums[i] = i;
  }

  for (int i = 0; i < CARS; ++i) {
    pthread_create(&car[i], NULL, &car_body, (void*)(&car_nums[i]));
  }
  for (int i = 0; i < CARS; ++i) {
    pthread_join(car[i], NULL);
  }
  return 0;
}
