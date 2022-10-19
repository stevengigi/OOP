#include <bits/stdc++.h>
#include "../src/cookie.h"

/* The function help you to create the empty grid. */
/* You can use this function or create by yourself. */
bool** create_grid(){
    bool** array = new bool*[10];
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    return array;
}

/* The function help you to delete the grid. */
/* You should implement this. */
void delete_grid(bool** array){
    for(int i = 0; i < 10; i++){
        delete[] array[i];
    }
    delete[] array;
}

void put_testcase(bool** grid, std::string operation){
    for(int i = 0; i < operation.length(); i++){
        if(operation[i] == 'T'){
            placeTop(grid);
        }else if(operation[i] == 'R'){
            placeRight(grid);
        }
    }
}

int calcAnswerRow(bool** grid, int row){
    /* Calculate the count of cookie on the specific row */
    if(!(0 <= row && row < 10)){
        return -1;
    }
    int count = 0;
    for(int i = 0; i < 10; i++){
        count += grid[row][i];
    }
    return count;
}

int calcAnswerColumn(bool** grid, int column){
    if(!(0 <= column && column < 10)){
        return -1;
    }
    /* Calculate the count of cookie on the specific column */
    int count = 0;
    for(int i = 0; i < 10; i++){
        count += grid[i][column];
    }
    return count;
}

TEST(Cookie, SampleTest1){
    bool** grid = create_grid();
    grid[9][0] = 1;
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    ASSERT_EQ(calcRow(grid, 8), calcAnswerRow(grid, 8));
    ASSERT_EQ(calcColumn(grid, 1), calcAnswerColumn(grid, 1));
    delete_grid(grid);
}

TEST(Cookie, SampleTest2){
    bool** grid = create_grid();
    grid[9][0] = 1;
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    ASSERT_EQ(calcRow(grid, 0), calcAnswerRow(grid, 0));
    ASSERT_EQ(calcRow(grid, 8), calcAnswerRow(grid, 8));
    ASSERT_EQ(calcColumn(grid, 0), calcAnswerColumn(grid, 0));
    delete_grid(grid);
}

TEST(Cookie, SampleTest3){
    bool** grid = create_grid();
    grid[9][0] = 1;
    for(int i = 0; i < 9; i++){
       placeTop(grid); 
    }
    ASSERT_THROW(placeTop(grid), std::string);
    delete_grid(grid);
}

TEST(Cookie, SampleTest4){
    bool** grid = create_grid();
    grid[9][0] = 1;
    ASSERT_EQ(calcRow(grid, 48763), calcAnswerRow(grid, 48763));
    delete_grid(grid);
}

TEST(Cookie, RegularTest1){
    bool** grid = create_grid();
    grid[9][0] = 1;
    put_testcase(grid, "TTRRTTRR");
    ASSERT_EQ(calcRow(grid, 7), calcAnswerRow(grid, 7));
    ASSERT_EQ(calcRow(grid, 5), calcAnswerRow(grid, 5));
    ASSERT_EQ(calcColumn(grid, 0), calcAnswerColumn(grid, 0));
    ASSERT_EQ(calcColumn(grid, 2), calcAnswerColumn(grid, 2));
    delete_grid(grid);
}

TEST(Cookie, RegularTest2){
    bool** grid = create_grid();
    grid[9][0] = 1;
    put_testcase(grid, "TTTTRRRR");
    ASSERT_EQ(calcRow(grid, 5), calcAnswerRow(grid, 5));
    ASSERT_EQ(calcColumn(grid, 0), calcAnswerColumn(grid, 0));
    put_testcase(grid, "TTTRRR");
    ASSERT_EQ(calcRow(grid, 2), calcAnswerRow(grid, 2));
    ASSERT_EQ(calcColumn(grid, 4), calcAnswerColumn(grid, 4));
    delete_grid(grid);
}

TEST(Cookie, RegularTest3){
    bool** grid = create_grid();
    grid[9][0] = 1;
    put_testcase(grid, "TRTRTRTRTRTRTRTRTR");
    for(int i = 0; i < 9; i++){
        ASSERT_EQ(calcRow(grid, i), calcAnswerRow(grid, i));
    }
    for(int i = 0; i < 9; i++){
        ASSERT_EQ(calcColumn(grid, i), calcAnswerColumn(grid, i));
    }
    delete_grid(grid);
}

