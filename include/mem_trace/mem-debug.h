/*
 * mem-debug.h
 *
 *  Created on: 2018-11-4
 *      Author: xiaoba-8
 */

#ifndef MEM_DEBUG_H_
#define MEM_DEBUG_H_

#include "mem-record.h"

#ifdef _DEBUG

#define new DEBUG_NEW
#define delete DEBUG_DELETE

#endif

#endif /* MEM_DEBUG_H_ */
