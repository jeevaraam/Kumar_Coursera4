/**
 * @file data.c
 * @brief Abstraction of Data conversion operations
 *
 * This implementation file provides an abstraction of Data Conversion Operations
 *
 * @author Jeevaraam Kumar
 * @date April 28 2020
 *
 */

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int i=0,negative=0,rem=0;
	uint8_t *src = ptr;
	
	if(data==0)
	{
		*src='0';
		src++;
		i++;
		*src='\0';
	}
	
	if(data<0)
	{
		negative=1;
		data=-data;
	}
	
	while(data>0)
	{
		rem=data%base;
		*src=(rem>9)?(rem-10+'a'):rem+'0';
		data=data/base;
		src++;
		i++;
	}
	
	if(negative==1)
	{
		*src='-';
		src++;
		i++;
	}
	
	*src='\0';
	
	my_reverse(ptr,i);
	
	return (i+1);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int i=0,negative=0,val=0,power=1,start=0;
	int32_t data=0;
	
	if(*ptr=='-')
	{
		negative=1;
		start=1;
	}
	
	for(i=digits-2;i>=start;i--)
	{
		if(*(ptr+i)>='0' && *(ptr+i)<'9')
		{
			val = *(ptr+i) - '0';
		}
		else
		{
			val = (*(ptr+i)) - 'a' + 10;
		}
		
		data +=(val*power);
        power = power * base;		
	}
	
	if(negative==1)
	{
		data=-data;
	}
	return data;
	
}