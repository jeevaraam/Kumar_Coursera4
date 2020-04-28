/**
 * @file data.h
 * @brief Abstraction of Data conversion operations
 *
 * This header file provides an abstraction of Data Conversion Operations
 *
 * @author Jeevaraam Kumar
 * @date April 28 2020
 *
 */

#include "memory.h"

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts the integer to ASCII string 
 *
 * Handles Conversion of integer to ASCII string
 *
 * @param data Input integer data
 * @param ptr Address pointer to which converted string should be placed
 * @param base Input base of the integer
 *
 * @return Length of the string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts the ASCII string to Integer
 *
 * Handles Conversion of ASCII string to integer
 *
 * @param ptr Address Pointer in which the string is present
 * @param digits No of digits present in the input
 * @param base Input base of the integer
 *
 * @return Converted integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif