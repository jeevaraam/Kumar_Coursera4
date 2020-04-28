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



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  
  printf("Input Array\n");
  print_array(test,SIZE);
  printf("Sorted Array\n");
  sort_array(test,SIZE);
  print_statistics(test,SIZE);
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char arr[], int length)
{
	print_array(arr,length);
	printf("Mean:\n");
	printf("%d\n",find_mean(arr,length));
	printf("Median:\n");
	printf("%d\n",find_median(arr,length));
	printf("Maximum Value:\n");
	printf("%d\n",find_maximum(arr,length));
	printf("Minimum Value:\n");
	printf("%d\n",find_minimum(arr,length));
}

void print_array(unsigned char arr[],int length)
{
	int i;
	
	for(i=0;i<length;i++)
	{
                if(!(i%8))
                   printf("\n");
		printf("%d\t",arr[i]);
	}
        printf("\n");
}

char find_mean(unsigned char arr[], int length)
{
	int i;
	float avg=0;
	
	for(i=0;i<length;i++)
	{
		avg = avg+((float)arr[i]);
	}
	
	avg = avg/length;
	
	return ((char)avg);
}

char find_median(unsigned char arr[], int length)
{
	char median=0;
	
	if((length%2)==0)
	{
		length = length/2;
		median = (arr[length]+arr[length-1])/2;
	}
	else
	{
		length=length/2;
		median = arr[length];
	}
	
	return median;
}

char find_maximum(unsigned char arr[], int length)
{
	char max=arr[0];
	int i;
	
	for(i=0;i<length;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	
	return max;
}

char find_minimum(unsigned char arr[], int length)
{
	char min=arr[0];
	int i;
	
	for(i=0;i<length;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	
	return min;
}

void sort_array(unsigned char* arr, int length)
{
	int i,j;
	char z;
	
	for(i=0;i<length;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if((*(arr+i))<(*(arr+j)))
			{
				z = (*(arr+i));
				(*(arr+i)) = (*(arr+j));
				(*(arr+j)) = z;
			}
		}
	}
}
