#include <stdio.h>
#include <string.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];  

int count;                  



void displayAll(){
	Contact nc;

    if (count == 0) {
        printf("通讯录为空！\n");
        return;
    }
    ph();

	int i;
    for (i=0; i < count; i++) {
        printf("|\t%-8d|\t%-8s|\t%-8s|\t%-8s|\t%-8s|\n", 
               i + 1, 
               contacts[i].name, 
               contacts[i].company, 
               contacts[i].title, 
               contacts[i].phone);
        printf("---------------------------------------------------------------------------------\n");       
    }
    
   
    printf("总计：%d 个联系人\n", count);
}
