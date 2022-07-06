
void kmain(void) {
    const char *str = "Kernel";
    char *vidptr = (char *) 0xb8000; /* Video memory beings here */
    unsigned int i = 0;
    unsigned int j = 0;

    /* Loop and clear screen
     * 25 lines of 80 colums, 
     * each element takes 2 bytes */
    while (j < 80 * 25 * 2) {
        /* Blank character */
        vidptr[j] = ' ';
        /* Attribute-byte - light grey on black screen */
        vidptr[j + 1] = 0x07;
        j = j + 2;
    }

    j = 0;

    while (str[j] != '\0') {
        vidptr[i] = str[j];

        vidptr[i + 1] = 0x07;
        ++j;
        i = i + 2;
    }
}
