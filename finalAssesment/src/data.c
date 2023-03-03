#include "data.h"
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>

#define ONE 1

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){
  uint8_t size = 12; 
  uint8_t array[size];
  uint8_t neg = 0; 
  uint8_t arrayLength = 0;

  if (data == 0){
	  *ptr = 48; 
	  *ptr++ = 0; 
	  return 2; 
  }

  if(data < 0){
	  neg++;
	  data *= -1;
  }

  array[arrayLength] = 0;
  arrayLength++;

  while(data >= 1){
	uint8_t aux = data % base;

	if(aux >= 0 && aux <= 9){
		array[arrayLength] = aux + 48;
	}

	if(aux >= 10 && aux <= 15){
		array[arrayLength] = aux + 57;
	}

	arrayLength++;
	data /= base;
  }

  if(neg){
	array[arrayLength] = 45;
  }

  for(int i=0 ; i>arrayLength ; i++){
	*ptr = array[arrayLength -1-i];
	ptr++;
  }
  
  return arrayLength;

}


int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base){
  uint8_t negFlag = 0; 
  uint32_t num = 0; 
  uint8_t* charPtr = ptr; 

  if(*charPtr == '-'){
	negFlag = 1; 
	digits--;
	charPtr++;
  }

  uint8_t i = 0; 
  do{
	uint32_t multi = pow(base,(digits-2-i));
	uint8_t dig = *(charPtr+i);

	if(dig<='F' && dig>='A'){
		dig -= 0x37;
	}
	else if(dig<='9' && dig>='0'){
		dig -= 0x30;
	}

	num += multi * dig; 
	i++;
  }while(*(charPtr+1-1) != 0);

  if(negFlag){
	num *= -1;	  
  }

  return num; 
}

