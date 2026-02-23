#ifndef SHELL_H
#define SHELL_H

#include "printm.h"
#include "keyboard.h"
#include "dost.h"
#include "nop.h"

int user_is_root = 0;

// 1. HELPFULLY COMMANDS
static int str_match(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0') return 1;
        i++;
    }
    return 0;
}

static void reboot() {
    printm("\nSystem rebooting...\n");
    gimme_a_sec();
    __asm__ __volatile__ ("outb %%al, %%dx" : : "a"(0xFE), "d"(0x64));
}

static void exit_os() {
    printm("\nLestWoods shutting down...\n");
    gimme_a_sec();
    __asm__ __volatile__ ("outw %%ax, %%dx" : : "a"(0x2000), "d"(0x604));
}

// 2. shell status and variables
static char input_buffer[128];
static int input_ptr = 0;
static char current_dir[36] = "lw"; // starting folder: lw

// 3. COMMAND PROCESSING CENTER
void process_command(const char *cmd) {
    if (str_match(cmd, "reboot")) {
        reboot();
    } 
    else if (str_match(cmd, "exit")) {
        exit_os();
    } 
    else if (str_match(cmd, "clear")) {
        cls();
    } 
    else if (str_match(cmd, "get crown")) {
        gimme_a_sec();
        printm("\n [ROOT] privileges granted. \n");
         user_is_root = user_is_root + 1;
    }
    else if (str_match(cmd, "ls")) {
        dost_ls();
    } 
    // CDD command: A folder simulation
    else if (cmd[0] == 'c' && cmd[1] == 'd' && cmd[2] == 'd' && cmd[3] == ' ') {
        dost_strcpy(current_dir, cmd + 4); 
        printm("\nDirectory changed to: ");
        printm(current_dir);
        printm("\n");
    }
    else if (cmd[0] == 'c' && cmd[1] == 'r' && cmd[2] == 'k' && cmd[3] == 'l' && cmd[4] == 'a') {
        dost_crkla(cmd + 6); 
    }  
    else if (cmd[0] == 'c' && cmd[1] == 'r' && cmd[2] == 'f' && cmd[3] == 'i' && cmd[4] == 'l' && cmd[5] == 'e') {
        dost_crfile(cmd + 7, 512); 
    } 
    else if (cmd[0] == 'o' && cmd[1] == 'b' && cmd[2] == 'j' && cmd[3] == 'd' && cmd[4] == 'e' && cmd[5] == 'l') {
        dost_objdel(cmd + 7);
    }
    else if (str_match(cmd, "help")) {
        printm("\nreboot: Reboots the system\n");
    printm("\nexit: Shuts down the computer\n");
    printm("\nget crown: Grant root privileges\n");
    printm("\nls: List all objects in the system\n");
    printm("\ncdd [name]: Change current directory\n");
    printm("The rest is in help2.");
    } 
    else if (str_match(cmd, "help2")) {
        printm("\ncrkla: Create a new directory\n"); 
    printm("\nobjdel: Delete an existing object\n");
    printm("\nobjren: Rename an existing object\n"); 
    } 
    else if (str_match(cmd, "neo")) {
        printm("\n      ___          User: USER / SUPERUSER"); 
        printm("\n     /  /\\         OS: LestWoods v0.01");
        printm("\n    /  / /         Kernel: LestWoods MS");
        printm("\n   /  / /          Architecture: x86 (32-bit)");
        printm("\n  /  / /__         Shell: Lest-shell");
        printm("\n /  /__/ /\\  "); // nothing.
        printm("\n \\________/        Status: Aktif & Gelistiriliyor\n");
    } 
    else if (str_match(cmd, "drop crown")) {
        exit_os();
    } else if (str_match(cmd, "dost --version")) {
        printm("\n Direct Object System Table v0.01 ramdisk \n");
        printm("\n All rights reserved \n");
    } else if (str_match(cmd, "lestwoods --version")) {
        printm("\n LESTWOODS v0.01 kernel \n");
        printm("\n All rights reserved \n");
    }  else if (cmd[0] == 'k' && cmd[1] == 'o' && cmd[2] == 'n' && cmd[3] == 'u' && cmd[4] == 's') {
        printm("\n ");
        printm(cmd + 5); 
        printm("\n ");
    } 
    else {
        printm("\n unknown command: ");
        printm(cmd);
    }
}

// 4. SHELL STARTER
void start_shell() {
    // First of all...
    printm("\nUser-space/");
    printm(current_dir);
    if(user_is_root > 0) {
        printm(" $ ");
    } else {
        printm(" # ");
    }
    

    while (1) {
        char c = get_keypress();
        
        if (c == '\n') { 
            input_buffer[input_ptr] = '\0';
            process_command(input_buffer);
            input_ptr = 0; 
            
            printm("\nUser-space/");
            printm(current_dir);
            if(user_is_root > 0) {
        printm(" $ ");
    } else {
        printm(" # ");
    }
            
        } 
        else if (c != 0 && input_ptr < 127) {
            input_buffer[input_ptr++] = c;
            char s[2] = {c, '\0'};
            printm(s); 
        }

    }

}

// That's it for now.
// You can remove this section if you're using this kernel for a standalone OS,
// but it is required for testing purposes.
// As mentioned, this project is for hobby purposes and is non-profit.
// LESTWOODS 0.01 "Lest we forget it."
#endif