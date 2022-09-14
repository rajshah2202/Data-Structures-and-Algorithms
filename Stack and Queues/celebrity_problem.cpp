#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i = 0;i<n;i++)
        {
            st.push(i);
        }
        
        while(st.size() >= 2)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            if(M[i][j] == 1)
                st.push(j);
            else
                st.push(i);
        }
        
        int cel = st.top();
        //cout << cel;
        st.pop();
        int flag = 0;
        for(int i = 0; i<n; i++)
        {
            if(cel == i)
                continue;
            else
            {
                if(M[cel][i] == 1 || M[i][cel] == 0)
                    flag = 1;
            }
        }
        
        if(flag == 0)
            return cel;
            
        else
            return -1;
    }
};