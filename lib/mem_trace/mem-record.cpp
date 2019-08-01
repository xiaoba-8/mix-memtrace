/*
 * mem-record.cpp
 *
 *  Created on: 2018-11-4
 *      Author: xiaoba-8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <execinfo.h>
#include <mem_trace/mem-record.h>

#include "MemInfoContainer.h"

#ifdef _DEBUG

static MemInfoContainer s_mem_info;

void print_trace(char *buffer, int maxlen)
{
	static int serialNo = 0;
	++serialNo;
	if (serialNo == 5)
		serialNo = 5;
	sprintf(buffer, "%d", serialNo);
}

void *operator new(size_t nsize) throw (std::bad_alloc)
{
	void *ptr = malloc(nsize);

	char msg[MAX_MSG_SIZE];
	print_trace(msg, MAX_MSG_SIZE);

	return ptr;
}

void *operator new[](size_t nsize) throw (std::bad_alloc)
{
	void *ptr = ::operator new(nsize);

	char msg[MAX_MSG_SIZE];
	print_trace(msg, MAX_MSG_SIZE);
	s_mem_info.Add(ptr, msg);

	return ptr;
}

void *operator new(size_t nsize, const char *filename, int linenum)
{
	void *ptr = malloc(nsize);

	char msg[MAX_MSG_SIZE];
	sprintf(msg, "new [%s] [%d]", filename, linenum);

	s_mem_info.Add(ptr, msg);

	return ptr;
}

void *operator new[](size_t nsize, const char *filename, int linenum)
{
	void *ptr = malloc(nsize);

	char msg[MAX_MSG_SIZE];
	sprintf(msg, "new[] [%s] [%d]", filename, linenum);

	s_mem_info.Add(ptr, msg);

	return ptr;
}

void operator delete(void *ptr, const char *filename, int linenum)
{
	::operator delete(ptr);
	//printf("delete [%s] [%d] address : [%ld]\n", filename, linenum, (long)ptr);
}
void operator delete[](void *ptr, const char *filename, int linenum)
{
	::operator delete[](ptr);

	//printf("delete[] [%s] [%d] address : [%ld]\n", filename, linenum, (long)ptr);
}

void operator delete(void *ptr) throw ()
{
	free(ptr);
	s_mem_info.Remove(ptr);
	//printf("delete address : [%ld]\n", (long)ptr);
}

void operator delete[](void *ptr) throw ()
{
	free(ptr);
	s_mem_info.Remove(ptr);
	//printf("delete[] address : [%ld]\n", (long)ptr);
}

void debug_line(const char *filename, int linenum)
{
	//printf("[%s] [%d] ", filename, linenum);
}
#endif

void print_mem_info()
{
#ifdef _DEBUG

	struct mem_info *p_next = s_mem_info.GetMemInfo()->next;

	printf("Begin MemInfo :\n--------------------------------\n");
	while (p_next != NULL)
	{
		printf("MemInfo address[%ld] %s\n", (long)p_next->ptr, p_next->msg);
		p_next = p_next->next;
	}
	printf("End MemInfo :\n--------------------------------\n");
#endif
}

