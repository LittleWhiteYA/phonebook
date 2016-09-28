#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 42737

#define OPT 1
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __NAME_DETAIL *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __NAME_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

entry *hash_table[HASH_TABLE_SIZE];

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *e);
unsigned int hash(char *key);

#endif
