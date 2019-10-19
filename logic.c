/** @file logic.c
 *  @author Richard Vong (rvo16)
 *  @date 13 October 2019
 *  @brief Functions for determining the logics ofthe game: Choice navigation and
 *         determining the result of the game
 *
 */

#include "logic.h"
#include "displaytext.h"

/* Char navigation for north navswitch push */
char letter_navigation_north (char character)
{
    if (character == 'R') {
        character = 'P';
    } else if (character == 'P') {
        character = 'S';
    } else if (character == 'S') {
        character = 'R';
    }
    return character;

}

/* Char navigation for south navswitch push */
char letter_navigation_south (char character)
{
    if (character == 'R') {
        character = 'S';
    } else if (character == 'P') {
        character = 'R';
    } else if (character == 'S') {
        character = 'P';
    }
    return character;

}

/* Check results of game */
void check_result(char sent_char, char recv_char)
{
    if (sent_char == 'R' && recv_char == 'P') {
        text_scroll(" LOSE");
    } else if (sent_char == 'P' && recv_char == 'R') {
        text_scroll(" WIN");
    } else if (sent_char == 'R' && recv_char == 'S') {
        text_scroll(" WIN");
    } else if (sent_char == 'P' && recv_char == 'S') {
        text_scroll(" LOSE");
    } else if (sent_char == 'S' && recv_char == 'R') {
        text_scroll(" LOSE");
    } else if (sent_char == 'S' && recv_char == 'P') {
        text_scroll(" WIN");
    } else if (sent_char == 'S' && recv_char == 'S') {
        text_scroll(" DRAW");
    } else if (sent_char == 'R' && recv_char == 'R') {
        text_scroll(" DRAW");
    } else if (sent_char == 'P' && recv_char == 'P') {
        text_scroll(" DRAW");
    }
}


/* Function to navigate through character selection */
char playGame (char character)
{
    if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
        tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
        display_character(character);
    }

    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
        character = letter_navigation_north (character);
        display_character (character);
    }

    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        tinygl_text_mode_set (TINYGL_TEXT_MODE_STEP);
        character = letter_navigation_south (character);
        display_character (character);
    }
    return character;
}
