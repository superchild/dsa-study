
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;
void substract(int &remain, int &height, int width, int len) {
    if (remain < len) {
        remain = width;
        height++;
    }
    
    remain -= len;
}

int height(string s, int width) {
    int remain = width;
    int len = 0;
    int height = 1;
    for (char c: s) {
        len++;
        if (c == ' ') {
            substract(remain, height, width, len);
            len = 0;
            substract(remain, height, width, 1);
        }
    }
    
    return height;
}

int main() {
    assert(height("This is the long text", 5) == 5);
    assert(height("I need to test if this is pass", 10) == 4);
}