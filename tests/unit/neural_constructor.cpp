#include <iostream>

#include "gtest/gtest.h"

#include "neural_network.h"

TEST(neural_network_case_1, constructor_tests) {
    //Arrange
    neural_network* net = (neural_network*) malloc(sizeof(neural_network));

    //Act
    neural_network_constructor(net, 3, 5, 2, 3);
    //Assertion
    EXPECT_TRUE(net);
}