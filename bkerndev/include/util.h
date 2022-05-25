#ifndef __UTIL_H__
#define __UTIL_H__

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef uint32_t size_t;
typedef uint32_t uintptr_t;
typedef float float32_t;
typedef double float64_t;

typedef uint8_t bool;
#define true (1)
#define false (0)

#define NULL (0)

#ifndef asm
#define asm __asm__ __volatile__
#endif //asm

extern uint8_t *memcpy(uint8_t *dest, const uint8_t *src, int32_t count);

extern uint8_t *memset(uint8_t *dest, uint8_t val, int32_t count);

extern uint16_t *memsetw(uint16_t *dest, uint16_t val, int32_t count);

extern int32_t strlen(const char *str);

extern uint8_t inportb(uint16_t _port);

extern void outputb(uint16_t _port, uint8_t _data);

#endif //__UTIL_H__
