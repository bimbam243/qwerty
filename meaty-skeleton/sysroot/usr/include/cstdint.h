#ifndef CSTDINT_H
#define CSTDINT_H
 
// Определение фиксированных по размеру целочисленных типов
#include <limits.h>
 
typedef signed char int8_t;               // 8-битный знакованный тип
typedef unsigned char uint8_t;            // 8-битный беззнакованный тип
typedef short int int16_t;                // 16-битный знакованный тип
typedef unsigned short int uint16_t;      // 16-битный беззнакованный тип
typedef int int32_t;                      // 32-битный знакованный тип
typedef unsigned int uint32_t;            // 32-битный беззнакованный тип
typedef long long int int64_t;            // 64-битный знакованный тип
typedef unsigned long long int uint64_t;  // 64-битный беззнакованный тип
 
#endif // CSTDINT_H
