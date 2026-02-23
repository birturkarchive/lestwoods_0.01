#ifndef DOST_H
#define DOST_H

#include "printm.h"

#define DOST_MAX_FILES 16
#define MAX_FILENAME 36
#define DOST_BLOCK_SIZE 512

// DOST Object system
typedef struct {
    char filename[MAX_FILENAME];
    unsigned int start_addr;
    unsigned int length;
    unsigned char active;   // 1: Active, 0: Empty/Deleted
    unsigned char is_dir;   // 1: Folder (crkla), 0: File
} DOST_Entry;

// File table 
static DOST_Entry dost_table[DOST_MAX_FILES];

// --- DOST starting ---
void dost_init() {
    for(int i = 0; i < DOST_MAX_FILES; i++) {
        dost_table[i].active = 0;
        dost_table[i].is_dir = 0;
    }
}

int dost_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++; s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

void dost_strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0' && i < MAX_FILENAME - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// file creating system
void dost_crfile(const char* name, unsigned int size) {
    for(int i = 0; i < DOST_MAX_FILES; i++) {
        if(!dost_table[i].active) {
            dost_strcpy(dost_table[i].filename, name);
            dost_table[i].active = 1;
            dost_table[i].is_dir = 0; 
            dost_table[i].length = size;
            printm("\n successful: ");
            printm(name);
            printm(" object was created!\n");
            return;
        }
    }
    printm("Error: DOST was full!\n");
}

// --- ls: looks files and folders
void dost_ls() {
    printm("\nDOST Object system:\n");
    printm("--------------------------\n");
    int found = 0;
    for(int i = 0; i < DOST_MAX_FILES; i++) {
        if(dost_table[i].active) {
            if(dost_table[i].is_dir) printm("[DIR]  ");
            else printm("[FILE] ");
            
            printm(dost_table[i].filename);
            printm("\n");
            found = 1;
        }
    }
    if(!found) printm("There are no objects in the system....\n");
}

// --- crkla: create a folder ---
void dost_crkla(const char* name) {
    for(int i = 0; i < DOST_MAX_FILES; i++) {
        if(!dost_table[i].active) {
            dost_strcpy(dost_table[i].filename, name);
            dost_table[i].active = 1;
            dost_table[i].is_dir = 1; 
            printm("\nsuccessful: ");
            printm(name);
            printm(" was created.\n");
            return;
        }
    }
    printm("Hata: DOST system is full!!!\n");
}

// --- objdel: delete an object ---
void dost_objdel(const char* name) {
    for(int i = 0; i < DOST_MAX_FILES; i++) {
        if(dost_table[i].active && dost_strcmp(dost_table[i].filename, name) == 0) {
            dost_table[i].active = 0;
            printm("\nsuccessful: ");
            printm(name);
            printm(" object was deleted.\n");
            return;
        }
    }
    printm("Error, object was not found.\n");
}

// --- objren: Rename an object ---
void dost_objren(const char* old_name, const char* new_name) {
    for(int i = 0; i < DOST_MAX_FILES; i++) {
        if(dost_table[i].active && dost_strcmp(dost_table[i].filename, old_name) == 0) {
            dost_strcpy(dost_table[i].filename, new_name);
            printm("\nsuccessful\n");
            return;
        }
    }
    printm("\nError, source not found.\n");
}

#endif