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

   if(matchPtr != NULL)
      printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee ID 1045 is NOT found in the record\n");
   
   matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
   
   if (matchPtr != NULL)
      printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Tony Bobcat is NOT found in the record\n");

   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-7890");

   if(matchPtr != NULL)
      printf("Employee Phone 123-456-7890 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Phone 123-456-7890 is NOT in the record\n");

   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");

   if (matchPtr != NULL)
      printf("Employee Phone 714-555-2749 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Phone 714-555-2749 is NOT in the record\n");

   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.26);

   if (matchPtr != NULL)
      printf("Employee Salary 6.26 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Salary 6.26 is NOT in the record\n");

   matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);

   if (matchPtr != NULL)
      printf("Employee Salary 8.78 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Salary 8.78 is NOT in the record\n");

   return EXIT_SUCCESS;
}