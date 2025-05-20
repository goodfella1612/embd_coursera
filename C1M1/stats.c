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

    print_array(test,SIZE);
    print_statistics(test,SIZE);
    sort_array(test,SIZE);
    print_array(test,SIZE);

}

void print_statistics(unsigned char *arr , int size) {
    unsigned char min = find_minimum(arr,size);
    printf("The minimum is :%d \n",min);
    unsigned char max = find_maximum(arr,size);
    printf("The maximum is :%d \n",max);
    unsigned char median = find_median(arr,size);
    printf("The median is :%d \n",median);
    unsigned char mean = find_mean(arr,size);
    printf("The mean is :%d \n",mean);
    printf("\n");
}

void print_array(unsigned char *arr , int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",*arr);
        arr++;
        if((i+1)%8 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

unsigned char find_median(unsigned char *arr , int size) {
    sort_array(arr,size);
    return ( size%2==0 ) ? (arr[size/2]+arr[size/2-1])/2 : arr[(size-1)/2];
}

unsigned char find_mean(unsigned char *arr , int size) {
    int total =0;
    for(int i=0;i<size;i++) {
        total=total+*arr;
        arr++;
    }
    return (unsigned char)(total/size);
}

unsigned char find_maximum(unsigned char *arr , int size) {
    unsigned char max=0;
    for(int i=0;i<size;i++) {
        if( *arr >= max ) {
            max=*arr;
        }
        arr++;
    }
    return max;
}

unsigned char find_minimum(unsigned char *arr , int size) {
    unsigned char min=255;
    for(int i=0;i<size;i++) {
        if( *arr <= min ) {
            min=*arr;
        }
        arr++;
    }
    return min;
}

void sort_array(unsigned char *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                unsigned char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
