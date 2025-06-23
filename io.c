#include <stdio.h>
#include <stdlib.h>
#include "contactst.c"
/*
void saveContacts(Contact contacts[], int count) {
    FILE *fp = fopen(CONTACTS_FILE, "wb");
    if (fp == NULL) {
        perror("�޷����ļ�������ϵ��");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(contacts, sizeof(Contact), count, fp);
    fclose(fp);
}


int loadContacts(Contact contacts[]) {
    FILE *fp = fopen(CONTACTS_FILE, "rb");
    if (fp == NULL) {
        return 0;
    }
    int count;
    fread(&count, sizeof(int), 1, fp);
    fread(contacts, sizeof(Contact), count, fp);
    fclose(fp);
    return count;
}
*/

// ������ϵ�˵��ı��ļ�
void saveContacts(Contact contacts[], int count) {
    FILE *fp = fopen(CONTACTS_FILE, "w");
    if (fp == NULL) {
        perror("�޷����ļ�������ϵ��");
        return;
    }
    int i;
    // д����ϵ������
    fprintf(fp, "%d\n", count);
    
    // ѭ��д��ÿ����ϵ����Ϣ
    for (i = 0; i < count; i++) {
        // ʹ�ö��ŷָ��ֶΣ����зָ���¼
        fprintf(fp, "%s,%s,%s,%s\n", 
                contacts[i].name, 
                contacts[i].company, 
                contacts[i].title, 
                contacts[i].phone);
    }
    
    fclose(fp);
}

// ���ı��ļ�������ϵ��
int loadContacts(Contact contacts[]) {
	int ii;
    FILE *fp = fopen(CONTACTS_FILE, "r");
    if (fp == NULL) {
        // �ļ������ڣ�����0����ϵ��
        return 0;
    }
    
    int count;
    // ��ȡ��ϵ������
    fscanf(fp, "%d\n", &count);
    
    // ȷ���������������
    if (count > MAX_CONTACTS) {
        count = MAX_CONTACTS;
    }
    
    // ѭ����ȡÿ����ϵ����Ϣ
    for (ii = 0; ii < count; ii++) {
        // ��ȡһ�����ݣ���ʽΪ "name,company,title,phone"
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", 
               contacts[ii].name, 
               contacts[ii].company, 
               contacts[ii].title, 
               contacts[ii].phone);
    }
    
    fclose(fp);
    return count;
}    
