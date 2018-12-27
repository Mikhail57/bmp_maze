#include <iostream>

#include "BMP.h"

int main() {
    BMP file("dnk.bmp");
    file.save("lol.bmp");
    return 0;
}