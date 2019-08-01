/*
 * mem-record.h
 *
 *  Created on: 2018-11-4
 *      Author: xiaoba-8
 */

#ifndef MEM_RECORD_H_
#define MEM_RECORD_H_

#include <stddef.h>

#ifdef _DEBUG

void *operator new(size_t nsize, const char *filename, int linenum);
void *operator new[](size_t nsize, const char *filename, int linenum);

void operator delete(void *ptr, const char *filename, int linenum);
void operator delete[](void *ptr, const char *filename, int linenum);

void debug_line(const char *filename, int linenum);

#define DEBUG_NEW new(__FILE__, __LINE__)
#define DEBUG_DELETE delete

#endif

void print_mem_info();

#endif /* MEM_RECORD_H_ */
