
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>
#include <term.h>
#include <stdlib.h>

typedef unsigned char digit;

digit *get_display_location(void);

void start_display(void);
void end_display(void);

void set_title_bar(char *);

void display(void);


void get_key(void);
typedef unsigned short int keybits;

int register_keyhandler( void(*f)(keybits) );

void set_key_text(int, char *);
