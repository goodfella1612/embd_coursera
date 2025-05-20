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
 * @brief Used to calculate diffrent statistics such as average median etc
 *
 * <Add Extended Description Here>
 *
 * @author Dev Thacker
 * @date May 20 2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


void print_statistics(int *arr , int size);
/**
 * @brief  A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Null
 */

void print_array(int *arr , int size);
/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Null
 */

unsigned char find_median(int *arr , int size);
/**
 * @brief  Given an array of data and a length, returns the median value
 *
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Median of the data
 */

unsigned char find_mean(int *arr , int size);
/**
 * @brief  Given an array of data and a length, returns the mean value
 *
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Mean of the data
 */

unsigned char find_maximum(int *arr , int size);
/**
 * @brief  Given an array of data and a length, returns the maximum value
 *
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Maximum of the data
 */

unsigned char find_minimum(int *arr , int size);
/**
 * @brief  Given an array of data and a length, returns the minimum value
 *
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Minimum of the data
 */

void sort_array(int *arr , int size);
/**
 * @brief  Given an array of data and a length, sorts the array from largest to smallest.
 *
 * @param arr  A pointer to the array
 * @param size THe size of the array
 *
 * @return Null
 */


#endif /* __STATS_H__ */