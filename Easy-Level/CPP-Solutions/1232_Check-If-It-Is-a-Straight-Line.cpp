class Solution
{
  public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        // furthest right and left coordinates
        vector<int> start = coordinates[0];
        vector<int> end = coordinates[0];

        // Equation points
        int totalX;
        float slope;

        // Setup start and end coordinates
        for (vector<int> point : coordinates)
        {
            // If x point less then current start then switch
            if (start[0] < point[0])
                start = point;
            // If x point greater then current end then switch
            else if (start[0] > point[0])
                end = point;
        }

        // Calculate slope y1 - y / x1 - x
        totalX = (end[0] - start[0]);

        // If inclined
        if (totalX)
        {
            // Calculate slope y1 - y / x1 - x
            slope = (float)(end[1] - start[1]) / totalX;

            // Get total of m(-x) + y
            float b = slope * (-1 * start[0]) + start[1];

            // Parse through all points
            for (vector<int> point : coordinates)
            {
                /* if pointY not equal to
                m (pointX - x) + y then means point
                is not intercepting then return false */
                if (slope * point[0] + b != point[1])
                    return false;
            }
        }
        else // Straight line
        {
            // Setup slope equal to the start of the line x axis
            slope = start[0];

            // Parse through all points
            for (int i = 0; i < coordinates.size(); i++)
            {
                // Check is straight
                if (coordinates[i][0] != slope)
                    return false;

                for (int j = i + 1; j < coordinates.size(); j++)
                {
                    // Check if point not in same location
                    if (coordinates[j] == coordinates[i])
                        return false;
                }
            }
        }

        // Else return true if no casualties where found
        return true;
    }
};
