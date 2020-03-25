#include <stdio.h>

int main(void) {
  int arr[1][2][1][3][1] = {{{{{1},{2},{3}}},{{{4},{5},{6}}}}};
  
  for(int i = 0; i < 1; i++) {
      for(int x = 0; x < 2; x++) {
          for(int b = 0; b < 1; b++) {
              for(int c = 0; c < 3; c++) {
                  for(int t = 0; t < 1; t++) {
                      printf("%d",arr[i][x][b][c][t]);
                  }
              }
          }
      }
  }
}
