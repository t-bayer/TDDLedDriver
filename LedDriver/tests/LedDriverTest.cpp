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



