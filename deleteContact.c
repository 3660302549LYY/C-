#include <stdio.h>
#include <string.h>
#include "contactst.c"


Contact contacts[MAX_CONTACTS];  
int count;                  


void deleteContact() {
	count = loadContacts(contacts); 
	displayAll();                  

	
	
    if (count == 0) {
        printf("通讯录为空，无联系人可删除！\n");
        return;
    }
    char delName[NAME_LEN];
    printf("请输入要删除联系人的姓名：");
    scanf("%s", delName);
    
    int i, findIndex = -1;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, delName) == 0) {
            findIndex = i;
            break;
        }
    }
    
    if (findIndex == -1) {
        printf("未找到名为【%s】的联系人，删除失败！\n", delName);
        return;
    }
    
    for (i = findIndex; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--; 
    printf("联系人【%s】删除成功！\n", delName);
}
