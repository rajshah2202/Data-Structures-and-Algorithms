#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int k = 10;
    stack<int> st;
    for(int i =0; i<6; i++)
    {
        st.push(i);
    }

    stack<int> st2;
    for(int i = 0; i<6; i++)
    {
        st2.push(st.top());
        st.pop();
    }

    st2.push(k);

    for(int i = 0; i< 7; i++)
    {
        st.push(st2.top());
        st2.pop();
    }

    while (!st.empty()) {
        cout << ' ' << st.top();
        st.pop();
    }

}