//
// Created by misha on 27.12.2018.
//

#ifndef BMP_MAZE_BMP_H
#define BMP_MAZE_BMP_H

#include <string>
#include <fstream>
#include <iostream>
#include "Geometry.h"

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offBits;
} BMPFileHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t clrUsed;
    uint32_t clrImportant;
} BMPInfoHeader;

class RGBPixel {
public:
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;

    RGBPixel(uint8_t blue, uint8_t green, uint8_t red, uint8_t reserved);

    RGBPixel(uint8_t blue, uint8_t green, uint8_t red);

    RGBPixel();

    bool operator==(const RGBPixel &rhs) const;

    bool operator!=(const RGBPixel &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const RGBPixel &pixel);
};

class BMP {
private:
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    RGBPixel **pixels;

public:
    explicit BMP(std::string filename);

    BMP(BMP &other);

    RGBPixel getPixel(int x, int y);

    void setPixel(int x, int y, RGBPixel &pixel);

    int getWidth() const;

    int getHeight() const;

    void save(std::string filename);

    RGBPixel operator[](const Point &p);

    ~BMP();
};


#endif //BMP_MAZE_BMP_H
