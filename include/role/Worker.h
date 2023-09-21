/*
 * Worker.h
 *
 *  Created on: 2023年9月20日
 *      Author: dcq
 */

#ifndef H4F9207FA_D01B_462E_81E5_135F5D9441A4
#define H4F9207FA_D01B_462E_81E5_135F5D9441A4


#include "base/Role.h"
#include "base/BaseType.h"
#include "base/interface_def.h"

struct Energy;

UNKNOWN_INTERFACE(Worker, 0x1234)
{
    Worker():produceNum(0)
    {}

    void produce();
    U32 getProduceNum() const
    {
        return produceNum;
    }

private:
    U32 produceNum;

private:
    USE_ROLE(Energy);
};


#endif /* H4F9207FA_D01B_462E_81E5_135F5D9441A4 */
