class Solution
{
    private:
        void solver(vector<int> &input, vector<int> &output, vector< vector< int >> &ans, vector< int > freqq)
        {
            if (output.size() == input.size())
            {
                ans.push_back(output);
                return;
            }

            for (int i = 0; i < input.size(); i++)
            {
                if (!freqq[i])
                {
                    output.push_back(input[i]);
                    freqq[i] = 1;
                    solver(input, output, ans, freqq);
                    freqq[i] = 0;
                    output.pop_back();
                }
            }
        }
    public:

        vector<vector < int>> permute(vector<int> &nums)
        {
            vector<vector < int>> ans;
            vector<int> output;
            vector<int> freqq(nums.size(), 0);
            solver(nums, output, ans, freqq);
            return ans;
        }
};