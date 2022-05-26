#include <gdt.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} ATTRIBUTE_PACKED;

struct gdt_ptr {
    uint16_t limit;
    uint8_t base;
} ATTRIBUTE_PACKED;

struct gdt_entry gdt[3];
struct gdt_ptr gp;


