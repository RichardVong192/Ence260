/** @file decision.c
 *  @author Richard Vong (rvo16)
 *  @date 13 October 2019
 *  @brief Functions for displaying text on the tinygl
 *
 */

#include "displaytext.h"
#define LOOP_RATE 500
#define PACER_RATE 500
#define MESSAGE_RATE 30


/* Initalises tiny_gl and displays title screen text */
void text_scroll(char* text)
{
    tinygl_init (LOOP_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);

    tinygl_text(text);
}

/* Displays single char on LED matrix */
void display_character (char character)
{
    tinygl_clear();
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}
