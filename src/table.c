#include "table.h" 
#include <string.h>

//should just init all structure values
void createTable(struct table *tbl) { 
    tbl->pk = 0; 
    tbl->name[0] = '\0';
    tbl->columns = NULL; //for custom colums 
    tbl->column_count = 0; 
    tbl->rows = NULL;
    tbl->row_count = 0; 
}

void addRow(struct table *tbl) {
    tbl->row_count++; 
    tbl->rows = realloc(tbl->rows, tbl->row_count * sizeof(struct table));
    if (tbl->rows == NULL) exit(1); //memory allocation error needs to be handled
    
    //BTW indexing for 0
    createTable(&tbl->rows[tbl->row_count - 1]); 
}

void addColumn(struct table *tbl, const char *col_name) {
    tbl->column_count++; 
    
    //allocate all of our columns into the dynamic array
    //if tbl->columns is NULL,
    tbl->columns = realloc(tbl->columns, tbl->column_count * sizeof(struct column));
    if (tbl->columns == NULL) exit(1); //again, more memory allocation errors that will need to be handled
    
    //init new column with name and auto NULL value
    strcpy(tbl->columns[tbl->column_count - 1].name, col_name); 
    tbl->columns[tbl->column_count - 1].value = NULL; 
}

void dropTable(struct table *tbl) {
    //free memory from within columns before freeing the WHOLE array to 
    //avoid possible memory leaks
    for (int i = 0; i < tbl->column_count; i++) {
        free(tbl->columns[i].value); 
    }
    free(tbl->columns);

    //same for the rows except rows can be objects from another table, so 
    //we'll recursively free the memory in those too to avoid additional memory leaks. 
    for (int i = 0; i < tbl->row_count; i++) { 
      dropTable(&tbl->rows[i]);  
    } 
    free(tbl->rows); 

    //update values
    tbl->columns = NULL; 
    tbl->column_count = 0; 
    tbl->rows = NULL; 
    tbl->row_count = 0; 
    tbl->pk = 0; 
    tbl->name[0] = '\0'; 
    
}
//combine some common column that is present in both tbl1 and tbl2 
void joinTable(struct table *tbl1, struct table *tbl2, const char common[10]) {
      struct table *newTbl = malloc(sizeof(struct table)); 
      createTable(newTbl);
      
      int tbl1_common_index = -1; 
      int tbl2_common_index = -1; 

      for (int i = 0; i < tbl1->column_count; i++) { 
          if (strcmp(tbl1->columns[i].name, common) == 0) { 
              tbl1_common_index = i;
              break; 
          } 
      } 

      for (int i = 0; i < tbl2->column_count; i++) {
          if (strcmp(tbl2->columns[i].name, common) == 0) { 
              tbl2_common_index = i;
              break; 
          } 
      } 
      if (tbl1_common_index != -1 && tbl2_common_index != -1) {
          //copy the tables into newTbl based on common column 
      } else { 
          printf("No common columns in either tables are found\n"); 
      } 
}

//does't need pointer 
void printTable(struct table tbl) { 

}



