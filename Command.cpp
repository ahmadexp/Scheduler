//
//  CommandQueue.cpp
//  
//
//  Created by Paul Jarrow on 2016-05-14.
//
//

#include "Command.hpp"
#include "CommandFunctions.hpp"
#include <iostream>
#include <queue>


using namespace std;

/* 
 * class Command implementation
 */
Command::Command(unsigned int priority, short (*commandFnc)()) : priority(priority), commandFunction(commandFnc){}

bool Command::operator<(const Command &rightCmd) const{
    return priority < rightCmd.priority;
}

bool Command::operator>(const Command &rightCmd) const{
    return priority > rightCmd.priority;
}

string Command::toString() const{
    return string("[" + to_string(priority) + "]");
}

short Command::callFunction() const{
    return commandFunction();
}

/*
 * Main for prototyping
 */
int main(){
    priority_queue<Command, vector<Command>, greater<Command> > pqueue;
    
    pqueue.push(Command(1, functionOne));
    pqueue.push(Command(5, functionTwo));
    pqueue.push(Command(3, functionThree));
    pqueue.push(Command(2, functionFour));

    cout << "Priority Queue contains " << pqueue.size() << " elements." << endl;

    while (!pqueue.empty()) {
        cout << pqueue.top().toString() << endl;
        pqueue.top().callFunction();
        pqueue.pop();
    }
    return 0;
}
