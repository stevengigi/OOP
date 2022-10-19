int check_x(bool** grid){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(grid[i][j] == 1){
                return i;
            }
        }
    }
    return 9;
}

int check_y(bool** grid){
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < 10; j++){
            if(grid[j][i] == 1){
                return i;
            }
        }
    }
    return 0;
}

void print_grid(bool** grid){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void placeTop(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x, check_y to get the x, y from the lastest of cookie you place. */
    int x = check_x(grid);
    int y = check_y(grid);

    /* Check is it out of bound or not. */
    if(x - 1 < 0){
        throw std::string("out of range.");
    }

    /* Place cookie from the top of current cookie. */
    grid[x-1][y] = 1;
}

void placeRight(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);
    int y = check_y(grid);

    /* Check is it out of bound or not. */
    if(y + 1 >= 10){
        throw std::string("out of range.");
    }

    /* Place cookie from the top of current cookie. */
    grid[x][y+1] = 1;
}

int calcRow(bool** grid, int row){
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

int calcColumn(bool** grid, int column){
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