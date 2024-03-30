#include "TestOptions.h"

TestOptions::TestOptions() : protectedOption(0), privateOption(0)
{

}

TestOptions::~TestOptions()
{
    
}

void TestOptions::displayOptions() const
{
    std::cout << "Protected Option: " << protectedOption << std::endl;
    std::cout << "Private Option: " << privateOption << std::endl;
}

void TestOptions::setup()
{
}

void TestOptions::setPassword(char * passStr, unsigned int i)
{
    if (strlen(passStr) > maxPassSize){
        std::cout << "pin length greater than " << maxPassSize << "exiting program";
        exit (-1);
    }
    if (i+1 > passBuffer.size()){
        passBuffer.resize(i + 1);
    }
    passBuffer[i].assign(passStr);
}

void TestOptions::getUserPass(unsigned int i)
{
    if (i+1 > passBuffer.size()){
        passBuffer.resize(i + 1);
    }
    else {
        std::cout << "Using Password entered in previous test\n";
        return;
    }
    char passStr[maxPassSize] = {}; // Ensure maxPinSize is defined elsewhere
    std::cout << "Enter PIN for the card in slot " << i << " (max length = " << maxPassSize << "): ";

#if defined(__linux) || defined(__APPLE__)
    // Temporarily disable echoing
    termios oldt;
    if (tcgetattr(STDIN_FILENO, &oldt) != 0) {
        std::cerr << "Error getting terminal attributes\n";
        exit(-1);
    }
    termios newt = oldt;
    newt.c_lflag &= ~ECHO; // Disable ECHO
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Set new attributes

    std::cin.getline(passStr, maxPassSize, '\n');

    // Restore the original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#else 
    std::cin.getline(passStr, maxPassSize, '\n');
#endif

    setPassword(passStr, i);
}

void TestOptions::modifyProtectedOption(unsigned long int value)
{
    protectedOption = value;
}

void TestOptions::setPrivateOption(unsigned long int value)
{
    privateOption = value;
}
