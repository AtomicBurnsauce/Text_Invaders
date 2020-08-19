#pragma once

#ifndef TEXTINVADERS_H_
#define TEXTINVADERS_H_

#include <string>
#include <vector>
/*
* Space Invaders:
* 
* (from: http://www.classicgaming.cc/classics/space-invaders/play-guide )
* 
* The object of the game is to shoot the invaders with your missle base while avoiding their shots and preventing an invastion.
* Amassing a high score is a further objective and one that must be prioritised against your continued survival.
* Each game screen starts with five rows of 11 invaders.
* The bottom 2 rows score 10 points per large invader, the middle 2 rows 20 points for each medium invader and the top row scores 30 points for
* each small invader. This makes each screen worth a total of 900 points.
* 
* The score for each screen can be dramatically incresed by the destruction of the 'mystery' value spaceships that frequently fly from
* one side of the screen to the other. The mystery UFO shouldhave a point value of 50 to 200 points.
* Temporary sanctuary can be sought beneath the 4 base shields. Shields are destructable by both the player and the aliens. Only part of the
* shield hit by either a player missle or an alien bomb should be destroyed, not the entire shield.
* 
* The invaders travel sideways and each time they touch the side they drow down 1 line.
* On screen 1 they need to drow 11 lines to reach the bottom and 'invade'.
* From screen 2 through screen 9 they start progressivly lower down the screen.
* At screen 10, the game reverts to the screen 1 start position and the cycle begins again.
* 
* There is no time limit, except for the fact that if you do not shoot them all before they reach the bottom of the screen, the game ends.
* 
* The more invaders the player shoots, the faster the remaining invaders move.
* When the invaders are low enough to touch the base shelters, they erase them as they pass. The last invader moves very quickly.
* 
* Any missiles dropped by an invader on the row above 'invasion' row will not harm the player's missle.
* 
* The aliens can have a maximum of 3 bombs on the screen at any one time. The player can have only 1 missile shot on the screen at any one time.
* 
* If the player is hit, the game should pause, and the player should be shown the exploding animation.
* 
* If an alien is hit, they should explode for a short period of time then disappear.
* 
* There should be an intro scree, game over screen (where the player can enter their name), and a high score screen.
* 
* The should be a high score table that can  been seen from the initial welcome screen and after the game is over and the player enters their 3 letter initals.
* 
* 
* All regular aliens are 2 by 4 in terms of size (2 rows by 4 columns)
* Player is 2 by 5
* Alien UFO is 2 by 6
* 
* Alien sprites:
* 30 point aliens:	/oo\	/oo\
*					<  >	/""\
* 
* 20 point aliens:	 ><		|><|
*					|\/|	/  \
* 
* 10 point aliens:	/--\	/--\
*					/  \	<  >
* 
* Alien explosion:	\|/
*					/|\
* 
* Alien bombs:		\ | / -
* 
* Alien UFO:		_/oo\_
*					-q--p-
* 
* Player sprite:	 _A_
*					-----
* 
* Player explosion:	,~^.' '+-`.
*					===== =====
* 
* Shield:			/IIIII\
*					IIIIIII
*					I/   \I
* 
* General Data
* ------------
* Player
* Aliens
* Shields
* Alien bombs
* Player missiles
* Game states
* Scores
* High Score Table
*
* Player
* ------
* Position
* Missile
* Animation State
* Size of the sprite
* Lives (3)
* Score
* 
* Shields
* -------
* Sprite - sprites can change
* Position
* 
* Alien Swarm (all the 10, 20, and 30 point aliens)
* ------
* Position
* Direction (Left or Right)
* Animation State
* Size of each alien
* State - alive, dead or explosion
* Alien bombs
* 
* Alien UFO
* ---------
* Size
* Position
* Points (50 - 200)
* 
* Position
* ---------
* x, y coordinate
* 
* Alien Bomb
* ----------
* Position
* animation state - \|/-
* 
* Missile (sprite - |)
* ---------
* Position
* 
* Game
* ------
* Game State
* Level
* Size of Window
* 
* Score
* -----
* Score value
* Name
* 
* High Score Table
* ----------------
* Vector of scores
*/

const char * PLAYER_SPRITE[] = {" =A= ", "====="};

const char PLAYER_MISSILE_SPRITE = '|';

const char * SHIELD_SPRITE[] = {"/IIIII\\", "IIIIIII", "I/   \\I"};

const char * ALIEN30_SPRITE[] = {"/oo\\", "<  >", "/oo\\", "/\"\"\\"};

const char * ALIEN20_SPRITE[] = {" >< ", "|\\/|", "|><|", "/  \\"};

const char * ALIEN10_SPRITE[] = {"/--\\", "/  \\", "/--\\", "<  >"};

const char * ALIEN_EXPLOSION[] = {"\\||/", "/||\\"};

enum
{
	SHIELD_SPRITE_HEIGHT = 3,
	SHIELD_SPRITE_WIDTH = 7,
	NUM_ALIEN_ROWS = 5,
	NUM_ALIEN_COLUMNS = 11,
	MAX_NUMBER_OF_ALIEN_BOMBS = 3,
	MAX_NUMBER_OF_LIVES = 3,
	PLAYER_SPRITE_WIDTH = 5,
	PLAYER_SPRITE_HEIGHT = 2,
	NOT_IN_PLAY = -1,
	PLAYER_MOVEMENT_AMOUNT = 2,
	PLAYER_MISSILE_SPEED = 1,
	FPS = 20,
	NUM_SHIELDS = 4,
	ALIEN_SPRITE_WIDTH = 4,
	ALIEN_SPRITE_HEIGHT = 2,
	ALIENS_X_PADDING = 1,
	ALIENS_Y_PADDING = 1,
	ALIEN_EXPLOSION_TIME = 4
};

enum AlienState
{
	AS_ALIVE = 0,
	AS_DEAD,
	AS_EXPLODING
};

enum GameState
{
	GS_INTRO = 0,
	GS_HIGH_SCORES,
	GS_PLAY,
	GS_PLAYER_DEAD,
	GS_WAIT,
	GS_GAME_OVER
};

struct Position
{
	int x;
	int y;
};

struct Size
{
	int width;
	int height;
};

struct Player
{
	Position position;
	Position missile;
	Size spriteSize;
	int animation;
	int lives; // max 3
	int score;
};

struct Shield
{
	Position position;
	char * sprite[SHIELD_SPRITE_HEIGHT];
};

struct AlienBomb
{
	Position position;
	int animation;
};

struct AlienSwarm
{
	Position position;
	AlienState aliens[NUM_ALIEN_ROWS][NUM_ALIEN_COLUMNS];
	AlienBomb bombs[MAX_NUMBER_OF_ALIEN_BOMBS];
	Size spriteSize;
	int animation;
	int direction; // > 0 for going right - < 0 for going left - 1 OR -1
	int numberOfBombsInPlay;
	int movementTime; // this is going to capture how fast the aliens should be going
	int explosionTimer; // This is going to capture how long to explode for
	int numAliensLeft; // this is to capture when to go to the next level
	int line; // This is to capture when the aliens win. Starts at the current level and decreases to 0
};

struct AlienUFO
{
	Position position;
	Size size;
	int points; // from 50 - 200
};

struct Score
{
	int score;
	std::string name;
};

struct HighScoreTable
{
	std::vector<Score> scores;
};

struct Game
{
	Size windowSize;
	GameState currentState;
	int level;
};

#endif /* TEXTINVADERS_H_ */