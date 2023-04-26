#include <gtest/gtest.h>
#include <vector>

using namespace std;

bool inBounds(vector<vector<int> > &arr, int i, int j) {
    size_t m = arr.size();
    size_t n = arr[0].size();
    if (0 <= i && i < m && 0 <= j && j < n) {
        return true;
    }
    return false;
}

void dropSandOn(vector<vector<int> > &world, int row, int col) {
    if (!inBounds(world, row, col)) {
        return;
    }

    world[row][col]++;

    if (world[row][col] == 4) {
        world[row][col] = 0;
        dropSandOn(world, row, col - 1);
        dropSandOn(world, row, col + 1);
        dropSandOn(world, row - 1, col);
        dropSandOn(world, row + 1, col);
    }
    return;
}

TEST(TEST, MyTEST) {
    {
        vector<vector<int> > before = {
                {0, 0, 0},
                {1, 3, 1},
                {0, 2, 0}
        };
        vector<vector<int> > after = {
                {0, 1, 0},
                {2, 0, 2},
                {0, 3, 0}
        };

        dropSandOn(before, 1, 1);
        EXPECT_EQ(before, after);
    }

    {
        vector<vector<int> > before = {
                {0, 0, 0, 0},
                {0, 3, 3, 0},
                {0, 0, 0, 0}
        };
        vector<vector<int> > after = {
                {0, 1, 1, 0},
                {1, 1, 0, 1},
                {0, 1, 1, 0}
        };

        dropSandOn(before, 1, 1);
        EXPECT_EQ(before, after); // The above call changes 'before.'
    }

    {
        vector<vector<int> > before = {
                {3, 3, 0, 0},
                {3, 0, 0, 0},
                {0, 0, 0, 0}
        };
        vector<vector<int> > after = {
                {2, 0, 1, 0},
                {0, 2, 0, 0},
                {1, 0, 0, 0}
        };

        dropSandOn(before, 0, 0);
        EXPECT_EQ(before, after); // The above call changes 'before.'
    }
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}