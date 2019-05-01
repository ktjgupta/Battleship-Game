#include "GameSquare.h"
#include "catch.hpp";
TEST_CASE("ChangeColor Method") {
	ofSoundPlayer player;
	GameSquare square;
	SECTION("Ship Present") {
		REQUIRE(square.ChangeColor('S', player) == 'H');
	}
	SECTION("No Ship Present") {
		REQUIRE(square.ChangeColor('_', player) == 'M');
	}
	SECTION("Other marker") {
		REQUIRE(square.ChangeColor('M', player) == 'M');
		REQUIRE(square.ChangeColor('H', player) == 'H');
		REQUIRE(square.ChangeColor('5', player) == '5');
	}
}