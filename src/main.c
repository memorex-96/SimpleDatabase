#include <stdio.h>
#include "table.c"
/*
 * CLI Database Program 
 * Simple functions: 
 *    - Create Table
 *      - Each column would be an array of attributes
 *    - Drop Table
 *    - Select Queries
 *    - Join Tables (later on)
 */


int main()
{
  struct table testTable; 
  
  createTable(&testTable); 
  addColumn(&testTable, "Age");
  addColumn(&testTable, "Occupation");

  addRow(&testTable); 
  addRow(&testTable);
  printf("Table has %d and %d columns", testTable.row_count, testTable.column_count); 
  //free(&testTable);  
  return 0; 
}


