#ifndef TABLE_H
#define TABLE_H 

#include <stdint.h>
#include <stdlib.h>

#define MAX_LENGTH 50

struct column { 
  char name[MAX_LENGTH];
  //dyamically allocated space for value in that column
  char *value; 
};

struct table {
  //make sure to init pk and char array to 0 and and empty string '\0'
  int pk; 
  char name[MAX_LENGTH]; 
  //add more table attributes later, some will not be used, not sure what else to add
  struct column *columns; 
  int column_count; 

  struct table *rows; 
  int row_count; 
}; 

//simple table functions for now 
void createTable(struct table *table); //make sure that createTable allocates space for struct and its data
void addRow(struct table *tbl); 
void addColumn(struct table *tbl, const char *col_name); 
//dropTable needs to free memory from table struct allocated memory
void dropTable(struct table *table);
//Need to fix, check table.c NOTE
void joinTable(struct table *table1, struct table *table2, const char common[MAX_LENGTH]); //we seem to be attempting to read more bytes than what exists
void printTable(struct table table); 
/* NOTE FOR JOIN: 
 * Join function:
 *    - Combines rows from two or more tables, based on a related column between them
 *    - Implent INNER JOINS for now
 *      -Other Joins
 *        - LEFT JOIN
 *        - RIGHT JOIN
 *        - FULL OUTER JOIN
 * */ 
#endif
