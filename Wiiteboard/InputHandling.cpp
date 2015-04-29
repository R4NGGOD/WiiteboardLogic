#include "stdafx.h"
#include <iostream>
#include "InputHandling.h"
#include <array>



const std::array<bool, 4> LEFT_CLICK_UP_NIBBLE = { 0, 1, 0, 0 };
const std::array<bool, 4> RIGHT_CLICK_DOWN_NIBBLE = { 0, 0, 1, 0 };
const std::array<bool, 4> RIGHT_CLICK_UP_NIBBLE = { 0, 0, 1, 1 };
const std::array<bool, 4> MOUSE_DISCONNECT_NIBBLE = { 0, 0, 0, 0 };

//returns true if the 8 Bit limit is reached
bool InputHandling::receiveBit(bool bit) {
	if (!startBitReceived) {
		startBitReceived = !bit;
	} 
	if (startBitReceived) {
		if (bitCounter < 8) {
			byte[bitCounter] = bit;
			bitCounter++;
			return false;
		}
		else {
			readFrame();
			bitCounter = 0;
			return true;
		}
	}
	return false;
}

void InputHandling::readFrame() {
	bool lastBit = byte[0];
	int counter = 0;
	int byteIndex = 0;
	int index = 0;
	for (bool b : byte) {
		if (b == lastBit && byteIndex < 7) {
			counter++;
		}
		else {
			if (byteIndex == 7) {
				counter++;
			}
			if (lastBit) {
				counter = (counter - (counter % 2)) / 2;
			}
			else {
				counter = (counter + (counter % 2)) / 2;
			}
			int curIndex = index;
			for (; index < curIndex + counter; ++index) {
				nibble[index] = lastBit;
			}
			counter = 1;
		}
		byteIndex++;
		lastBit = b;
	}
}

PenAction InputHandling::analyzePenAction() {
	if (nibble == InputHandling::LEFT_CLICK_DOWN_NIBBLE) {
		penAction = LEFT_CLICK_DOWN;
	} else if (nibble == InputHandling::LEFT_CLICK_UP_NIBBLE) {
		penAction = LEFT_CLICK_UP;
	} else if (nibble == InputHandling::RIGHT_CLICK_DOWN_NIBBLE) {
		penAction = RIGHT_CLICK_DOWN;
	} else if (nibble == InputHandling::RIGHT_CLICK_UP_NIBBLE) {
		penAction = RIGHT_CLICK_UP;
	} else if (nibble == InputHandling::MOUSE_DISCONNECT_NIBBLE) {
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
