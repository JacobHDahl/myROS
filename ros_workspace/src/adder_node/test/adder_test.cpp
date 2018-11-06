#include <iostream>
#include "ros/ros.h"
#include <std_msgs/Int16.h>
#include <random_node/Num.h>
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>
#include <vector>




/* ---------- Global testing variables -----------
	 Why? 
	 -----> We need to read parameters from a parameter
	 -----> file (they are read in the main function)
	 -----> and pass them to the test class. 
*/
namespace
{
	/* ---------- Global nodehandle ------------ 
		 Why?
		 ----> This have to be accessible both in main
		 ----> and within the test. Thus it is defined
		 ----> globally 
	*/
	ros::NodeHandle* g_n = NULL;

	/* How many number of runs left until the test is finished */
	int number_of_runs_left = 500;

	/* The base name of the file we want to store the test data to */
    std::string log_file_base;

	/* Maximum latency for the node under test */
	double max_latency;
		
	/* Floating point tolerance */
	double floating_tol;

	/* How often we refresh while we wait for a new message */
    double refresh_rate;

	/* How many callbacks we have in our test class 
	 	 -----> This has to be specified here! 
	 */
	const int number_callbacks = 2;

	/* --------- Testing class ---------
	   Why? 
		 -----> The testing class is passed to an argument 
		 -----> to each of the tests in this program. It
		 -----> provides utilities to read messages from
		 -----> nodes and define utilities to make the 
		 -----> test output readable and practical for our 
		 -----> purpose. 
	 */
	class AdderTest : public testing::Test  	/* Google test utilities */
	{
        protected:
            bool newRandomMessageRecieved = false;

            bool newAdderMessageRecieved = false;


		public:
			AdderTest(){;}

			~AdderTest() {}

            void setNewMessageReceived(bool messageRecievedBool, int index);

            const bool getNewMessageReceived(int index); //index is so we can use the same function for 2 different bools

            double computeAverageTime();



			/* Container for receiving messages */
    	    random_node::Num numMsg_;

            std_msgs::Int16 adderNumMsg_;

	  	/* Callback for waypoint messages */
			void timingNumMsgCb(const boost::shared_ptr<random_node::Num const>& msg);

            void addingNumMsgCb(const boost::shared_ptr<std_msgs::Int16 const>& msg);

			/* Add-ons for printing test errors */
			::testing::AssertionResult lessThan(double val1, double val2);
			
			/* Array for handling post processing statistics */
			std::vector<double> timing_numMsgs;

            int additionMistakes = 0;
	};

    void AdderTest::setNewMessageReceived(bool messageRecievedBool, int index){
        if(index==0) this->newRandomMessageRecieved = messageRecievedBool;
        if(index==1) this->newAdderMessageRecieved = messageRecievedBool;
    }

    const bool AdderTest::getNewMessageReceived(int index){
        if(index==0) return this->newRandomMessageRecieved;
        if(index==1) return this->newAdderMessageRecieved;
    }

    double AdderTest::computeAverageTime(){
        double totalValue = 0.0;
        for(int i=0;i<timing_numMsgs.size();i++){
            totalValue += timing_numMsgs[i];
        }
        return totalValue/timing_numMsgs.size();
    }
		
	void AdderTest::timingNumMsgCb(const boost::shared_ptr<random_node::Num const>& msg)
	{
        this->setNewMessageReceived(true,0);
		numMsg_= *msg;
	}

    void AdderTest::addingNumMsgCb(const boost::shared_ptr<std_msgs::Int16 const>& msg)
    {

        adderNumMsg_ = *msg;

    }

	::testing::AssertionResult
	AdderTest::lessThan(double val1, double val2)
	{
		if (val1 - val2 < 0)
			return ::testing::AssertionSuccess() << val1-val2 << " < " << 0;
		return ::testing::AssertionFailure() << val1-val2 << " > " << 0;
	}

} /* End empty namespace */ 


