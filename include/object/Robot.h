/*
 * Robot.h
 *
 *  Created on: 2023年9月20日
 *      Author: dcq
 */

#ifndef H3943554E_40DF_408B_BC62_C333527D48D3
#define H3943554E_40DF_408B_BC62_C333527D48D3

#include "base/Role.h"
#include "role/Worker.h"
#include "role/Energy.h"

struct Robot : Worker
               , ChargeEnergy
{
private:
    IMPL_ROLE(Energy);
};



#endif /* H3943554E_40DF_408B_BC62_C333527D48D3 */
