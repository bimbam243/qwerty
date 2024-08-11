#include "gdt.h"
#include <stdio.h>
#include <cstdint.h>
#include <stdint.h>
#include <kernel/tty.h>



/* Our GDT, with 3 entries, and finally our special GDT pointer */
struct gdt_entry gdt[3];
struct gdt_ptr gp;

/* This will be a function in start.asm. We use this to properly
*  reload the new segment registers */

void gdt_flush()
{
    asm volatile 
    (
        "lgdt gp\n"      // Загрузка GDT по адресу gdt
        "mov $0x10, %%ax\n" // 0x10 - это смещени6  е в GDT для нашего сегмента данных
        "mov %%ax, %%ds\n"
        "mov %%ax, %%es\n"
        "mov %%ax, %%fs\n"
        "mov %%ax, %%gs\n"
        "mov %%ax, %%ss\n"
        "ljmp $0x08, $1f\n" // 0x08 - это смещение к нашему сегменту кода; далекий переход
        "1:\n"
        "ret\n"
        :
        :
        : "memory"           // Указание компилятору, что память может быть изменена
    );

}

void check_segments() {
    unsigned short ds, es, fs, gs, ss;
 
    asm volatile (
        "mov %%ds, %0\n"
        "mov %%es, %1\n"
        "mov %%fs, %2\n"
        "mov %%gs, %3\n"
        "mov %%ss, %4\n"
        : "=r" (ds), "=r" (es), "=r" (fs), "=r" (gs), "=r" (ss)
        :
        :
    );
 
    printf("DS: 0x%04x\n", ds);
    printf("ES: 0x%04x\n", es);
    printf("FS: 0x%04x\n", fs);
    printf("GS: 0x%04x\n", gs);
    printf("SS: 0x%04x\n", ss);
}

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

/* Should be called by main. This will setup the special GDT
*  pointer, set up the first 3 entries in our GDT, and then
*  finally call gdt_flush() in our assembler file in order
*  to tell the processor where the new GDT is and update the
*  new segment regi sters */
void gdt_install() {   
    printf("bbb\n");
    /* Setup the GDT pointer and limit */
    gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = (unsigned long) &gdt;

    /* Our NULL descriptor */
    gdt_set_gate(0, 0, 0, 0, 0);

    /* The second entry is our Code Segment. The base address
    *  is 0, the limit is 4GBytes, it uses 4KByte granularity,
    *  uses 32-bit opcodes, and is a Code Segment descriptor.
    *  Please check the table above in the tutorial in order
    *  to see exactly what each value means */
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    /* The third entry is our Data Segment. It's EXACTLY the
    *  same as our code segment, but the descriptor type in
    *  this entry's access byte says it's a Data Segment */
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
    
    /* Flush out the old GDT and install the new changes! */
    gdt_flush();
    check_segments();
    
}







 

