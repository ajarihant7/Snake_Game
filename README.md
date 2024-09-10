# Snake_Game
This is a classic snake game built on top of C++. It's can be played on CMD.

There are three fucntions currently ->
1. gameSetup() -> This initializes my game state.
2. Box() -> This function draws the layout everytime in repeat. Its the basic layout of the game and has the snake and fruit updated everytime.
3. KeyBoard_IP() -> This function accepts the keyboard input.

The important function - gameLogic() is left to be written.

To run this file you will need g++ version 12.2.0

Next steps ->
Write the gameLogic() function.
Write the functions in seperate files.
Add a new fruit which is of 5 points and appears after every 5 normal fruit and appears only for 7 seconds.
Test a makefile for this if possible. 