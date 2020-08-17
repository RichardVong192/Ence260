/** @file logic.h
 *  @author Richard Vong (rvo16)
 *  @date 13 October 2019
 *  @brief Functions for determining the logics ofthe game: Choice navigation and
 *         determining the result of the game
 *
 */

#ifndef LOGIC_H
#define LOGIC_H

#include "system.h"
#include "tinygl.h"
#include "../fonts/font3x5_1.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "ledmat.h"


/* Char navigation for north navswitch push */
char letter_navigation_north (char character);

/* Char navigation for south navswitch push */
char letter_navigation_south (char character);

/* Check results of game */
void check_result(char sent_char, char recv_char);

/* Function to navigate through character selection */
char playGame (char character);



#endif
