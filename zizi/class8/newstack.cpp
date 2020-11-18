#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int char_num;
int line_num = 0;
string line;
vector<char> brace_stack;

bool IsOpening(char c) { return (c == '{') || (c == '[') || (c == '('); }

bool IsClosing(char c) { return (c == '}') || (c == ']') || (c == ')'); }

bool IsMatching(char cur_char, char brace_stack_back) {
  return (cur_char == '}' && brace_stack_back == '{') ||
         (cur_char == ')' && brace_stack_back == '(') ||
         (cur_char == ']' && brace_stack_back == '[');
}

int main(int argc, const char *argv[]) {
  if (argc < 2) {
    cerr << "Please give command line argument." << endl;
    exit(5);
  }
  ifstream fin(argv[1]);
  if (!fin.is_open()) {
    cerr << "Could not open file: " << argv[1] << endl;
  } else {
    while (getline(fin, line)) {
      line_num++;
      for (char_num = 0; char_num < line.length(); char_num++) {
        char cur_char = line.at(char_num);

        if (IsOpening(cur_char)) {
          brace_stack.push_back(cur_char);
        } else if (IsClosing(cur_char)) {
          if (!IsMatching(cur_char, brace_stack.back())) {
            cerr << "Error on line " << line_num << " mismatched " << cur_char
                 << endl;
            exit(1);
          } else {
            brace_stack.pop_back();
          }
        } // end elseif
      }   // end for
    }     // end while
  }       // end file open?
  if (brace_stack.size() >= 1) {
	  cerr << "Extra " << brace_stack.back() << endl;
	  exit(9);
  }

  cout << line_num << " lines read. All balanced." << endl;
}