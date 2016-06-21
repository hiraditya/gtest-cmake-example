#include <iostream>
#include "gtest/gtest.h"

#include "graph.h"

// The fixture for testing class Project1. From google test primer.
class GraphTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	GraphTest() {
		// You can do set-up work for each test here.
	}

	virtual ~GraphTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Project1.
	BinaryTree T;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access
// the test fixture (from google test primer)
TEST_F(GraphTest, MethodBarDoesAbc) {
  int V1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int V2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  BinaryTree B;
  for (int i = 0; i < 10; ++i) {
    B.Insert(V1[i]);
    B.Insert(V2[10 -i -1]);
  }
	EXPECT_EQ(B.GetRoot()->GetId(), 1);
}

// }  // namespace - could surround Project1Test in a namespace

