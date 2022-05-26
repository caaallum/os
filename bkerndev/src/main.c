#include <util.h>
#include <scrn.h>

void _main() {
    init_video();

    int i = 5;

    set_text_colour(COLOUR_BLACK, COLOUR_GREEN);
    print("Hello World!");

    for (;;);
}