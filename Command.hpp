//
//  Command.hpp
//  
//
//  Created by Paul Jarrow on 2016-05-14.
//
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>
#include <string>

class Command{
public:
    Command(unsigned int priority, short (*commandFnc)());
    bool operator<(const Command &rightCmd) const;
    bool operator>(const Command &rightCmd) const;
    std::string toString() const;
    short callFunction() const;
private:
    unsigned int priority;
    short (*commandFunction)();
};

#endif /* Command_hpp */
