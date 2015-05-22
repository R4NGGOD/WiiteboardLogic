//AUTHOR: Alexander Ciupka

#include "stdafx.h"
#include <iostream>
#include "InputHandling.h"
#include <array>

/*
	Nibble arrays (length=4, bool as datatype)
	represent the different click/mouse options
*/
std::array<bool, 4> LEFT_CLICK_DOWN_NIBBLE = { 0, 0, 0, 1 };
std::array<bool, 4> LEFT_CLICK_UP_NIBBLE = { 0, 1, 0, 0 };
std::array<bool, 4> RIGHT_CLICK_DOWN_NIBBLE = { 0, 0, 1, 0 };
std::array<bool, 4> RIGHT_CLICK_UP_NIBBLE = { 0, 0, 1, 1 };
std::array<bool, 4> MOUSE_DISCONNECT_NIBBLE = { 0, 0, 0, 0 };
std::array<bool, 4> MOVE_MOUSE_NIBBLE = { 0, 1, 1, 1 };
/*
	2 start bits
*/
std::array<bool, 2> CORRECT_START_BITS = { 0, 1 };

/*
	Adds a new bit to the received bits
	returns true if the new bit is the last bit needed
	returns false if the new bit isnt the last bit needed
*/
bool InputHandling::receiveBit(bool bit) {
	if (lastBit && !startBitReceived) {
		startBitReceived = !bit;
	}
	if (startBitReceived) {
		byte[bitCounter] = bit;
		//Checks if the added bit, is the 12th
		if (bitCounter >= 11) {
			bitCounter = 0;
			//Calls method to analyze the received bits
			readFrame();
			startBitReceived = false;
			lastBit = false;
			return true;
		}
		bitCounter++;
	}
	else {
		lastBit = bit;
	}
	return false;
}

/*
	Analyzes the 12 received bits and checks if the start bits are valid
*/

bool InputHandling::readFrame() {
	lastBit = byte[0];
	int counter = 0;
	int byteIndex = 0;
	int startBitIndex = 0;
	int index = 0;
	//for each loop through the received bits
	for (bool b : byte) {
		//Checks if 4 bits were checked yet
		if (byteIndex == 4) {
			//Checks if the received start bits are valid
			if (translatedBits[0] != CORRECT_START_BITS[0] || translatedBits[1] != CORRECT_START_BITS[1]) {
				nibble = MOVE_MOUSE_NIBBLE;
				return false;
			}
		}
		//Checks if last bit is the same than the new one and if the bit is not the last one
		if (b == lastBit && byteIndex < 11) {
			counter++;
		}
		else {
			if (byteIndex == 11) {
				counter++;
			}
			if (lastBit) {
				//calculates the ammount of TRUE bits
				counter = (counter - (counter % 2)) / 2;
			}
			else {
				//calculates the ammount of FALSE bits
				counter = (counter + (counter % 2)) / 2;
			}
			int curIndex = index;
			for (; index < curIndex + counter; ++index) {
				std::cout << "Index: " << index;
				translatedBits[index] = lastBit;
			}
			//If the last bit is true and the index of the byte array is odd
			if (lastBit && byteIndex % 2 == 1) {
				//When its true	the ammount of read FALSE in a row is set to 1 -> because FALSE is 'dominant'
				counter = 1;
			}
			//Else if the of the byte array is odd, but the last bit was FALSE, sets the ammount of received TRUE in a row to 0
			else if (byteIndex % 2 == 1) {
				counter = 0;
			}
			//Else sets the ammount of read TRUE or FALSE in a row to 1
			else {
				counter = 1;
			}
		}
		byteIndex++;
		lastBit = b;
	}
	//copies the 6-Bit long translatedBits array into the nibble array
	for (int i = 2; i < translatedBits.size(); ++i) {
		nibble[i - 2] = translatedBits[i];
	}
	return true;
}

/*
	returns the analyzeed penAction
*/

PenAction InputHandling::analyzePenAction() {
	for (bool b : nibble) {
		std::cout << "\n" << "Nibble: " << b << "\n";
	}
	if (nibble == LEFT_CLICK_DOWN_NIBBLE) {
		penAction = LEFT_CLICK_DOWN;
	}
	else if (nibble == LEFT_CLICK_UP_NIBBLE) {
		penAction = LEFT_CLICK_UP;
	}
	else if (nibble == RIGHT_CLICK_DOWN_NIBBLE) {
		penAction = RIGHT_CLICK_DOWN;
	}
	else if (nibble == RIGHT_CLICK_UP_NIBBLE) {
		penAction = RIGHT_CLICK_UP;
	}
	else if (nibble == MOUSE_DISCONNECT_NIBBLE) {
		penAction = MOUSE_DISCONNECT;
	} else {
		penAction = MOVE_MOUSE;
	}
	return penAction;
}

PenAction InputHandling::getPenAction() {
	return analyzePenAction();
}



InputHandling::~InputHandling()
{
}
