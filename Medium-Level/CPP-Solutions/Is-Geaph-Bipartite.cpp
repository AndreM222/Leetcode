class Solution {

private:
    bool bipart(int curr, vector<vector<int>>& graph, vector<int>& partition)
    {
        // If Current is untoched then set to 1
        if(partition[curr] == -1) partition[curr] = 1;

        // Parse through current loop content
        for(auto i : graph[curr])
        {
            // Check if connection is untoched
            if(partition[i] == -1)
            {
                // If untoched

                /* Setup current content equal to 1 - current content
                 * If current 1 then connection be 0
                 * if current 0 then connection becomes -1 so next loop is 1 */
                partition[i] = 1 - partition[curr];

                /* Check if current content is partition
                 * else if not then return false */
                if(!bipart(i, graph, partition)) return false;
            }    
            /* If not untoched then check if connection is not same as content
             * return false if true since it's a loop */
            else if(partition[i] == partition[curr]) return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int length = graph.size();

        /* Separate into different partitions
         * Set all negative ones to tell is untoched */
        vector<int> partition(length, -1);
        // Parse through the array
        for(int i = 0; i < length; i++) 
        {
            // Check that current is bipart
            if(!bipart(i, graph, partition)) return false;
        }

        return true;
    }
};
