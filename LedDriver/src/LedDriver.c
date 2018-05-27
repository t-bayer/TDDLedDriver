/**
 * @file LedDriver.c
 * @brief File containing a driver for controlling a series of LEDs
 *
 * The module is writte to demonstrate the TDD approach. The main goal is to build a HAL for controlling LEDs and be able to\n
 * perform unit test easily. Therefore the module hides technology details of the controller and its physical memory access
 *
 * @author Timo Bayer
 * @date 25 May 2018
 */
#include "LedDriver.h"
#include <stdint.h>

static uint16_t * ledsAddress;

/**
 * @brief Initialize the leds
 *
 * The function initializes the corresponding memory space of the leds specified by the address parameter
 *
 * @param[in] address Pointer to the memory address for controlling the leds
 */
void LedDriver_Create(uint16_t * address){
	ledsAddress = address;
	*ledsAddress = 0;
}

/**
 * @brief Deinitialize the leds
 *
 * The function deinitializes the corresponding memory space
 *
 */
void LedDriver_Destroy(void){
}

/**
 * @brief Helper function to convert the led number to the corresponding bit within the memory block
 *
 * @param[in] ledNumber The number which needs to be converted
 */
static uint16_t convertLedNumberToBit(int ledNumber){
	return 1 << (ledNumber -1);
}

/**
 * @brief The function turns on a specified led
 *
 * Turning on a led is done by setting the corresponding bit within the memory block
 *
 * @param[in] ledNumber The number which needs to be turned on
 */
void LedDriver_TurnOn(int ledNumber){
	*ledsAddress = convertLedNumberToBit(ledNumber);
}

/**
 * @brief The function turns off a specified led
 *
 * Turning off a led is done by setting the corresponding bit within the memory block to low
 *
 * @param[in] ledNumber The number which needs to be turned off
 */
void LedDriver_TurnOff(int ledNumber){
	*ledsAddress = 0;
}