TEST(Cookie, RegularTestContainThrow1){
    bool** grid = create_grid();
    grid[9][0] = 1;
    put_testcase(grid, "TRTRTRTRTRTRTRTRTR");
    for(int i = 0; i < 9; i++){
        ASSERT_EQ(calcRow(grid, i), calcAnswerRow(grid, i));
    }
    for(int i = 0; i < 9; i++){
        ASSERT_EQ(calcColumn(grid, i), calcColumn(grid, i));
    }
    ASSERT_THROW(placeTop(grid), std::string);
    ASSERT_THROW(placeRight(grid), std::string);
    delete_grid(grid);
}

TEST(Cookie, RegularTestContainThrow2){
    bool** grid = create_grid();
    grid[9][0] = 1;
    ASSERT_THROW(put_testcase(grid, "TTTTTTTTTTTTTTTTTTTTTTTTTTTT"), std::string);
    delete_grid(grid);
}

TEST(Cookie, RegularTestContainThrow3){
    bool** grid = create_grid();
    grid[9][0] = 1;
    ASSERT_THROW(put_testcase(grid, "RRRRRRRRRRRRRRRRRRRRRRRRRRRR"), std::string);
    delete_grid(grid);
}

TEST(Cookie, RegularTestContainThrow4){
    bool** grid = create_grid();
    grid[9][0] = 1;
    ASSERT_THROW(put_testcase(grid, "TTRRTRTRTTRRTRTRTRTR"), std::string);
    delete_grid(grid);
}

TEST(Cookie, RandomTest01){
    for(int i = 0; i < 100; i++){
        bool** grid = create_grid();
        grid[9][0] = 1;
        std::string str = "TTTTTTTTTRRRRRRRRR";
        random_shuffle(str.begin(), str.end());
        put_testcase(grid, str);
        for(int j = 0; j < 10; j++){
            ASSERT_EQ(calcRow(grid, j), calcAnswerRow(grid, j));
            ASSERT_EQ(calcColumn(grid, j), calcAnswerColumn(grid, j));
        }
        delete_grid(grid);
    }
}

TEST(Cookie, RandomTest02){
    for(int i = 0; i < 100; i++){
        bool** grid = create_grid();
        grid[9][0] = 1;
        int t_count = rand() % 9;
        int r_count = rand() % 9;
        std::string str = "";
        for(int j = 0; j < t_count; j++) str += "T";
        for(int j = 0; j < r_count; j++) str += "R";
        random_shuffle(str.begin(), str.end());
        put_testcase(grid, str);
        for(int j = 0; j < 10; j++){
            ASSERT_EQ(calcRow(grid, j), calcAnswerRow(grid, j));
            ASSERT_EQ(calcColumn(grid, j), calcAnswerColumn(grid, j));
        }
        delete_grid(grid);
    }
}

TEST(Cookie, RandomTest03){
    for(int i = 0; i < 100; i++){
        bool** grid = create_grid();
        grid[9][0] = 1;
        int t_count = rand() % 9;
        int r_count = rand() % 9;
        std::string str = "";
        for(int j = 0; j < t_count; j++) str += "T";
        for(int j = 0; j < r_count; j++) str += "R";
        random_shuffle(str.begin(), str.end());
        for(int j = 0; j < str.length(); j++){
            put_testcase(grid, std::string(1, str[j]));
            for(int k = 0; k < 10; k++){
                ASSERT_EQ(calcRow(grid, k), calcAnswerRow(grid, k));
                ASSERT_EQ(calcColumn(grid, k), calcAnswerColumn(grid, k));
            }
        }
        delete_grid(grid);
    }
}

TEST(Cookie, RandomTest04){
    for(int i = 0; i < 100; i++){
        bool** grid = create_grid();
        grid[9][0] = 1;
        int t_count = rand() % 2 == 0 ? rand() % 9 : rand() % 1000;
        int r_count = rand() % 2 == 0 ? rand() % 9 : rand() % 1000;
        std::string str = "";
        for(int j = 0; j < t_count; j++) str += "T";
        for(int j = 0; j < r_count; j++) str += "R";
        if(t_count > 9 || r_count > 9){
            ASSERT_THROW(put_testcase(grid, str), std::string);
        }else{
            put_testcase(grid, str);
            for(int j = 0; j < 10; j++){
                ASSERT_EQ(calcRow(grid, j), calcAnswerRow(grid, j));
                ASSERT_EQ(calcColumn(grid, j), calcAnswerColumn(grid, j));
            }
        }
        delete_grid(grid);
    }
}
