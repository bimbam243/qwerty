#ifndef _STDDEF_H
#define _STDDEF_H
 
// Определения стандартных типов
typedef unsigned long size_t;
typedef long ptrdiff_t;
 
// Определение макроса NULL
#define NULL ((void*)0)
 
// Макрос для получения смещения в структуре
#define offsetof(TYPE, MEMBER) ((size_t) &(((TYPE *)0)->MEMBER))
 
#endif /* _STDDEF_H */
