class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n * n;
        
        long long sum = 0;
        long long sqSum = 0;


        for(int i = 0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {
                sum += grid[i][j];
                sqSum += (grid[i][j] * grid[i][j]);
            }
        }
        
        long long esum = (N*(N+1))/2;
        long long esqSum = (N*(N+1)*(2*N+1))/6;

        int sqdiff = esqSum - sqSum;
        int diff = esum - sum;

        int a = (sqdiff/diff + diff)/2;
        int b = (sqdiff/diff - diff)/2;

        return{b,a};
    }
};