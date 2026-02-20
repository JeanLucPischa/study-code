#include <stdio.h>

#define MAX_ARRAY_SIZE 3000

typedef struct{
  float time;
  double probability;
} SensorData;

typedef struct{
  int id;
  double threshold;
  SensorData data[MAX_ARRAY_SIZE];
  int object_detection[MAX_ARRAY_SIZE];
} Sensor;

void read_to_SensorData(Sensor *ptr_sensor, char *file);

void generate_detection_signal(Sensor *ptr_sensor);

void analyze_detections(Sensor *ptr_sensor1, Sensor *ptr_sensor2);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(){

  Sensor sensor1 = {1, 0.8, {0}, {0}};
  Sensor sensor2 = {2, 0.7, {0}, {0}};

  Sensor *ptr_sensor1 = &sensor1;
  Sensor *ptr_sensor2 = &sensor2;

  read_to_SensorData(ptr_sensor1, "sensor1.txt");
  read_to_SensorData(ptr_sensor2, "sensor2.txt");

  generate_detection_signal(ptr_sensor1);
  generate_detection_signal(ptr_sensor2);

  analyze_detections(ptr_sensor1, ptr_sensor2);

  return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void read_to_SensorData(Sensor *ptr_sensor, char *file){
  FILE *data = fopen(file, "r");
  if(data == NULL){
    printf("Cannot open file.\n");
    return;
  }

  int i = 0;

  while(i < MAX_ARRAY_SIZE && fscanf(data, "%f %lf", &ptr_sensor->data[i].time, &ptr_sensor->data[i].probability) == 2){
    i++;
  }

  if(fclose(data) != 0){
    printf("Cannot close file.\n");
    return;
  }
}

void generate_detection_signal(Sensor *ptr_sensor){
  for(int i=0; i<MAX_ARRAY_SIZE; i++){
    if((ptr_sensor->data[i].probability)>ptr_sensor->threshold){
      ptr_sensor->object_detection[i] = 1;
    }
    else{
      ptr_sensor->object_detection[i] = 0;
    }
  }
}

void analyze_detections(Sensor *ptr_sensor1, Sensor *ptr_sensor2){
  int signal = 0;

  printf("Sensor 1 detections: ");
  for(int i=0; i<MAX_ARRAY_SIZE; i++){
    if((ptr_sensor1->object_detection[i]) == 1){
      if(!signal){
        printf(" Start: %.2f s", (ptr_sensor1->data[i].time));
        signal = 1;
      }
    }
    if(!((ptr_sensor1->object_detection[i]) == 1) && signal){
      printf(" End: %.2f s", (ptr_sensor1->data[i].time));
      signal = 0;
    }
  }
  printf("\n");
  signal = 0;

  printf("Sensor 2 detections: ");
  for(int i=0; i<MAX_ARRAY_SIZE; i++){
    if((ptr_sensor2->object_detection[i]) == 1){
      if(!signal){
        printf(" Start: %.2f s", (ptr_sensor2->data[i].time));
        signal = 1;
      }
    }
    if(!((ptr_sensor2->object_detection[i]) == 1) && signal){
      printf(" End: %.2f s", (ptr_sensor2->data[i].time));
      signal = 0;
    }
  }
  printf("\n");
  signal = 0;

  printf("Fused signal (both sensors): ");
  for(int i=0; i<MAX_ARRAY_SIZE; i++){
    if(((ptr_sensor1->object_detection[i]) == 1) && ((ptr_sensor2->object_detection[i]) == 1)){
      if(!signal){
        printf(" Start: %.2f s", (ptr_sensor1->data[i].time));
        signal = 1;
      }
    }
    if(!(((ptr_sensor1->object_detection[i]) == 1) && ((ptr_sensor2->object_detection[i]) == 1)) && signal){
      printf(" End: %.2f s", (ptr_sensor1->data[i].time));
      signal = 0;
    }
  }
  printf("\n");
}