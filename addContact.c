#include <stdio.h>
#include <string.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];  // ͨѶ¼����
int count;                   // ��ǰ��ϵ������


void addContact(){
	if(count>=MAX_CONTACTS){
		printf("ͨѶ¼����");
		return; 
	}
	Contact newContact;
	
	printf("\n---�������ϵ��---\n");
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
	printf("\n��ӳɹ� !\n");

}
