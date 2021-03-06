#include <util.h>

uint8_t *memcpy(uint8_t *dest, const uint8_t *src, int32_t count) {
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    for (; count != 0; count--) {
        *dp++ = *sp++;
    }
    return dest;
}

uint8_t *memset(uint8_t *dest, uint8_t val, int32_t count) {
    char *tmp = (char *)dest;
    for (; count != 0; count--) {
        *tmp++ = val;
    }
    return dest;
}

uint16_t *memsetw(uint16_t *dest, uint16_t val, int32_t count) {
    uint16_t *temp = (uint16_t *)dest;
    for (; count != 0; count--) {
        *temp++ = val;
    }
    return dest;
}

int32_t strlen(const char *str) {
    size_t size;
    for (size = 0; *str != '\0'; str++) {
        size++;
    }
    return size;
}

char *strcat(char *str1, const char *str2) {
    char *tmp = str1;

    while (*tmp != '\0') {
        tmp++;
    }

    while (*str2 != '\0') {
        *tmp++ = *str2++;
    }

    *tmp = '\0';
    return str1;
}

char *strcpy(char *dest, const char *src) {
    char *ptr = dest;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
    return ptr;
}

uint8_t inportb(uint16_t _port) {
    uint8_t rv;
    asm("inb %1, %0" : "=a" (rv): "dN" (_port));
    return rv;
}

void outportb(uint16_t _port, uint8_t _data) {
    asm("outb %1, %0" : : "dN" (_port), "a" (_data));
}