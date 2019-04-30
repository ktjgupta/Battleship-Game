#include "GameSquare.h"

/*Method that changes the color of the given square and returns char value*/
char GameSquare::ChangeColor(char val, ofSoundPlayer hit_sound) {
	if (val == 'S') {
		color = ofColor::red;
		hit_sound.play();
		return 'H';
	}
	if (val == '_') {
		color = ofColor::gray;
		return 'M';
	}
	return val;
}