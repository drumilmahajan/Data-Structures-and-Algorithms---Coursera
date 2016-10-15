#include <iostream>
#include <stack>
#include <string>

// Creating a Bracket struct which will hold the opeing brackets and its position in the code based on 1 base indexing. 
struct Bracket {
    Bracket(char type, int position):
        type(type),  // initializes type to type
        position(position)   // intializes position to position. 
    {}
	// Matches open and closing brackets. 
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
    int check = 0; // Check if pops are equal to pushes on the stack.
    int count = 0; // Count if the whole line has been read.
    bool error_thrown = false; // To store that is there a mismatch error or not. Initially false. 

	//Creating a stack of struct Bracket
    std::stack <Bracket> opening_brackets_stack;
    // Looping through the input string
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position]; // Storing a char in next at a time
		count++;
		
		// If its an opening bracket, push it on stack.
        if (next == '(' || next == '[' || next == '{') {
        	// We dont have to type def structs in c++
        	//but have to do it in C if we want to. 
        	check++; 
        	// creating an object for a bracket if encounterd
        	Bracket b_open(next, position+1);
            opening_brackets_stack.push(b_open);
        }
		// If it is closing bracket. Match is with the top of stack. If matches then remove else throw error and break the program. 
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
				opening_brackets_stack.pop(); // Removing only when push matched the pop else loop is broken and error is thrown. 
			}
		
        }
        
        
}
    // Final test to see if stack is empty or not. If it is that there is a mismatch. 
    if(!opening_brackets_stack.empty() && error_thrown == false) {
    	Bracket remain = opening_brackets_stack.top();
    	opening_brackets_stack.pop();
		std::cout<<remain.position;
	}
	// If everything goes well. That is stack is empty, all chars read, pops are equal to pushes. Then output Success. 
	else if (check == 0 && count == text.length() && opening_brackets_stack.empty() ==1  ) {
		std::cout<<"Success";
	}
    return 0;
}
