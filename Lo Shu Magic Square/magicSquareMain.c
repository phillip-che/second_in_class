#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool loShuMagicSquareCheck(int array[3][3])
{
   int rowTotal = 0, colTotal = 0, diag1Total = 0, diag2Total = 0;
   bool result = true;
   int squareTotal[8];

   // sum of rows, columns, and diagonals
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
      {
         rowTotal += array[row][col];
         colTotal += array[col][row];
      }
      diag1Total += array[row][row];
      diag2Total += array[row][2 - row];
      squareTotal[row] = rowTotal;
      squareTotal[row + 3] = colTotal;
      rowTotal = 0;
      colTotal = 0;
   }
   squareTotal[6] = diag1Total;
   squareTotal[7] = diag2Total;

   for (int i = 1; i < 8; i++)
   {
      if (squareTotal[i] != squareTotal[i - 1])
         result = false;
   }

   return result;
}

void loShuMagicSquareGenerator()
{
   bool isLoShuMagicSquare = false;
   int counter = 0, index = 0, temp, randIndex;
   int array[3][3];
   int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   time_t t;

   srand(time(NULL));

   while (isLoShuMagicSquare != true)
   {

      // scramble numbers array
      for (int i = 0; i < 9; i++)
      {
         randIndex = (rand() % 9);
         temp = numbers[randIndex];
         numbers[randIndex] = numbers[i];
         numbers[i] = temp;
      }

      for (int row = 0; row < 3; row++)
      {
         for (int col = 0; col < 3; col++)
         {
            array[row][col] = numbers[index];
            index++;
         }
      }

      index = 0;
      counter++;
      isLoShuMagicSquare = loShuMagicSquareCheck(array);
   }

   printf("Total Number of Squares Generated Before Success: %d\n", counter);

   //prints array
   for (int row = 0; row < 3; row++)
   {
      printf("[");
      for (int col = 0; col < 3; col++)
      {
         printf(" %d ", array[row][col]);
         if (col == 2)
            printf("]\n");
      }
   }
}

void main()
{
   bool isLoShuMagicSquare;
   int loShuMagicSquare[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
   int square[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   isLoShuMagicSquare = loShuMagicSquareCheck(loShuMagicSquare);

   if (isLoShuMagicSquare == false)
      printf("Not a Lo Shu Magic Square\n");
   else
      printf("Is a Lo Shu Magic Square\n");

   isLoShuMagicSquare = loShuMagicSquareCheck(square);

   if(isLoShuMagicSquare == false)
      printf("Not a Lo Shu Magic Square\n");
   else
      printf("Is a Lo Shu Magic Square\n");

   loShuMagicSquareGenerator();
}