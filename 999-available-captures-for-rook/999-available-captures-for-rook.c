#define NOT_FOUND -1

int numRookCaptures(char** board, int boardSize, int* boardColSize){
    char R_row;
    char R_col;
    char B_loc = NOT_FOUND;
    char p_loc = NOT_FOUND;
    char output = 0;

    for (char row = 0; row <= boardSize - 1; row++){
        for (char col = 0; col <= boardSize - 1; col++){
            if (board[row][col] == 'R') {
                R_row = row;
                R_col = col;
            }
        }
    }

    for (char row = R_row; row >= 0; row--){
        if (board[row][R_col] == 'B' && B_loc == NOT_FOUND){
            B_loc = row;
        }
        else if (board[row][R_col] == 'p' && p_loc == NOT_FOUND){
            p_loc = row;
        }
    }
    
    if ((B_loc < p_loc && p_loc != NOT_FOUND) || (B_loc == NOT_FOUND && p_loc != NOT_FOUND)){
        output++;
    }
    
    B_loc = NOT_FOUND;
    p_loc = NOT_FOUND;

    for (char row = R_row; row <= boardSize - 1; row++){
        if (board[row][R_col] == 'B' && B_loc == NOT_FOUND){
            B_loc = row;
        }
        else if (board[row][R_col] == 'p' && p_loc == NOT_FOUND){
            p_loc = row;
        }
    }
    
    if ((B_loc > p_loc && p_loc != NOT_FOUND) || (B_loc == NOT_FOUND && p_loc != NOT_FOUND)){
        output++;
    }

    B_loc = NOT_FOUND;
    p_loc = NOT_FOUND;

    for (char col = R_col; col >= 0; col--){
        if (board[R_row][col] == 'B' && B_loc == NOT_FOUND){
            B_loc = col;
        }
        else if (board[R_row][col] == 'p' && p_loc == NOT_FOUND){
            p_loc = col;
        }
    }
    
    if ((B_loc < p_loc && p_loc != NOT_FOUND) || (B_loc == NOT_FOUND && p_loc != NOT_FOUND)){
        output++;
    }
    
    B_loc = NOT_FOUND;
    p_loc = NOT_FOUND;
    
    for (char col = R_col; col <= boardSize - 1; col++){
        if (board[R_row][col] == 'B' && B_loc == NOT_FOUND){
            B_loc = col;
        }
        else if (board[R_row][col] == 'p' && p_loc == NOT_FOUND){
            p_loc = col;
        }
    }
    
    if ((B_loc > p_loc && p_loc != NOT_FOUND) || (B_loc == NOT_FOUND && p_loc != NOT_FOUND)){
        output++;
    }
    
    return output;
}