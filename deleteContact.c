#include <stdio.h>
#include <string.h>
#include "contactst.c"


Contact contacts[MAX_CONTACTS];  
int count;                  


void deleteContact() {
	count = loadContacts(contacts); 
	displayAll();                  

	
	
    if (count == 0) {
        printf("ͨѶ¼Ϊ�գ�����ϵ�˿�ɾ����\n");
        return;
    }
    char delName[NAME_LEN];
    printf("������Ҫɾ����ϵ�˵�������");
    scanf("%s", delName);
    
    int i, findIndex = -1;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, delName) == 0) {
            findIndex = i;
            break;
        }
    }
    
    if (findIndex == -1) {
        printf("δ�ҵ���Ϊ��%s������ϵ�ˣ�ɾ��ʧ�ܣ�\n", delName);
        return;
    }
    
    for (i = findIndex; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--; 
    printf("��ϵ�ˡ�%s��ɾ���ɹ���\n", delName);
}
