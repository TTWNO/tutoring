#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int char_num, line_num = 0;
vector<char> brace_stack;

int main(int argc, char * argv[]) {
    std::cout << "Args: " << argc << std::endl;
    //std::cout << argv[1] << std::endl;

    std::string line;
    std::ifstream myFile("stack.cpp");
    while (getline(myFile, line)) {
        line_num++;
        std::cout << line << std::endl;
        line.length();
        // first cahracter
        line.at(0);

        for (char_num = 0, char_num < line.length(), char_num++) {
            char cur_char = line.at(char_num);
            if (cur_char == '[') {
                brace_stack.push_back(cur_char);
            } else if (cur_char == '{') {
            } else if (cur_char == '(') {
            } else if (cur_char == ']') {
                if (brace_stack.back() != '[') {
                    cout << "Error on line " << line_num << " mismatched " << "]" << endl;
                }
            } else if (cur_char == '}') {
            } else if (cur_char == ')') {
            }
        }
    }
}

