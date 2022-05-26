#include <scrn.h>
typedef char *va_list;
#define va_start(ap,parmn) (void)((ap) = (char*)(&(parmn) + 1))
#define va_end(ap) (void)((ap) = 0)
#define va_arg(ap, type) \
    (((type*)((ap) = ((ap) + sizeof(type))))[-1])

uint16_t *textmemptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void _scroll(void) {
    unsigned blank, tmp;

    blank = 0x20 | (attrib << 8);

    if (csr_y >= 25) {
        tmp = csr_y - 25 + 1;
        memcpy(textmemptr, textmemptr + tmp * 80, (25 - tmp) * 80 * 2);

        memsetw(textmemptr + (25 - tmp) * 80, blank, 80);
        csr_y = 25 - 1;
    }
}

void _move_csr(void) {
    unsigned tmp;

    tmp = csr_y * 80 + csr_x;

    outportb(0x3D4, 14);
    outportb(0x3D5, tmp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, tmp);
}

void cls() {
    unsigned blank;
    int i;

    blank = 0x20 | (attrib << 8);

    for (i = 0; i < 25; i++) {
        memsetw(textmemptr + i * 80, blank, 80);
    }

    csr_x = 0;
    csr_y = 0;
    _move_csr();
}

void print_char(unsigned char c) {
    uint16_t *where;
    unsigned att = attrib << 8;

    switch(c) {
        case 0x08: // Backspace
            if (csr_x != 0) {
                csr_x--;
            }
            break;

        case 0x09: // Tab
            csr_x = (csr_x + 8) & ~(8 -1);
            break;

        case '\r': // Carriage return
            csr_x = 0;
            break;

        case '\n': // New line
            csr_x = 0;
            csr_y++;
            break;

        default:
            if (c >= ' ') {
                where = textmemptr + (csr_y * 80 + csr_x);
                *where = c | att;
                csr_x++;
            }
            break;
    }
    if (csr_x >= 80) {
        csr_x = 0;
        csr_y++;
    }

    _scroll();
    _move_csr();
}

void print(unsigned char *str) {
    int i;

    for (i = 0; i < strlen(str); i++) {
        print_char (str[i]);
    }
}

void set_text_colour(uint8_t foreground, uint8_t background) {
    attrib = (background << 4) | (foreground & 0x0F);
}

void init_video() {
    textmemptr = (uint16_t *)0xB8000;
    cls();
}