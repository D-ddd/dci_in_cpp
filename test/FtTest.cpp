#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

#include "base/Unknown.h"
#include "object/Human.h"
#include "object/Robot.h"

struct FtTest : testing::Test
{
};

TEST_F(FtTest,should_gtest_ok)
{
    printf("gtest ok!\n");
}

TEST_F(FtTest, human_do_with_dci)
{
    dci::Unknown* unknown = HumanFactory::create();
    Worker* worker = dci::unknown_cast<Worker>(unknown);
    ASSERT_TRUE(worker!=nullptr);

    worker->produce();
    ASSERT_EQ(1, worker->getProduceNum());
}

TEST_F(FtTest,robot_do)
{
    Robot robot;
    SELF(robot, ChargeEnergy).charge();

    while(!SELF(robot, Energy).isExhausted())
    {
        SELF(robot, Worker).produce();
    }

    ASSERT_EQ(100, SELF(robot, Worker).getProduceNum());
}
