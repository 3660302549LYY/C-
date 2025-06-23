#include <stdio.h>
#include <string.h>
#include "contactst.c"  
Contact contacts[MAX_CONTACTS];
int count;  

void modifyContact() {
    count = loadContacts(contacts); 
    displayAll();                    
	
    
    if (count == 0) {
        printf("ͨѶ¼Ϊ�գ�û����ϵ�˿��޸ġ�\n");
        return;
    }

    char targetName[NAME_LEN];
    printf("������Ҫ�޸ĵ���ϵ������: ");
    scanf("%s", targetName);

    int found = 0, i;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, targetName) == 0) {
            found = 1;
            break;  
        }
    }

    if (!found) {
        printf("δ�ҵ���Ϊ %s ����ϵ�ˣ��޷��޸ġ�\n", targetName);
        return;
    }

    
    int ccc;  
    while (1) {  
        printf("\n��ϵ�˹���ϵͳ���޸Ĳ˵���\n");
        printf("1. �޸Ĺ�˾\n");
        printf("2. �޸�ְλ\n");
        printf("3. �޸ĵ绰\n");
        printf("4. �޸�������Ϣ\n");
        printf("0. �˳��޸�\n");
        printf("������ѡ��");
        scanf("%d", &ccc);

        
        switch (ccc) {
            case 1:  
                printf("�������µĹ�˾����: ");
                char newCompany[COMPANY_LEN];
                scanf("%s", newCompany);
                strcpy(contacts[i].company, newCompany);
                printf("��ϵ�˹�˾�޸ĳɹ���\n");
                saveContacts(contacts, count);  
                break;

            case 2:  
                printf("�������µ�ְλ: ");
                char newTitle[TITLE_LEN];
                scanf("%s", newTitle);
                strcpy(contacts[i].title, newTitle);
                printf("��ϵ��ְλ�޸ĳɹ���\n");
                saveContacts(contacts, count);
                break;

            case 3:  
                printf("�������µĵ绰����: ");
                char newPhone[PHONE_LEN];
                scanf("%s", newPhone);
                strcpy(contacts[i].phone, newPhone);
                printf("��ϵ�˵绰�޸ĳɹ���\n");
                saveContacts(contacts, count);
                break;

            case 4: 
                printf("�������µĹ�˾����: ");
                char newCompanyAll[COMPANY_LEN];
                scanf("%s", newCompanyAll);
                strcpy(contacts[i].company, newCompanyAll);

                printf("�������µ�ְλ: ");
                char newTitleAll[TITLE_LEN];
                scanf("%s", newTitleAll);
                strcpy(contacts[i].title, newTitleAll);

                printf("�������µĵ绰����: ");
                char newPhoneAll[PHONE_LEN];
                scanf("%s", newPhoneAll);
                strcpy(contacts[i].phone, newPhoneAll);

                printf("��ϵ����Ϣ��ȫ���޸ġ�\n");
                saveContacts(contacts, count);
                break;

            case 0:  
                printf("�˳���ϵ���޸����̡�\n");
                return;

            default: 
                printf("��Ч���룬������ѡ��0-4��\n");
                break;
        }
    }
}
