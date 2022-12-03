/* LEDisplay.h -- header file for 7segment clock library file
 *
 * Darren Provine, 14 August 2009
 *
 * Copyright (C) Darren Provine, 2009-2022, All Rights Reserved
 */

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
