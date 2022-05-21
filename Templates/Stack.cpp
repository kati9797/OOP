#include <iostream>
#include "Stack.hpp"

int main()
{
    Stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    std::cout << st.top() << std::endl; // 3
    st.pop();
    std::cout << st.top() << std::endl; // 2
    st.pop();
    std::cout << st.top() << std::endl; // 1
    st.pop();
}
