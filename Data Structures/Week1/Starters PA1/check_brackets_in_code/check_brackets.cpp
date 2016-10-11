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
    int check = 0;
    int count = 0;
    bool error_thrown = false; 

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
		count++;
        if (next == '(' || next == '[' || next == '{') {
        	// We dont have to type def structs in c++
        	//but have to do it in C if we want to. 
        	check++;
        	// creating an object for a bracket if encounterd
        	Bracket b_open(next, position+1);
            opening_brackets_stack.push(b_open);
        }

        if (next == ')' || next == ']' || next == '}') {
        	check--;
        	// Checking if struct is empty after encountering a closing bracket.
            if (opening_brackets_stack.empty()) {
            	std::cout<<position+1;
            	error_thrown = true;
            	break;
			}
			else {
				Bracket b_open_pop = opening_brackets_stack.top();
				
				char bracket = b_open_pop.type;
				if(!b_open_pop.Matchc(next)) {
					std::cout<<position + 1;
					error_thrown = true;
					break;
				}
				opening_brackets_stack.pop();
			}
		
        }
        
        
}
    
    if(!opening_brackets_stack.empty() && error_thrown == false) {
    	Bracket remain = opening_brackets_stack.top();
    	opening_brackets_stack.pop();
		std::cout<<remain.position;
	}
	
	else if (check == 0 && count == text.length() && opening_brackets_stack.empty() ==1  ) {
		std::cout<<"Success";
	}
	

	// {[}
    // Printing answer, write your code here

    return 0;
}
