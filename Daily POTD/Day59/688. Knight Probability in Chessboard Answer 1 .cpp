class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        return helper(N, K, r, c);
    }
    
    double helper(int N, int K, int row, int col){
        
        if(row < 0 || col < 0 || row >= N || col >= N) return 0.0;
        
        if(K == 0) return 1.0;
        
        double ans = helper(N, K-1, row+2, col+1) + helper(N, K-1, row+1, col+2) + 
                    helper(N, K-1, row-1, col+2) + helper(N, K-1, row-2, col+1) + 
                    helper(N, K-1, row-2, col-1) + helper(N, K-1, row-1, col-2) +
                  helper(N, K-1, row+1, col-2) + helper(N, K-1, row+2, col-1);
        
        double result  = ans / 8.0;
        return result;
    }
};