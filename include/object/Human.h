/*
 * Human.h
 *
 *  Created on: 2023年9月20日
 *      Author: dcq
 */

#ifndef HDF9049A3_8952_43E6_A786_5CA934BC004F
#define HDF9049A3_8952_43E6_A786_5CA934BC004F

#include "base/Role.h"
#include "base/interface_def.h"
#include "base/Unknown.h"
#include "role/Worker.h"
#include "role/Energy.h"

struct HumanObject : dci::Unknown
                   , Worker
                   , private HumanEnergy
{
    BEGIN_INTERFACE_TABLE()
        __HAS_INTERFACE(Worker)
    END_INTERFACE_TABLE()

private:
    IMPL_ROLE(Energy);
};

struct HumanFactory
{
    static dci::Unknown* create()
    {
        return new HumanObject();
    }
};


#endif /* HDF9049A3_8952_43E6_A786_5CA934BC004F */
