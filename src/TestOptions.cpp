#include "TestOptions.h"
#include <iostream>

TestOptions::TestOptions() : protectedOption(0), privateOption(0) {
}

TestOptions::~TestOptions() {
    // Cleanup code if necessary
}

void TestOptions::displayOptions() const {
    std::cout << "Protected Option: " << protectedOption << std::endl;
    std::cout << "Private Option: " << privateOption << std::endl;
}

void TestOptions::modifyProtectedOption(int value) {
    protectedOption = value;
}

void TestOptions::setPrivateOption(int value) {
    privateOption = value;
}
