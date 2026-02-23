LESTWOODS Kernel v0.01
LestWoods is a standalone, x86-based micro-kernel developed from scratch without any standard library dependencies (-ffreestanding).
This project serves as a technical exploration into low-level system programming, hardware interfacing, and custom file system architecture.

Technical Specifications
Architecture: 32-bit x86 (i386 target).

Bootloader: Assembly-based boot.s compiled with NASM.

Video Interface: Direct VGA text buffer access at address 0xB8000 with custom scrolling logic.

I/O Management: Hardware-level keyboard polling via Port 0x64 and 0x60.

Scheduler Engine: Implements a custom Mini-Cos function using Taylor Series for system tick synchronization (bypassing traditional math libraries).

DOST File System (Direct Object System Table)
LestWoods features a unique RAM-based object management system named DOST.

Capacity: Supports up to 16 concurrent system objects.

Object Types: Native support for both files and directories using an is_dir flag system.

Operations: Implements crfile, crkla (directory creation), objdel (deletion), and objren (renaming).

The "Lest-Shell" Environment
The kernel boots into a custom shell environment that supports dynamic privilege escalation.

ls: Lists all active DOST objects.

get crown: Grants [ROOT] privileges to the user.

neo: Displays system architecture, kernel state, and build information.

reboot/exit: Handles safe system restarts and shutdowns via assembly out instructions.

LestWoods is more than a kernel;
"Lest we forget it."

Developed by birturkarchive, 2026. All rights reserved.