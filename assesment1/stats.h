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
 * File Name: STATS.H 
 * Description: This is the header file of the program, it includes all the 
 * function definitions.
 *
 * In this file i am defining the 7 functions that will be used in the program.
 *  - 2 printing functions: to print the statistics and the values of an array.
 *  - 4 finder functions: will find the median, minimum, maximum and mean of a  *    given array.
 *  - 1 sorting function: sorts an a array from largest to smallest.
 *
 *
 * Author: Yevyeni Mascareñas
 * Date: 12/26/22
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * Function: print_statistics
 * Description:
 * 	 This function prints on the screen the statistics of an array inclu-
 * 	 ding minimum, maximum, mean and median.
 * Parameters:
 * 	char* array: Pointer to a data set
 * Return: nothing
 */
void print_statistics(unsigned char* array);
/**
 * Function: print_array
 * Description:
 *       This function prints on the screen the values stored inside an array.
 * Parameters:
 *      char* array: Pointer to a data set
 * Return: nothing
 */
void print_array(unsigned char* array);
/**
 * Function: find_median
 * Description:
 *       This function calculates the median value  of a data set.
 * Parameters:
 *      char* array: Pointer to a data set
 *      int length: Int value of the length or size of the data set
 * Return:
 * 	int median: the median value of the data set
 */
int find_median(unsigned char* array, int length);
/**
 * Function: find_mean
 * Description:
 *       This function calculates the mean value  of a data set.
 * Parameters:
 *      char* array: Pointer to a data set
 *      int length: Int value of the length or size of the data set
 * Return:
 *      int mean: the mean value of the data set
 */
int find_mean(unsigned char* array, int length);
/**
 * Function: find_maximum
 * Description:
 *       This function finds the max value  of a data set.
 * Parameters:
 *      char* array: Pointer to a data set
 *      int length: Int value of the length or size of the data set
 * Return:
 *      int maximum: the maximum value of the data set
 */
int find_maximum(unsigned char* array, int length);
/**
 * Function: find_minimum
 * Description:
 *       This function finds the minimum value  of a data set.
 * Parameters:
 *      char* array: Pointer to a data set
 *      int length: Int value of the length or size of the data set
 * Return:
 *      int minimum: the minimum value of the data set
 */
int find_minimum(unsigned char* array, int length);
/**
 * Function: find_minimum
 * Description:
 *       This function sorts the array from largest to smallest(value). 
 * Parameters:
 *      char* array: Pointer to a data set
 *      int length: Int value of the length or size of the data set
 * Return:
 *      Nothing
 */
void sort_array(unsigned char* array, int length);


#endif /* __STATS_H__ */
