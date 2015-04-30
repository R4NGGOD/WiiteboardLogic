#ifndef InputHandling_h
#define InputHandling_h
#include "PenAction.h"
#include <array>

class InputHandling
{
public:
	InputHandling() { };
	bool InputHandling::receiveBit(bool bit);
	PenAction InputHandling::getPenAction();
	PenAction InputHandling::analyzePenAction();
	~InputHandling();
private:
	std::array<bool, 8> InputHandling::byte;
	std::array<bool, 4> InputHandling::nibble;
	bool startBitReceived = false;
	int InputHandling::bitCounter = 0;
	void InputHandling::readFrame();
	PenAction InputHandling::penAction;

};

#endif