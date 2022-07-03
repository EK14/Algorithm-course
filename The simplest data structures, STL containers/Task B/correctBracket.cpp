#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string message;
    std::stack <char> st;
    std::cin >> message;
    for(int i = 0; i < message.size(); ++i){
        if(message[i] == '(' || message[i] == '[' || message[i] == '{'){
            st.push(message[i]);
        }
        else if(!st.empty()){
            if(message[i] == ')' && st.top() == '('){
                st.pop();
            }
            else if(message[i] == ']' && st.top() == '['){
                st.pop();
            }
            else if(message[i] == '}' && st.top() == '{'){
                st.pop();
            }
            else{
                std::cout << "NO";
                return 0;
            }
        }
        else{
            std::cout << "NO";
            return 0;
        }
    }
    if(st.empty())
        std::cout << "YES";
    else
        std::cout << "NO";
}
