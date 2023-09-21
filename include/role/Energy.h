/*
 * Energy.h
 *
 *  Created on: 2023年9月20日
 *      Author: dcq
 */

#ifndef H24283E73_68DF_4F20_87F5_A86E36364C4B
#define H24283E73_68DF_4F20_87F5_A86E36364C4B


#include "base/Role.h"
#include "base/BaseType.h"

DEFINE_ROLE(Energy)
{
    ABSTRACT(void consume());
    ABSTRACT(bool isExhausted() const);
};

struct HumanEnergy : Energy
{
    HumanEnergy():isHungry(false),consumeTimes(0)
    {}

private:
    OVERRIDE(void consume())
    {
        consumeTimes++;
        if(consumeTimes >= MAX_CONSUME_TIME)
        {
            isHungry = true;
        }
    }

    OVERRIDE(bool isExhausted() const)
    {
        return isHungry;
    }


private:
    enum
    {
        MAX_CONSUME_TIME = 10
    };

    bool isHungry;
    U8 consumeTimes;
};

struct ChargeEnergy : Energy
{
    ChargeEnergy():percent(0)
    {}

    void charge()
    {
        percent = FULL_PERCENT;
    }

private:
    OVERRIDE(void consume())
    {
        if(percent > 0)
        {
            percent -= CONSUME_PERCENT;
        }
    }

    OVERRIDE(bool isExhausted() const)
    {
        return percent == 0;
    }


private:
    enum
    {
        FULL_PERCENT = 100,
        CONSUME_PERCENT = 1
    };

    U8 percent;
};


#endif /* H24283E73_68DF_4F20_87F5_A86E36364C4B */
