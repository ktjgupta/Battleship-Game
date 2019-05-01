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

## Week 4

* Openframeworks development
	* Edited the draw function so it only shows the enemy board when user is done picking ships
	* Created orange rectangles that imitate the 5 classic ships of battle ship
	* Added a label to indicate size of ship when user clicks the ship
	* Tried to make ships draggable
		* Tried using drag events
		* Couldn't figure out how t ocorrelate draggable object with coordinates on board
		* Wasn't able to turn the ships like I wanted to
	* Decided that user can click two coordinates and indicate that's where the ship should be.
	* Steps:
		* User clicks ship and size is shown
		* User clicks first cooridnate where ship should go
			* Made this purple to indicate where the user clicked the first coordinate
		* User clicks again for final coordinate
		* If ship placement is validated, then ship is placed
			* Made ship turn gree nto indicate where ship is
		* Ship disappears once ship placed
		* When all ships are gone, regular game play continues
	* Centered the You Win and You Lose label
	* Added reset button

* Back-end Development
	* Made a validate method for ship placement
		* Uses the ships cooridnates
			* Checks to make sure correct ship size
			* Checks to make sure that it is either horizontal or vertical
			* Checks to make sure ship placement doesn't overlap any ships
	* Made a place ship method that places the ship in the right place once validated