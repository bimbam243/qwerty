#ifndef GDT_H
#define GDT_H
 
#include <stdint.h>
#include <cstdint.h>
 
// Структура GDT
struct gdt_entry
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));

/* Special pointer which includes the limit: The max bytes
*  taken up by the GDT, minus 1. Again, this NEEDS to be packed */
struct gdt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));
 


 
// Функции
void gdt_install();
//void create_descriptor(uint32_t base, uint32_t limit, uint16_t flag);
void gdt_set_gate(int, unsigned long , unsigned long, unsigned char, unsigned char );
void gdt_flush();
void check_segments();
 
 
#endif // GDT_H
