#include <iostream>
#include <string>

using namespace std;

#define MAX_INPUT_LENGTH 200 + 1

class Input {
private:
    string input;
    long unsigned int counter = 0;
public:
    Input(string input){
        this->input = input;
    }

    char read(){
        if(isEmpty()) return 0;
        return input.at(counter);
    }

    char pop(){
        if(isEmpty()) return 0;
        return input.at(counter++);
    }

    bool isEmpty(){
        return counter >= input.size();
    }
};

bool C(Input *input), B(Input *input), A(Input *input), S(Input *input);

int main(){
    string raw_input;
    getline(cin, raw_input);

    if(raw_input.size() > MAX_INPUT_LENGTH) {
        cout << "Maksimalna velicina ulaza prekoracena. Izlazim...";
        return 0;
    }

    Input input(raw_input);

    string output = (S(&input) == false || !input.isEmpty()) ? "\nNE" : "\nDA";
    cout << output;
    return 0;
}

bool C(Input *input){
    cout << "C";
    return A(input) && A(input);
}

bool B(Input *input){
    cout << "B";
    if(input->isEmpty()) return true;

    if(input->read() != 'c') return true;
    input->pop();
    if(input->read() != 'c') return false;
    input->pop();
    if(S(input) == false) return false;
    if(input->read() != 'b') return false;
    input->pop();
    if(input->read() != 'c') return false;
    input->pop();
    return true;
}

bool A(Input *input){
    cout << "A";
    if(input->isEmpty()) return false;
    char sw_var = input->read();
    switch (sw_var)
    {
    case 'b':
        input->pop();
        return C(input);
    case 'a':
        input->pop();
        return true;
    default:
        return false;
    }
}

bool S(Input *input){
    cout << "S";
    if(input->isEmpty()) return false;
    char sw_var = input->read();
    switch (sw_var)
    {
    case 'a':
        input->pop();
        return A(input) && B(input);
    case 'b':
        input->pop();
        return B(input) && A(input);
    default:
        return false;
    }
}