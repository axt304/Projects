VIRTUAL DIGITAL CLOCK

In addition to this file, you will want to read the files
'1-ampm+date.txt', '2-LED.txt', and '3-BUTTONS.txt'.

 **

We're building a digital clock with an LED display.  Our company has
ordered a million LED clock faces delivered to the factory.

The display manufacturer has sent us some files so we can work on our
code while waiting for the hardware to be delivered:

   LED-layout.txt : explains which bits turn on the LEDs
   LED-display.h  : prototypes and declarations needed for our compiler
   LED-display.o  : executable object code for a simulated LED panel

(They did not send us the C source files, because they consider their
source to be a trade secret.)


Right now, we have a stub clock which only shows the time in 24-hour
mode, as plain text.

We have to do two things to be ready for manufacture:

 1) Modify the file 'view.c' to handle all the possible modes
    (am/pm, date, test) which our clock might be in.
    This has to work before we can go on to step 2.

 2) a) Figure out how to put bits in the right places to turn on
       the LEDs.

    b) Process button clicks to change the mode.

This two consecutive programming assignments.

 *

Our clock will use a Model-View-Controller architecture.  This is a
design which (like encapsulation familiar from object-oriented
programming) keeps parts of the design separate.

MVC architecture can be applied to many programs.  For a chess
program, for example:

      Model: all the code that checks to see if a move is legal
             and picks the next move for the computer.  This will
             be where the array is that keeps the current board position.

       View: the user interface that the user interacts with.  This is
             also the buttons or the graphical window they click the
             mouse on, or whatever.

 Controller: the main routine that starts the program, and manages
             getting information to the model and view.  (Model and
             view do not talk directly to each other.)

Advantages to a design like this include having separate teams work on
separate parts of the program: the team building the View can design
3-D graphics of the chess board and pieces and such using only a stub
for the Model, which just makes any moves at all, legal or not - they
don't care about that part, they just need it to look right.  And the
team building the Model can have an interface where you just type in
moves like '22-23', meaning 'move the piece on square 22 to square
23', and work to make sure it only allows legal moves and plays the
game well.  They don't need the final interface to work on their part.
Also, they can have two different models play against themselves to
see which is better, without having to figure out how to send a mouse
click through the interface.

If you're taking an AI class, you're building a Model, not a View: your
grade will depend on how well your program plays checkers, or whatever,
not on what it looks like.  And if you're doing graphic design, it's the
other way around.


For our clock, the breakdown works like this:

      Model: a real-time clock that fires every second.  (This part
             is already completed.)

             functions in the model:
                get_offset()  - find out what the time offset is
                set_offset()  - set a new time offset
                tick()        - function that's called when a second
                                passes (when the clock ticks)
                                This function calls 'new_time()'
                                in the controller, and sends it a
                                'struct tm' object.
                start_timer() - get the realtime clock running


       View: The clock display.  The first one will just do plain
             text output, like: '12:03:47 pm' (without the quotes).
             It will have to know whether it's in am/pm mode, or
             date mode, and (for the final version) whether it's in
             LED mode.

             functions in the view:
                set_view_properties() - set the mode bits
                get_view_properties() - return the mode bits
                do_test()             - turn on and off all the LEDs
                                        to make sure they work
                make_timestring()     - take a tm object and turn
                                        into a string (so it can
                                        be printed)
                show_text()           - print the time as a string
                show_led()            - show the time on the LEDs
                show()                - call either show_text() or
                                        show_led(), depending on
                                        the mode bits

             Except for make_timestring(), do_test(), and show_led(),
             these functions are completed.


 Controller: Reads the options from the command line ('-a' means
             use am/pm, '-l' means use the LEDs, and so on) and sets
             up the properties of the View.  Also starts the Model
             running.  When the model signals that a second has
             passed, the controller gets the time and passes it to
             the View.

             functions in the view:
                version()     - show the version
                usage()       - print a help message
                stop_clock()  - turn off the LEDs before quitting
                main()        - get everything running
                new_time()    - send the tm object given by the model
                                off to the view
                process_key() - handle a key or button press

             Except for process_key(), these functions are complete.
 *

Things To Notice:

1) The Makefile includes a LIBRARY macro, for some of the special
   features needed to do full-screen display.

2) A stub 'ledshow()' is in 'view.c', but it's just sample code.

3) 'view.h' defines some bits which can be switched on or off to
   set the various modes.  The controller calls 'get_view_properties()'
   and 'set_view_properties()' in order to read/set the bits.

