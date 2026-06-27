class Solution {
public:
    bool isValid(string s) {
       stack<char> stack1;
        map<char, char> closeToOpen=
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s)
        {
            if(closeToOpen.count(c)) //map::count input is key which is close bracket here
            {
                if(!stack1.empty() && stack1.top() == closeToOpen[c])
                {
                   stack1.pop();
                }
                else return false;
            }
            else 
            stack1.push(c); //we actually push open brackets here 
            //[(])
        }
        return stack1.empty();
    }
};
