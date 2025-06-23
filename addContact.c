#include <stdio.h>
#include <string.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];  // 通讯录数组
int count;                   // 当前联系人数量


void addContact(){
	if(count>=MAX_CONTACTS){
		printf("通讯录已满");
		return; 
	}
	Contact newContact;
	
	printf("\n---添加新联系人---\n");
	printf("name:");
	scanf("%s",newContact.name);
	printf("commpany:");
	scanf("%s",newContact.company);
	printf("title:");
	scanf("%s",newContact.title);
	printf("phone:");
	scanf("%s",newContact.phone);
	
	contacts[count++]=newContact;
	saveContacts(contacts, count);
	printf("\n添加成功 !\n");

}
