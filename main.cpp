#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
#include <random>
#include <string>
#include <time.h>

#define SIZEMAX 10

using namespace std;

int fieldSize = 0;
int cowNo = 0;

int cowPlace[SIZEMAX][SIZEMAX];
//int* numberArr;

void Initialize();
//bool* CreateCowArray();
int getNumberOfCowsInCorners();
int getNumberOfCowsWithNeighbours();

int main()
{
    srand (time(NULL));
    char chTemp;

        system("cls");
        printf("Please enter the field size: ");
        scanf ("%d",&fieldSize);

        printf("Please enter the cow number: ");
        scanf ("%d",&cowNo);

        Initialize();

        printf("\nNo. of cows in the corners are: %d",getNumberOfCowsInCorners());

        printf("\nNo. of adjacent cows are: %d", getNumberOfCowsWithNeighbours());

        printf("\n\n");

    return 0;
}


void Initialize() {
  int x = 0;
  int y = 0;
  int cowNoHolder = 0;

  //fieldSize = random(SIZEMAX) + 1;
  if (fieldSize < 1) {
    fieldSize = 1;
  }
  if (fieldSize > SIZEMAX) {
    fieldSize = SIZEMAX;
  }
  printf("\n\nThe field size is: %d",fieldSize);

  //cowNo = random(fieldSize + 1) * random(fieldSize + 1);
  if (cowNo < 0) {
    cowNo = 0;
  }
  if (cowNo > (fieldSize * fieldSize)) {
    cowNo = (fieldSize * fieldSize) - 1;
  }
  printf("\n\nThe cow no is: %d", cowNo);

  //Initializing the cowplace array with all zero
  printf("\n\nInitializing the cowplace array with all zero");
  for (x = 0; x < fieldSize; x++) {
    for (y = 0; y < fieldSize; y++) {
      cowPlace[x][y] = 0;
    }
  }

  //Distribute the cows randomly
  printf("\n\nDistribute the cows randomly");
  while (cowNoHolder < cowNo) {
    x = rand()%fieldSize;
    y = rand()%fieldSize;
    if (0 == cowPlace[x][y]) {
      cowNoHolder++;
      cowPlace[x][y] = cowNoHolder;
    }
  }

  //Diplay the cows on the field
  printf("\n\nDiplay the cows on the field\n");
  for (x = 0; x < fieldSize; x++) {
    for (y = 0; y < fieldSize; y++) {
      if (cowPlace[x][y]) {
            printf("%d\t",cowPlace[x][y]);
        //cowNo++;
      } else {
        printf("X\t");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int getNumberOfCowsInCorners() {
  bool cowArr[fieldSize * fieldSize]={false};
  int x = 0;
  int y = 0;
  int cowsInCorner = 0;
  int corner_0_0 = 0;
  int corner_0_fieldSize = fieldSize - 1;
  int corner_fieldSize_0 = (fieldSize - 1) * fieldSize;
  int corner_fieldSize_fieldSize = (fieldSize * fieldSize) - 1;

  if (fieldSize < 2) {
    return (cowNo);
  }

  for (x = 0; x < fieldSize; x++) {
    for (y = 0; y < fieldSize; y++) {
        if (cowPlace[x][y]) {
        cowArr[x + (y * fieldSize)] = true;
        }
    }
  }

  if (cowArr[corner_0_0]) {
    cowsInCorner++;
  }

  if (cowArr[corner_0_fieldSize]) {
    cowsInCorner++;
  }

  if (cowArr[corner_fieldSize_0]) {
    cowsInCorner++;
  }

  if (cowArr[corner_fieldSize_fieldSize]) {
    cowsInCorner++;
  }

  return (cowsInCorner);
}

int getNumberOfCowsWithNeighbours() {
  bool cowArr[fieldSize * fieldSize]={false};
  int neighNo = 0;
  int x = 0;
  int y = 0;
  if (fieldSize < 2) {
    return (neighNo);
  }

  for (x = 0; x < fieldSize; x++) {
    for (y = 0; y < fieldSize; y++) {
      if (cowPlace[x][y]) {
        cowArr[x + (y * fieldSize)] = true;
      }
    }
  }

  for (x = 0; x < fieldSize; x++) {
    for (y = 0; y < fieldSize; y++) {

      if(false == cowArr[x + (y * fieldSize)])
      {
        continue;
      }
      //printf("\n(%d,%d)",x,y);
      if(x==0)
      {
          if(cowArr[(x+1) + ((y) * fieldSize)])
          {
              neighNo++;
              //printf("\n(x+1)Neigh: %d",neighNo);
          }
          if(y>0)
          {
              if(cowArr[(x) + ((y-1) * fieldSize)])
              {
                  neighNo++;
                  //printf("\n(y-1)Neigh: %d",neighNo);
              }
          }
          if(y<(fieldSize-1))
          {
              if(cowArr[(x) + ((y+1) * fieldSize)])
              {
                  neighNo++;
                  //printf("\n(y+1)Neigh: %d",neighNo);
              }
          }
      }
      else if(x == (fieldSize - 1))
      {
          if(cowArr[(x-1) + ((y) * fieldSize)])
          {
              neighNo++;
              //printf("\n(x-1)Neigh: %d",neighNo);
          }
          if(y>0)
          {
              if(cowArr[(x) + ((y-1) * fieldSize)])
              {
                  neighNo++;
                  //printf("\n(y-1)Neigh: %d",neighNo);
              }
          }
          if(y<(fieldSize-1))
          {
              if(cowArr[(x) + ((y+1) * fieldSize)])
              {
                  neighNo++;
                  //printf("\n(y+1)Neigh: %d",neighNo);
              }
          }
      }
      else
      {
          if(cowArr[(x-1) + ((y) * fieldSize)])
          {
              neighNo++;
              //printf("\n(x-1)Neigh: %d",neighNo);
          }
          if(cowArr[(x+1) + ((y) * fieldSize)])
          {
              neighNo++;
              //printf("\n(x+1)Neigh: %d",neighNo);
          }
          if(y>0)
          {
              if(cowArr[(x) + ((y-1) * fieldSize)])
              {
                  neighNo++;
                  //printf("\n(y-1)Neigh: %d",neighNo);
              }
          }
          if(y<(fieldSize-1))
          {
              if(cowArr[(x) + ((y+1) * fieldSize)])
              {
                  neighNo++;
                  //printf("\n(y+1)Neigh: %d",neighNo);
              }
          }

      }

    }
  }

  return (neighNo);
}
