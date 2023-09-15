#include <gtest/gtest.h>
#include "GalacticSpacecraft.h" // Include the header file for your GalacticSpacecraft class

// Define a fixture class for testing GalacticSpacecraft
class GalacticSpacecraftTest : public ::testing::Test {
protected:
    // Create an instance of GalacticSpacecraft for each test
    GalacticSpacecraft spacecraft;

    // Constructor runs before each test
    GalacticSpacecraftTest() : spacecraft(0, 0, 0, 'N') {}
};

// Test the initial position and direction
TEST_F(GalacticSpacecraftTest, InitialPositionAndDirection) {
    EXPECT_EQ(spacecraft.getX(), 0);
    EXPECT_EQ(spacecraft.getY(), 0);
    EXPECT_EQ(spacecraft.getZ(), 0);
    EXPECT_EQ(spacecraft.getDirection(), 'N');
}

// Test moving forward
TEST_F(GalacticSpacecraftTest, MoveForward) {
    spacecraft.moveForward();
    EXPECT_EQ(spacecraft.getY(), 1);
}

// Test moving backward
TEST_F(GalacticSpacecraftTest, MoveBackward) {
    spacecraft.moveBackward();
    EXPECT_EQ(spacecraft.getY(), -1);
}

// Test turning left
TEST_F(GalacticSpacecraftTest, TurnLeft) {
    spacecraft.turnLeft();
    EXPECT_EQ(spacecraft.getDirection(), 'W');
}

// Test turning right
TEST_F(GalacticSpacecraftTest, TurnRight) {
    spacecraft.turnRight();
    EXPECT_EQ(spacecraft.getDirection(), 'E');
}

// Test turning up
TEST_F(GalacticSpacecraftTest, TurnUp) {
    spacecraft.turnUp();
    EXPECT_EQ(spacecraft.getDirection(), 'U');
    EXPECT_EQ(spacecraft.getZ(), 1);
}

// Test turning down
TEST_F(GalacticSpacecraftTest, TurnDown) {
    spacecraft.turnDown();
    EXPECT_EQ(spacecraft.getDirection(), 'D');
    EXPECT_EQ(spacecraft.getZ(), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
