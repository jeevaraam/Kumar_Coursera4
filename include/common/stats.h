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
 * @file stats.c
 * @brief Implementation of Statistics operation using C Code
 *
 * @author Jeevaraam Kumar
 * @date 03-Apr-2020
 *
 */
 
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Print the Mean, Median and Mode of given array
 *  
 * The function calls the corresponding statistical functions for calculation of Mean, Median and Mode of given array
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return void
 */

 void print_statistics(unsigned char arr[], int length);
 
 /**
 * @brief Print the Input array values 
 *  
 * The function prints the array values given as input to the function
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return void
 */

 void print_array(unsigned char arr[],int length);
 
 /**
 * @brief Calculate the median and return the median of given array
 *  
 * The function takes the array and length input and calculates the median of the given array values
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return median value of the given array
 */
 
 char find_median(unsigned char arr[], int length);
 
 /**
 * @brief Calculate the mean and return the mean of given array
 *  
 * The function takes the array and length input and calculates the mean of the given array values
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return mean value of the given array
 */
 
 char find_mean(unsigned char arr[], int length);
 
 /**
 * @brief Find the maximum value and return the same
 *  
 * The function takes the array and length input and calculates the maximum value of the given array values
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return maximum value of the given array
 */
 
 char find_maximum(unsigned char arr[], int length);
 
 /**
 * @brief Find the minimum value and return the same
 *  
 * The function takes the array and length input and calculates the minimum value of the given array values
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return minimum value of the given array
 */
 
 char find_minimum(unsigned char arr[], int length);
 
 /**
 * @brief Sorts the given array in descending order
 *  
 * The function takes the array and length input and sorts the values from largest to smallest
 *
 * @param arr Input array
 * @param length Length of the array
 *
 * @return void
 */
 
 void sort_array(unsigned char* arr, int length);
 
#endif /* __STATS_H__ */

