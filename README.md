# PAPER SCISSORS ROCK!
### Author: Richard Vong (rvo16)

# BREIF DISCRIPTION:
This game is based on the classic Paper, Scissors, Rock game coded in C language and run in an arduino UCFUNKIT 4.

## HOW TO PLAY:
1. Turn on both devices.
2. Both players must push the navswitch push OR navswitch south OR navswitch north button on their controllers to start the game. 
   After pusing the button both plays will get to see their choices to select from (R = Rock, P = PAPER, S = SCISSORS)
3. Use the navswitch on the device to select your option to play. Once you have decided your option, push the
   navswitch west button to confirm your choice.
4. Once both players have confirmed their choices, the game will calculate the result of the game and display
   the result on each players device.
5. Press the navswitch push button to return to the title screen. Now you can play the game again!

## STRUCTURE OF THE PROGRAM:
1. Title  - Displays the scrolling text "PAPER SCISSORS ROCK".
2. Gameplay  - Displays the gameplay logic of the game (choosing characters and confirming your choice).
3. Results  - Displays the results of the game.


## MODULES:
game.c - The main game file.

displaytext.c - Contains the functions which display text on the device.

logic.c - Contains the various functions of the game logic.





