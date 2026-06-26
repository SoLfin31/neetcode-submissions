class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        vector<int> record;
        int result = 0;
        for(int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "+")
            {
               int top = record.back();
               record.pop_back();
               int newTop = record.back() + top;
               record.push_back(top);
               record.push_back(newTop);
            }
            else if (operations[i] == "D")
            {
               int top = record.back();
               record.pop_back();
               int newTop = 2 * top;
               record.push_back(top);
               record.push_back(newTop);
            }
            else if (operations[i] == "C")
            {
                record.pop_back();
            }
            else
            {
                record.push_back(stoi(operations[i]));
            }
        }
        for(int score : record)
        {
            result += score;
        }
        return result;
    };
};