#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,			// Add Ladder Action
	ADD_SNAKE,			// Add Snake Action	
	ADD_CARD,			// Add Card Action	
	COPY_CARD,			// Copy Card Action
	CUT_CARD,			// Cut Card Action
	PASTE_CARD,			// Paste Card Action
	EDIT_CARD,			// Edit Card Action
	DELETE_GAME_OBJECT,	// Deletes a Game Object the user chooses
	SAVE_GRID,			// Saves the Designed Grid
	OPEN_GRID,			// Open a Saved Grid
	EXIT,				// Exit Application
	TO_PLAY_MODE,		// Go to Play Mode

	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,			// Roll Dice Action
	INPUT_DICE_VALUE,	// Asks the user ti insert Dice value between 1-6
	NEW_GAME,			// Restarts the Game from the beginning
	TO_DESIGN_MODE,		// Go to Design Mode
	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif