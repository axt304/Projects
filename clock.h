/* clock.h -- header file for clock program
 *
 * Darren Provine, 17 July 2009
 *
 * Copyright (C) Darren Provine, 2009-2022, All Rights Reserved
 */

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include "LEDisplay.h"



/* model prototypes */
void start_timer(void);
void tick(int);
void set_offset(int);
int  get_offset(void);

/* controller prototypes */
void new_time(struct tm *);

/* view prototypes */
#include "view.h"
