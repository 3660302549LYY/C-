#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100
#define NAME_LEN 30
#define COMPANY_LEN 50
#define TITLE_LEN 50
#define PHONE_LEN 20
#define CONTACTS_FILE "save.lbb"

typedef struct {
    char name[NAME_LEN];
    char company[COMPANY_LEN];
    char title[TITLE_LEN];
    char phone[PHONE_LEN];
} Contact;


