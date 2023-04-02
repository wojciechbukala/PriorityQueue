#include <gtest/gtest.h>
#include "PQueue.hpp"

TEST(Construct, NoParam)
{
    PriorityQueue<std::string> sq;
    EXPECT_TRUE(sq.empty());
    EXPECT_EQ(sq.size(), 0);

    PriorityQueue<int> iq;
    EXPECT_TRUE(iq.empty());
    EXPECT_EQ(iq.size(), 0);

    PriorityQueue<double> dq;
    EXPECT_TRUE(dq.empty());
    EXPECT_EQ(dq.size(), 0);
}

TEST(RemoveMax, Typical_valuses)
{
    PriorityQueue<std::string> sq;
    sq.push("Wojtek",3);
    sq.push("Mateusz",4);
    sq.push("Janusz",1);
    sq.push("Marcin",2);

    EXPECT_EQ(sq.size(), 4);

    std::string removed1 = " ", removed2 = " "; 
    removed1 = sq.removeMax().getElement();
    removed2 = sq.removeMax().getElement();

    EXPECT_EQ(sq.size(), 2);
    EXPECT_EQ(removed1, "Mateusz");
    EXPECT_EQ(removed2, "Wojtek");

    sq.removeMax();
    EXPECT_EQ(sq.size(), 1);

}

TEST(RemoveMax, Border_valuses)
{
    PriorityQueue<std::string> sq;
    sq.push("Wojtek",3);
    sq.push("Mateusz",4);
    sq.push("Janusz",1);
    sq.push("Marcin",2);
    sq.push("Michal",6);
    sq.push("Jan", 5);

    EXPECT_EQ(sq.size(), 6);

    std::string removed1 = " ", removed2 = " "; 
    removed1 = sq.removeMax().getElement();
    removed2 = sq.removeMax().getElement();

    EXPECT_EQ(sq.size(), 4);
    EXPECT_EQ(removed1, "Michal");
    EXPECT_EQ(removed2, "Jan");

    sq.removeMax();
    sq.removeMax();
    sq.removeMax();
    sq.removeMax();
    EXPECT_EQ(sq.size(), 0);

    //EXPECT_THROW(sq.removeMax(), std::runtime_error);
}

TEST(RemoveMax, Wide_range_value)
{
    PriorityQueue<int> iq;
	
	srand((unsigned) time(NULL));

	// Get a random number
	int random = rand();


    for(int i=0; i<500; ++i)
    {
	    // Get a random number
	    int random = rand();
        iq.push(random, i);
    }

    for(int i = 1000; i>500; --i)
    {
        iq.push(random, i);
    }

    EXPECT_EQ(iq.size(), 1000);
}


