/*
 * MemInfoContainer.h
 *
 *  Created on: 2018-11-8
 *      Author: xiaoba-8
 */

#ifndef MEMINFOCONTAINER_H_
#define MEMINFOCONTAINER_H_

#define MAX_MSG_SIZE	255

struct mem_info
{
	void *ptr;
	char msg[MAX_MSG_SIZE];
	struct mem_info *next;
};

class MemInfoContainer
{
public:
	MemInfoContainer();
	virtual ~MemInfoContainer();

	void Add(void *ptr, char *msg);
	void Remove(void *ptr);

	struct mem_info *GetMemInfo();
private:
	struct mem_info m_header;
	struct mem_info *m_p_cusor;
};

#endif /* MEMINFOCONTAINER_H_ */
