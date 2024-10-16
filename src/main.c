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
  printf("Table has %d and %d columns\n", testTable.row_count, testTable.column_count); 
  

  dropTable(&testTable);
  printf("Table has %d and %d columns\n", testTable.row_count, testTable.column_count); 
  
  //test for the inner join on two tables 
  struct table table1; 
  struct table table2; 
  
  createTable(&table1);
  createTable(&table2);

  addColumn(&table1, "Common");
  addColumn(&table2, "Common"); 
  addRow(&table1);
  addRow(&table2);
  char common[MAX_LENGTH] = {"Common"}; 
  joinTable(&table1, &table2, common);    
  return 0; 
}


