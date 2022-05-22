#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LoadMap {
  char programName[100];
  char programLength[100];
  char programStart[100];
  char programStartLength[100];
  char programEnd[100];
  char programEndLength[100];
  int length;
  int startLength;
  int endLength;
} loadMap[100];

int stringToDec(char string[100]) {
  int j, k = 0;
  int length = 0;
  for (j = strlen(string) - 1; j >= 0; j--) {
    switch (string[j]) {
      case '0':
        length += (int)pow(16, k) * 0;
        break;
      case '1':
        length += (int)pow(16, k) * 1;
        break;
      case '2':
        length += (int)pow(16, k) * 2;
        break;
      case '3':
        length += (int)pow(16, k) * 3;
        break;
      case '4':
        length += (int)pow(16, k) * 4;
        break;
      case '5':
        length += (int)pow(16, k) * 5;
        break;
      case '6':
        length += (int)pow(16, k) * 6;
        break;
      case '7':
        length += (int)pow(16, k) * 7;
        break;
      case '8':
        length += (int)pow(16, k) * 8;
        break;
      case '9':
        length += (int)pow(16, k) * 9;
        break;
      case 'A':
      case 'a':
        length += (int)pow(16, k) * 10;
        break;
      case 'B':
      case 'b':
        length += (int)pow(16, k) * 11;
        break;
      case 'C':
      case 'c':
        length += (int)pow(16, k) * 12;
        break;
      case 'D':
      case 'd':
        length += (int)pow(16, k) * 13;
        break;
      case 'E':
      case 'e':
        length += (int)pow(16, k) * 14;
        break;
      case 'F':
      case 'f':
        length += (int)pow(16, k) * 15;
        break;
    }
    k++;
  }
  return length;
}

int main(int argc, char *argv[]) {
  char temp;

  int i, j, k;
  int loadMapLength = 0;

  // load start location
  char start[100];
  strcat(start, argv[1]);
  int lengthSum = stringToDec(start);
  printf("%X\n", lengthSum);

  for (i = 2; i < argc; i++) {
    FILE *f = fopen(argv[i], "r");
    char word;
    if (f == NULL) {
      printf("file not found!");
    } else {
      char line[999];
      while (fgets(line, 999, f)) {
        if (line[0] == 'H') {
          memset(loadMap[loadMapLength].programName, '\0', 100);
          memset(loadMap[loadMapLength].programLength, '\0', 100);
          for (j = 1; j < strlen(line); j++) {
            if (line[j] != ' ') {
              strncat(loadMap[loadMapLength].programName, &line[j], 1);
            } else {
              strncat(loadMap[loadMapLength].programLength, &line[j + 1], strlen(line) - (j + 2));
              loadMap[loadMapLength].length = stringToDec(loadMap[loadMapLength].programLength);
              break;
            }
          }
        } else if (line[0] == 'D') {
          memset(loadMap[loadMapLength].programStart, '\0', 100);
          memset(loadMap[loadMapLength].programEnd, '\0', 100);
          memset(loadMap[loadMapLength].programStartLength, '\0', 100);
          memset(loadMap[loadMapLength].programEndLength, '\0', 100);
          strncat(loadMap[loadMapLength].programStart, &line[1], 6);
          strncat(loadMap[loadMapLength].programStartLength, &line[7], 6);
          strncat(loadMap[loadMapLength].programEnd, &line[13], 6);
          strncat(loadMap[loadMapLength].programEndLength, &line[19], 6);
          loadMap[loadMapLength].startLength = stringToDec(loadMap[loadMapLength].programStartLength);
          loadMap[loadMapLength].endLength = stringToDec(loadMap[loadMapLength].programEndLength);
        }
      }
      fclose(f);
    }
    loadMapLength++;
  }

  printf("%-18s%-14s%-8s%-4s\n", "control section", "symbol name", "address", "length");
  for (i = 0; i < loadMapLength; i++) {
    printf("%-18s%-14s%-8X%04X\n", loadMap[i].programName, "", lengthSum, loadMap[i].length);
    printf("%-18s%-14s%-6X\n", "", loadMap[i].programStart, lengthSum + loadMap[i].startLength);
    printf("%-18s%-14s%-8X\n", "", loadMap[i].programEnd, lengthSum + loadMap[i].endLength);
    lengthSum += loadMap[i].length;
  }
}