//TEST_F(AdderTest, timingAdditionTester)
//{
//	
//	/* Define subscriber for receiving incoming messages */
//	ros::Subscriber random_sub = g_n->subscribe<random_node::Num>("random_topic", 1, boost::bind(&AdderTest::timingNumMsgCb, this, _1));
//
//	/* Sample timing data number_of_runs_left times more */
//	while (number_of_runs_left > 0)
//	{
//		
//		/* Refresh data */
//		int i = 10; this->setNewMessageReceived(false,0);
//		
//		/* Actively wait for a new message to arrive */
//		while ((!this->getNewMessageReceived(0)) && i > 0 )
//		{
//			ros::spinOnce();
//			ros::WallDuration duration(refresh_rate);
//			duration.sleep();
//			i--;
//		}
//
//		/* Local scope to localize where a test may fail.
//			 This is a great utility when the tests grow bigger.
//		 */
//		{
//		SCOPED_TRACE("WAYPOINT_TIMING_VERIFICATION");
//			
//			/* Just double checking */
//			if (this->getNewMessageReceived(0))
//			{
//				/* Extract timing data */
//				ros::Duration latency = (numMsg_.header.stamp - numMsg_.start.data);
//
//				
//				/* Verify if we exceed our maximum timing limit */
//				EXPECT_TRUE(this->lessThan(latency.toSec(), max_latency));
//
//				/* Store timing data */
//				timing_numMsgs.push_back(latency.toSec());
//			}
//		}
//		number_of_runs_left--;
//	}
//}

TEST_F(AdderTest, additionTester)
{
    ros::Subscriber adder_sub = g_n->subscribe<std_msgs::Int16>("adder_topic", 1, boost::bind(&AdderTest::adderNumMsg_, this, _1));
    ros::Subscriber random_sub = g_n->subscribe<random_node::Num>("random_topic", 1, boost::bind(&AdderTest::timingNumMsgCb, this, _1));

    while(number_of_runs_left>0)
    {
        /* Refresh data */
		int i = 10; 
        this->setNewMessageReceived(false,0);
        this->setNewMessageReceived(false,1);

		
		/* Actively wait for a new message to arrive */
		while ((!this->getNewMessageReceived(0)) && (!this->getNewMessageReceived(1)) && i > 0 )
		{
			ros::spinOnce();
			ros::WallDuration duration(refresh_rate);
			duration.sleep();
			i--;
		}

        int adderNumber = adderNumMsg_.data;
        int sumRandomNumbers = numMsg_.num1 + numMsg_.num2;

        ASSERT_EQ(adderNumber, sumRandomNumbers);

        if(adderNumber!=sumRandomNumbers)
            additionMistakes++;

    }

}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);

	ros::init(argc, argv, "adder_test");
	g_n = new ros::NodeHandle();

	/* Wait for sim time to begin */
	while (ros::Time::now().toSec() <= 0)
	{
		ros::Duration(0.25).toSec();
		ros::spinOnce();
	}

	/* Process parameters 
	if (!g_n->getParam("test_planning/number_of_runs", number_of_runs_left))
	{
		ROS_ERROR_STREAM("Missing parameter: test_planning/number_of_runs");
		delete g_n;
		return 0;
	}
	
	if (!g_n->getParam("test_planning/log_file_base", log_file_base))
	{
		ROS_ERROR_STREAM("Missing parameter: test_planning/log_file_base");
		delete g_n;
		return 0;
	}

	if (!g_n->getParam("test_planning/max_latency", max_latency))
	{
		ROS_ERROR_STREAM("Missing parameter: test_planning/max_latency");
		delete g_n;
		return 0;
	}
	
	if (!g_n->getParam("test_planning/floating_tol", floating_tol))
	{
		ROS_ERROR_STREAM("Missing parameter: test_planning/floating_tol");
		delete g_n;
		return 0;
	}

	if (!g_n->getParam("test_planning/refresh_rate", refresh_rate))
	{
		ROS_ERROR_STREAM("Missing parameter: test_planning/refresh_rate");
		delete g_n;
		return 0;
	}
	
	float del;	
	if (!g_n->getParam("test_planning/delay", del))
	{
		ROS_ERROR_STREAM("Missing parameter: test_planning/delay");
		delete g_n;
		return 0;
	}
	ros::Duration delay = ros::Duration(del);*/

	/* Give nodes time to start up 
	ros::Time start_time = ros::Time::now();
	while ((ros::Time::now().toSec() - start_time.toSec()) < 3.0.toSec())
	{
		ros::Duration(0.25).sleep();
		ros::spinOnce();
	}*/

    ros::Duration(3.0).sleep();
    ros::spinOnce();

  int result = RUN_ALL_TESTS();

	delete g_n;
	return result;
}
