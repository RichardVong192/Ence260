/** @file game.c
 *  @author Richard Vong (rvo16)
 *  @date 13 October 2019
 *  @brief The classic Paper Scissors Rock game
 *
 */

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "../fonts/font3x5_1.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "ledmat.h"
#include "displaytext.h"
#include "logic.h"

#define LOOP_RATE 500
#define PACER_RATE 500
#define MESSAGE_RATE 30

/* Define game states in the game */
typedef enum {TITLE_STATE, GAMEPLAY_STATE, RESULT_STATE}
game_stage_t;

/* Main program */
int main(void)
{
    /* Initalise stuff */
    system_init();
    pacer_init (PACER_RATE);
    navswitch_init ();
    ir_uart_init ();

    /* Initalise variables */
    game_stage_t state = TITLE_STATE;
    char character = 'R';
    char sent_char = ' ';
    char recv_char = ' ';
    int sent = 0;
    int recv = 0;

    /* Paced loop*/
    while(1) {
        pacer_wait();
        tinygl_update ();
        navswitch_update ();

        switch(state) {

        /* Title state with displays scrolling text */
        case TITLE_STATE:
            text_scroll(" PAPER SCISSORS ROCK! ");
            state = GAMEPLAY_STATE;
            break;
        /* Gameplay state for selecting choice and sending character */
        case GAMEPLAY_STATE:

            character = playGame(character);

            if (navswitch_push_event_p (NAVSWITCH_WEST)) {
                ir_uart_putc (character);
                sent_char = character;
                sent = 1;
            }
            if (ir_uart_read_ready_p()) {
                char buffer;
                buffer = ir_uart_getc();
                if (buffer == 'P' || buffer == 'R' || buffer == 'S') {
                    recv_char = buffer;
                    recv = 1;
                }
            }
            if (sent == 1 && recv == 1) {
                state = RESULT_STATE;
            }
            break;
        /* Results state for checking the result of the game */
        case RESULT_STATE:
            check_result(sent_char, recv_char);
            while (state == RESULT_STATE) {
                pacer_wait();
                tinygl_update ();
                navswitch_update ();

                /*Reset game back to title state to allow replay ability*/
                if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
                    state = TITLE_STATE;
                    sent_char = ' ';
                    recv_char = ' ';
                    sent = 0;
                    recv = 0;
                    break;
                }
            }
        }
    }
    return 0;
}
