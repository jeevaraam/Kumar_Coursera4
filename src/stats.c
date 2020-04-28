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
	#ifdef VERBOSE
	int i;
	
	for(i=0;i<length;i++)
	{
                if(!(i%8))
                   PRINTF("\n");
		PRINTF("%d\t",arr[i]);
	}
        PRINTF("\n");
	#endif
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
