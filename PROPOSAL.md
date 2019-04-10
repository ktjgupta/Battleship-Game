# Proposal

## Normal Game
I would really like my project to simulate the classic battleship board game. The way this game works is that each player 
receives 5 ships of finite length: Carrier - 5, Battleship – 4, Cruiser – 3, Submarine – 3, Destroyer – 2. The player then has 
the option to put these submarines across their 10x10 grid either vertically or horizontally.  Once all the ships are placed, 
gameplay begins. Players take turn picking positions on the opponents grid where they think their ships are. If they don't hit 
anything, it is a miss. Otherwise, it is a hit and one of the ships loses health. If all of the gridpoints where one ship is 
positioned is hit, the ship is considered sunk. Once all of one player's ships are sunk, that player has lost and the other 
player is declared winner.

## My Implementation
What I plan to do for my implementation, is to keep the basic game but instead of 2 players playing against each other, the
player would have the opportunity to play against an AI. One of these AI will be dumb and make random choices for gridpoints, 
while the other one will be a smarter implementation and play the game how I would normally play it. In terms of user
interaction, I plan to implement a very simple gui that will display the players board like a grid and indicate which spaces 
you have your ships. There will also be another grid that represents the opponents board, so the player can see which squares
they have already chosen and mark if the player called a square that hit the opponent. Additionally I will have a popup text
that will either say Hit or Miss after each time the player calls a square.

## Libraries
I will be using the standard ofxGui libary as well as implementing a library called ofxImGui to help with the display aspect of
this project and to make it a much more clean design.

### Resources
* http://github.com - automatic!
[GitHub](http://github.com)