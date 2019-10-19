/** @file decision.h
 *  @author Richard Vong (rvo16)
 *  @date 13 October 2019
 *  @brief Functions for displaying text on the tinygl
 *
 */

#ifndef DISPLAYTEXT_H
#define DISPLAYTEXT_H

#include "system.h"
#include "tinygl.h"
#include "../fonts/font3x5_1.h"
#include "ir_uart.h"
#include "navswitch.h"
#include "ledmat.h"


/* Initalises tiny_gl and displays title screen text */
void text_scroll(char* text);

/* Displays single char on LED matrix */
void display_character (char character);



#endif
