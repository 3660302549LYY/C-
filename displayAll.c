#include <stdio.h>
#include <string.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];  

int count;                  



void displayAll(){
	Contact nc;

    if (count == 0) {
        printf("ͨѶ¼Ϊ�գ�\n");
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
    
   
    printf("�ܼƣ�%d ����ϵ��\n", count);
}
