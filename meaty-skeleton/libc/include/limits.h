#ifndef LIMITS_H
#define LIMITS_H
 
#include <stdint.h>
 
// Ограничения для знаковых типов
#define CHAR_BIT       8        // Количество бит в знаковом типе char
#define SCHAR_MIN     (-128)    // Минимальное значение для signed char
#define SCHAR_MAX      127       // Максимальное значение для signed char
#define UCHAR_MAX      255       // Максимальное значение для unsigned char
 
#define CHAR_MIN      SCHAR_MIN 
#define CHAR_MAX      SCHAR_MAX
 
#define SHRT_MIN     (-32768)    // Минимальное значение для short
#define SHRT_MAX      32767       // Максимальное значение для short
#define USHRT_MAX     65535       // Максимальное значение для unsigned short
 
#define INT_MIN      (-2147483647 - 1) // Минимальное значение для int
#define INT_MAX      2147483647         // Максимальное значение для int
#define UINT_MAX     4294967295U        // Максимальное значение для unsigned int
 
#define LONG_MIN     (-9223372036854775807LL - 1) // Минимальное значение для long
#define LONG_MAX     9223372036854775807LL         // Максимальное значение для long
#define ULONG_MAX    18446744073709551615ULL       // Максимальное значение для unsigned long
 
// Ограничения для intptr_t и uintptr_t
#define INTPTR_MIN   LONG_MIN
#define INTPTR_MAX   LONG_MAX
#define UINTPTR_MAX  ULONG_MAX
 
#endif // LIMITS_H
