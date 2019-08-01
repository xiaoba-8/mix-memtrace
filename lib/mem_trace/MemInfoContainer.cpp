/*
 * MemInfoContainer.cpp
 *
 *  Created on: 2018-11-8
 *      Author: xiaoba-8
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "MemInfoContainer.h"

MemInfoContainer::MemInfoContainer()
{
	m_header.next = NULL;
	m_p_cusor = &m_header;
}

MemInfoContainer::~MemInfoContainer()
{
	struct mem_info *p_next = m_header.next;
	struct mem_info *p_current = NULL;

	while (p_next != NULL)
	{
		p_current = p_next;
		p_next = p_next->next;

		free(p_current);
	}
}

void MemInfoContainer::Add(void *ptr, char *msg)
{
	struct mem_info *p_item = (struct mem_info *)malloc(sizeof(struct mem_info));
	p_item->ptr = ptr;
	strcpy(p_item->msg, msg);
	p_item->next = m_header.next;

	m_header.next = p_item;
}

void MemInfoContainer::Remove(void *ptr)
{
	struct mem_info *p_parent = &m_header;
	struct mem_info *p_current = m_header.next;

	while (p_current != NULL)
	{
		if (p_current->ptr == ptr)
		{
			p_parent->next = p_current->next;
			free(p_current);
			break;
		}
		p_parent = p_current;
		p_current = p_parent->next;
	}
}

struct mem_info *MemInfoContainer::GetMemInfo()
{
	return &m_header;
}
