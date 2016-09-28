#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /*
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
    */

	unsigned int idx = hash(lastName);
	pHead = hash_table[idx];
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
	}
	return NULL;
}

entry *hash_table[HASH_TABLE_SIZE] = {NULL};
entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    /*
	e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
	*/

	unsigned int idx = hash(lastName);
	if(hash_table[idx] == NULL) {
		hash_table[idx] = (entry *) malloc(sizeof(entry));
		hash_table[idx]->pNext = NULL;
		strcpy(hash_table[idx]->lastName, lastName);
	} else {
		/*
		e = hash_table[idx];

		while(e->pNext != NULL) {
			e = e->pNext;
		}
		e->pNext = (entry *) malloc(sizeof(entry));	
		e = e->pNext;
		e->pNext = NULL;
		strcpy(e->lastName, lastName);
		*/
		entry *h;
		h = (entry *) malloc(sizeof(entry));
		strcpy(h->lastName, lastName);
		h->pNext = hash_table[idx];
		hash_table[idx] = h;
	}
		
	return e;	
}

unsigned int hash(char *key)
{
	unsigned int hashVal = 0;
	while (*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }

    return hashVal % HASH_TABLE_SIZE;
}

