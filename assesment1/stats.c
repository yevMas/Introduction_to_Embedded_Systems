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
 * File name: stats.c 
 * 	This file includes the function implementations of every defined 
 * 	function in the .h file.
 *
 * 	It incorporates the functional code of each printing, sorting and 
 * 	finder function of the project. 
 *
 * 	This project works with an array of data finding the median, maximum, 
 * 	minimum, and mean values of that data array. 
 *
 * 	This project is for learning and practicing purposes.
 * *
 * Author: Yevyeni Mascareñas
 * Date: 12/27/2022
 */

#include <string.h>
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
//  unsigned char* ptr = test;
  /* Statistics and Printing Functions Go Here */
  print_array(test);
  print_statistics(test);

}


/*-------------Function Implementations----------*/ 
/* Statistics printer function */
void print_statistics(unsigned char* array){
	printf("\nStatistics:\n");
	printf("Maximum: %i \n", find_maximum(array, SIZE));
	printf("Minimum: %i \n", find_minimum(array, SIZE));
	printf("Median: %i \n", find_median(array, SIZE));
	printf("Mean: %i \n", find_mean(array, SIZE));
	printf("%li", sizeof(array));
	printf("\n");
}

/*This function prints the value of a data array*/
void print_array(unsigned char* array){
	printf("Array values: \n");
	for(int i=0; i<SIZE ; i++){
		printf(" %i, ", array[i]); 
	}

}

/*This function finds the median of the data array */ 
int find_median(unsigned char* array, int length){
	int median;
	median = array[19];

	return(median);
}

/*This function finds the maximum value of the data array */
int find_maximum(unsigned char* array, int length){
	sort_array(array, length);
	
	return(array[0]);
}
/*this function finds the mean value of the data array*/
int find_mean(unsigned char* array, int length){
	int sum = 0;
	for(int i=0; i<length ; i++){
		sum += array[i];
	}
//	sum = sum/SIZE;

	return (sum/length);
}

/*this function finds the minimum value of the data array */ 
int find_minimum(unsigned char* array, int length){
	sort_array(array, length);

	return(array[SIZE-1]);
}

/*Bubble sort*/
void sort_array(unsigned char* array, int length){
	unsigned char aux;

	for(int i=0; i<SIZE ;i++){
		for(int j=0; j<SIZE ;j++){
			if(array[i] > array[j]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
}




