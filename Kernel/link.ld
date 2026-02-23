ENTRY(_start)
SECTIONS
{
    . = 1M;

    .text : {
        *(.multiboot)
        *(.text)
        *(.doom_section)
    }

    .data : { *(.data) }
    .bss  : { *(.bss) }
}