#ifndef TESTOPTIONS_H
#define TESTOPTIONS_H

#include <memory>
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <functional>

#include <unistd.h>
#include <stdio.h>
#include <termios.h>

#define maxPassSize 250

class TestOptions {
public:
    TestOptions();
    ~TestOptions();
    void setup();
    void setPassword(char * pinStr, unsigned int i);
    void displayOptions() const;

protected:
    int protectedOption;
    void modifyProtectedOption(unsigned long int value);
    void getUserPass(unsigned int i);
    
private:
    int privateOption;
    void setPrivateOption(unsigned long int value);

    std::vector<std::string> passBuffer;
};

#endif // TESTOPTIONS_H
