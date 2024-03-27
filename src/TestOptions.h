#ifndef TESTOPTIONS_H
#define TESTOPTIONS_H

class TestOptions {
public:
    TestOptions();
    ~TestOptions();
    void displayOptions() const;

protected:
    int protectedOption;
    void modifyProtectedOption(int value);

private:
    int privateOption;
    void setPrivateOption(int value);
};

#endif // TESTOPTIONS_H
