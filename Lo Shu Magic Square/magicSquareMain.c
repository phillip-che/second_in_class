#include <stdio.h>
#include <stdbool.h>

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

void printSquare(int array[9])
{

}

void main()
{
   bool isLoShuMagicSquare;
   int loShuMagicSquare[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
   int square[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   // isLoShuMagicSquare = loShuMagicSquareCheck(loShuMagicSquare);
   isLoShuMagicSquare = loShuMagicSquareCheck(square);

   if(isLoShuMagicSquare == false)
      printf("Not a Lo Shu Magic Square\n");
   else
      printf("Is a Lo Shu Magic Square\n");
}