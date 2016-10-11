#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),  // initializes type to type
        position(position)   // intializes position to position. 
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
		
        if (next == '(' || next == '[' || next == '{') {
        	// We dont have to type def structs in c++
        	//but have to do it in C if we want to. 
        	
        	// creating an object for a bracket if encounterd
        	Bracket b_open(next, position+1);
            opening_brackets_stack.push(b_open);
        }

        if (next == ')' || next == ']' || next == '}') {
        	// Checking if struct is empty after encountering a closing bracket.
            if (opening_brackets_stack.empty()) {
            	std::cout<<position+1;
			}
			else {
				Bracket b_open_pop = opening_brackets_stack.top();
				opening_brackets_stack.pop();
				char bracket = b_open_pop.type;
				if(!b_open_pop.Matchc(next)) {
					std::cout<<position + 1;
				}
			}
		
        }
        
        
}
    
    if(!opening_brackets_stack.empty()) {
    	Bracket remain = opening_brackets_stack.top();
    	opening_brackets_stack.pop();
		std::cout<<remain.position;
	}
	


    // Printing answer, write your code here

    return 0;
}
