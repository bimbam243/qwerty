#include <stdio.h>
#include <stdint.h>
#include <kernel/tty.h>
#include "gdt.h"
#include <cstdint.h>

void kernel_main(void) {
    terminal_initialize();
    printf("hello!!!!!!!!!\n"); 
    gdt_install();
	
    printf("hello!!!!!!!!!\n");    
   
}
