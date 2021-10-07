#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
   PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
   PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
   PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
   PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

   extern Employee EmployeeTable[];
   extern const int EmployeeTableEntries;

   PtrToEmployee matchPtr;
   matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

   if (matchPtr != NULL)
      printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee ID 1045 is NOT found in the record\n");

   matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

   if (matchPtr != NULL)
      printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Tony Bobcat is NOT found in the record\n");

   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "831-344-9927");

   if (matchPtr != NULL)
      printf("Employee Phone 831-344-9927 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Phone 831-344-9927 is NOT in the record\n");

   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "213-555-1212");

   if (matchPtr != NULL)
      printf("Employee Phone 213-555-1212 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Phone 213-555-1212 is NOT in the record\n");

   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 1.23);

   if (matchPtr != NULL)
      printf("Employee Salary 1.23 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Salary 1.23 is NOT in the record\n");

   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 7.80);

   if (matchPtr != NULL)
      printf("Employee Salary 7.80 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Salary 7.80 is NOT in the record\n");

   return EXIT_SUCCESS;
}