/*
 * memdebug-demo.cpp
 *
 *  Created on: Aug 1, 2019
 *      Author: xiaoba-8
 */

#include <stdio.h>

#include <mem_trace/mem-debug.h>

int main(int argc, char *argv[])
{
	int *pInt = new int;
	int *pIntArray = new int[10];

	printf("The memery info now\n");
	print_mem_info();

	delete pInt;
	delete[] pIntArray;

	printf("\n");
	printf("The memery info before exit\n");
	print_mem_info();

}
