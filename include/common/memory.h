/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Jeevaraam Kumar
 * @date April 28 2020
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Moves the specified data from one memory to another memory 
 *
 * Handles memory corruption
 *
 * @param src Pointer to data source
 * @param dst Pointer to data destination
 * @param length Length of the data to be moved
 *
 * @return Pointer of destination address
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Moves the specified data from one memory to another memory 
 *
 * DO not handle memory corruption
 *
 * @param src Pointer to data source
 * @param dst Pointer to data destination
 * @param length Length of the data to be moved
 *
 * @return Pointer of destination address
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets the values of given address to value for given length 
 *
 * Sets the values at specific addresses to given value
 *
 * @param src Pointer to data source
 * @param length Length for which the data to be initialized to value
 * @param value Value to which the addresses should be initialized
 *
 * @return Pointer of destination address
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets the values of given address to zero for given length 
 *
 * Sets the values at specific addresses to zero
 *
 * @param src Pointer to data source
 * @param length Length for which the data to be initialized to zero
 *
 * @return Pointer of destination address
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the value in the given address and length 
 *
 * Reverse the data in the given address for given length
 *
 * @param src Pointer to data source
 * @param length Length for which the data to be reversed
 *
 * @return Pointer of destination address
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates memory for the given length 
 *
 * Allocates the memory for the given length
 *
 * @param length Length for which the data to be reserved
 *
 * @return Pointer of destination address
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Deallocates the memory given at the location 
 *
 * Deallocates the memory at the given memory location
 *
 * @param src Address of the location where memory has to be deallocated
 *
 * @return void
 */
void free_words(int32_t * src);

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the location
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

#endif /* __MEMORY_H__ */
