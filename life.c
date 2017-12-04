#include <stdio.h>
#include <stdlib.h>

char* globalT;
int globalWidth;
int globalHeight;

const int REINCARNATE = 3;
const int MIN_STAY_ALIVE = 2;
const int MAX_STAY_ALIZE = 3;

void initialize(int* resWidth, int* resHeight, char** addrT) {
  char* resT;
  scanf("%d", resWidth);
  scanf("%d", resHeight);

  int height = *resHeight;
  int width = *resWidth;

  resT = malloc(height * width * sizeof(char));

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int scannedValue = 0;
      scanf("%d", &scannedValue);
      if (scannedValue > 0) {
        resT[i * width + j] = (char) 1;
      } else {
        resT[i * width + j] = (char) 0;
      }
    }
  }
  
  *addrT = resT;
}

void start(int width, int height, char* T) {
  globalHeight = height;
  globalWidth = width;
  globalT = T;
  return;
}

void move_all_t_bits_left() {
  for (int i = 0; i < globalHeight; i++) {
    for (int j = 0; j < globalWidth; j++) {
      globalT[i * globalWidth + j] <<= 1;
    }
  }
}

int get_new_value(int index, int n_sum) {
  return ((globalT[index] & 1) && (n_sum <= MAX_STAY_ALIZE || n_sum >= MIN_STAY_ALIVE)) || ((globalT[index] ^ 1) && n_sum == 3);
}

int get_cell_neighbours_value(int col, int row) {
  int n_value = 0;

  for (int h = -1; h <= 1; h++) {
    for (int w = -1; w <= 1; w++) {
      int w_index = w + col;
      int h_index = h + row;
      if ((w_index < 0 || w_index >= globalWidth) || (h_index < 0 || h_index >= globalHeight) || (w_index == 0 && h_index == 0)) {
        continue;
      }
      n_value += globalT[globalWidth * (row + h) + w + col] >> 1 & 1;
    }
  }

  return n_value;
}

void run_one_step() {  
  for (int i = 0; i < globalHeight; i++) {
    for (int j = 0; j < globalWidth; j++) {
      int value = get_cell_neighbours_value(j, i);
      int position = i * globalWidth + j;
      globalT[position] |= get_new_value(position, value);
    }
  }

}


void run(int steps_num) {
  for (int i = 0; i < steps_num; i++) {
    move_all_t_bits_left();
    run_one_step();
  }
  return;
}

int main() {
  int width = 0;
  int height = 0;
  char* T = malloc(sizeof(char*));

  initialize(&width, &height, &T);

  if (width < 1 || height < 1) {
    printf("width && height must be > 1");
    return 0;
  }

  start(width, height, T);
  run(1);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", globalT[i * width + j] & 1);
    }
    printf("\n");
  }

  return 0;
}
