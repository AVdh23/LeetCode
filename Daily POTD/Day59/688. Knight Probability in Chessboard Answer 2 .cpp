class Solution {
public:
    double knightProbability(int chessBoardSize, int moves, int currentRow, int currentCol){
        // Initialize 3D dp array to store the probability of knight being on a certain square after k moves
        vector<vector<vector<double>>> dp(moves + 1, vector<vector<double>> (chessBoardSize, vector<double>(chessBoardSize, -1)));
            // Call the helper function to solve the problem
    return solve(chessBoardSize, moves, currentRow, currentCol, dp);
}
private:
    double solve(int chessBoardSize, int moves, int currentRow, int currentCol, vector<vector<vector<double>>>& dp){
    // If the knight is out of the chess board, return 0
    if (currentRow < 0 || currentRow >= chessBoardSize || currentCol < 0 || currentCol >= chessBoardSize) return 0;
    // If the knight has made k moves, return 1 as it will be on the chess board
    if (moves == 0) return 1;
        // If the probability for this state is already calculated, return it
    if (dp[moves][currentRow][currentCol] != -1)
        return dp[moves][currentRow][currentCol];
    
    // Total probability is the sum of probabilities of all 8 possible moves from the current square
    double total = solve(chessBoardSize, moves - 1, currentRow - 2, currentCol + 1, dp) + solve(chessBoardSize, moves - 1, currentRow - 1, currentCol + 2, dp)
                + solve(chessBoardSize, moves - 1, currentRow + 1, currentCol + 2, dp) + solve(chessBoardSize, moves - 1, currentRow + 2, currentCol + 1, dp)
                + solve(chessBoardSize, moves - 1, currentRow + 2, currentCol - 1, dp) + solve(chessBoardSize, moves - 1, currentRow + 1, currentCol - 2, dp)
                + solve(chessBoardSize, moves - 1, currentRow - 1, currentCol - 2, dp) + solve(chessBoardSize, moves - 1, currentRow - 2, currentCol - 1, dp);
        
    total = total / 8;
    return dp[moves][currentRow][currentCol] = total;
    }
};
