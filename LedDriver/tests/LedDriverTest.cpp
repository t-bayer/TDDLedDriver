extern "C"
{
#include "LedDriver.h"
#include <stdint.h>
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedDriver)
{
	uint16_t virtualLeds;
    void setup()
    {
      LedDriver_Create(&virtualLeds);
    }

    void teardown()
    {
       LedDriver_Destroy();
    }
};

TEST(LedDriver, LedsAreOffAfterCreate)
{
	virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	LONGS_EQUAL(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnMultipeLeds){
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	LONGS_EQUAL(0x180, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed){
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	LONGS_EQUAL(0xFF7F, virtualLeds);
}

TEST(LedDriver, TurnAllOn){
	LedDriver_TurnAllOn();
	LONGS_EQUAL(0xFFFF, virtualLeds);
}

TEST(LedDriver, LedMemoryIsNotReadable){
	virtualLeds = 0xFFFF;
	LedDriver_TurnOn(8);
	LONGS_EQUAL(0x80, virtualLeds);
}

TEST(LedDriver, UpperAndLowerBounds){
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	LONGS_EQUAL(0x8001, virtualLeds);
}

TEST(LedDriver, OutOfBoundsChangesNothing){
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(17);
	LedDriver_TurnOn(3141);
	LONGS_EQUAL(0x0, virtualLeds);
}






