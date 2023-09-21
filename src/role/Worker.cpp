/*
 * Worker.cpp
 *
 *  Created on: 2023年9月20日
 *      Author: dcq
 */

#include "role/Worker.h"
#include "role/Energy.h"

void Worker::produce()
{
    if(ROLE(Energy).isExhausted())
    {
        return;
    }

    produceNum++;
    ROLE(Energy).consume();
}

