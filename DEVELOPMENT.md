# Development

## Testing Libraries
* Tested and played around with ofxGui examples
* Utilized ImGui and ran the first couple of examples

## Week 2 Code Review

* Started openframeworks development
	* Spent a lot of time trying to figure out how to make good buttons
	* Tried using ofxGui but buttons were pretty ugly and didn't want to use a panel for the game
	* Tried using ofxMSAInteractiveObject (external add-on)
		 *Proved to be overly complicated
	* Ended up using ofRectangle and created my own class
		* Used the properties mousepressed() and inside() to check if user was clicking button
		* Made it so that it changed colors when pressed
	* Created 100 buttons in 10X10 grid to mimic gameboard

* BackEnd Development
	* Created methods that randomizes ships on standard board to mimic enemy board
	* Figured out I had to set the random seed otherwise I get same results every time

* Combining Aspects
	* Made the app access the enemy board
	* Implemented method in class to change color based on if there was a ship or not in each square
		* If there is a ship, button should turn red when clicked
		* If there isnt, button should turn gray

## Week 3 Code Review

* Openframeworks development
	* Added the players board
		* Made sure that the enemy's move was registered
	* Made Gui look better
		* Made board proportional to screen
		* Tried to Make window automatically open in full screen
			* Didn't work, just made window bigger
		* Added BattleShip Title

* BackEnd Development
	* Made enemy choose a random tile on player board for its move
	* Made sure that the player moves, followed by enemy forever
	* Made enemy lag so that it looked a little more real
	* Made a funciton to check if a board had won
	* Implemented function and stopped game once someone wins