//
// Created by misha on 27.12.2018.
//

#include "BMP.h"

template<class T>
void write(std::ofstream &file, T data) {
    file.write(reinterpret_cast<char *>(&data), sizeof(data));
}


uint8_t read_u8(std::ifstream &file) {
    uint8_t res;
    file.read(reinterpret_cast<char *>(&res), sizeof(res));
    return res;
}

uint16_t read_u16(std::ifstream &file) {
    uint16_t res;
    file.read(reinterpret_cast<char *>(&res), sizeof(res));
    return res;
}

uint32_t read_u24(std::ifstream &file) {
    uint16_t res;
    uint8_t res2;
    file.read(reinterpret_cast<char *>(&res), sizeof(res));
    file.read(reinterpret_cast<char *>(&res2), sizeof(res2));
    return (res << 16) | res2;
}

uint32_t read_u32(std::ifstream &file) {
    uint32_t res;
    file.read(reinterpret_cast<char *>(&res), sizeof(res));
    return res;
}

int32_t read_s32(std::ifstream &file) {
    int32_t res;
    file.read(reinterpret_cast<char *>(&res), sizeof(res));
    return res;
}

BMP::BMP(std::string filename) {
    std::ifstream file(filename, std::ios::binary);

    fileHeader.type = read_u16(file);
    fileHeader.size = read_u32(file);
    fileHeader.reserved1 = read_u16(file);
    fileHeader.reserved2 = read_u16(file);
    fileHeader.offBits = read_u32(file);

    infoHeader.size = read_u32(file);
    infoHeader.width = read_s32(file);
    infoHeader.height = read_s32(file);
    infoHeader.planes = read_u16(file);
    infoHeader.bitCount = read_u16(file);
    infoHeader.compression = read_u32(file);
    infoHeader.sizeImage = read_u32(file);
    infoHeader.xPelsPerMeter = read_s32(file);
    infoHeader.yPelsPerMeter = read_s32(file);
    infoHeader.clrUsed = read_u32(file);
    infoHeader.clrImportant = read_u32(file);

    std::cout << "Size: " << infoHeader.width << "x" << infoHeader.height << std::endl;
    std::cout.flush();

    pixels = new RGBPixel *[infoHeader.width];

    for (int i = 0; i < infoHeader.width; i++) {
        pixels[i] = new RGBPixel[infoHeader.height];
    }

    std::cout << "Reading file..." << std::endl;
    for (int i = 0; i < infoHeader.width; i++) {
        for (int j = 0; j < infoHeader.height; j++) {
            pixels[i][j].blue = read_u8(file);
            pixels[i][j].green = read_u8(file);
            pixels[i][j].red = read_u8(file);
        }
    }

    std::cout << "Reading complete" << std::endl;

    file.close();
}

BMP::~BMP() {
    for (int i = 0; i < infoHeader.width; i++) {
        delete[] pixels[i];
    }
    delete[] pixels;
}

RGBPixel BMP::getPixel(int x, int y) {
    return pixels[x][y];
}

void BMP::save(std::string filename) {
    std::ofstream file(filename, std::ios::binary);

    write(file, fileHeader.type);
    write(file, fileHeader.size);
    write(file, fileHeader.reserved1);
    write(file, fileHeader.reserved2);
    write(file, fileHeader.offBits);

    write(file, infoHeader.size);
    write(file, infoHeader.width);
    write(file, infoHeader.height);
    write(file, infoHeader.planes);
    write(file, infoHeader.bitCount);
    write(file, infoHeader.compression);
    write(file, infoHeader.sizeImage);
    write(file, infoHeader.xPelsPerMeter);
    write(file, infoHeader.yPelsPerMeter);
    write(file, infoHeader.clrUsed);
    write(file, infoHeader.clrImportant);

    for (int x = 0; x < infoHeader.width; x++) {
        for (int y = 0; y < infoHeader.height; y++) {

            RGBPixel &pixel = pixels[x][y];
            if (pixel.red == 0 && pixel.green == 0 && pixel.blue == 0) {
                pixel.blue = 200;
            }
            write<uint8_t>(file, pixel.blue);
            write<uint8_t>(file, pixel.green);
            write<uint8_t>(file, pixel.red);
//            write(file, pixels[x][y].reserved);
        }
//        write(file, (uint8_t) 0);
    }

    file.close();
}

void BMP::setPixel(int x, int y, RGBPixel &pixel) {
    pixels[x][y] = pixel;
}

int BMP::getWidth() const {
    return infoHeader.width;
}

int BMP::getHeight() const {
    return infoHeader.height;
}

bool operator==(const RGBPixel &p1, const RGBPixel &p2) {
    return p1.red == p2.red && p1.green == p2.green && p1.blue == p2.blue;
}

RGBPixel::RGBPixel(uint8_t blue, uint8_t green, uint8_t red, uint8_t reserved) : blue(blue), green(green), red(red),
                                                                                 reserved(reserved) {}

RGBPixel::RGBPixel(uint8_t blue, uint8_t green, uint8_t red) : blue(blue), green(green), red(red) { reserved = 0; }

RGBPixel::RGBPixel() {
    red = 0;
    green = 0;
    blue = 0;
    reserved = 0;
}
