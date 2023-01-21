/* VIEW OPTIONS
 *
 * AMPM (default is 24-hour) --+
 * date ---------------------+ |
 * LED mode ---------------+ | |
 * reserved -------------+ | | |
 *                       | | | |
 * test -----------+     | | | |
 *                 |     | | | |
 *                 |     | | | |
 *                 V     V V V V
 *           0 0 0 0     0 0 0 0
 * unused ---+-+-+
 */
#define  AMPM_MODE  0x01
#define  DATE_MODE  0x02
#define  LED_MODE   0x04
#define  TEST_MODE  0x10

// set packed bits for what you want
void set_view_properties( int );
int get_view_properties( void );

void show(struct tm *);

