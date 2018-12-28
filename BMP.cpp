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

    pixels = new RGBPixel *[infoHeader.height];

    for (int i = 0; i < infoHeader.height; i++) {
        pixels[i] = new RGBPixel[infoHeader.width];
    }

    int lineWidth = (3 * infoHeader.width + 3) & (-4);
    int diff = lineWidth - infoHeader.width * 3;
//    std::cout << "lineWidth:" << lineWidth << std::endl;
//    std::cout << "diff:" << diff << std::endl;

    std::cout << "Reading file..." << std::endl;
    for (int y = infoHeader.height - 1; y >= 0; y--) {
        for (int x = 0; x < infoHeader.width; x++) {
            pixels[y][x].blue = read_u8(file);
            pixels[y][x].green = read_u8(file);
            pixels[y][x].red = read_u8(file);
        }
        file.seekg(diff, std::ios_base::cur);
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
    return pixels[y][x];
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

    int lineWidth = (3 * infoHeader.width + 3) & (-4);
    int diff = lineWidth - infoHeader.width * 3;
//    std::cout << "lineWidth:" << lineWidth << std::endl;
//    std::cout << "diff:" << diff << std::endl;


    for (int y = infoHeader.height - 1; y >= 0; y--) {
        for (int x = 0; x < infoHeader.width; x++) {

            RGBPixel &pixel = pixels[y][x];
            write<uint8_t>(file, pixel.blue);
            write<uint8_t>(file, pixel.green);
            write<uint8_t>(file, pixel.red);
//            write(file, pixels[x][y].reserved);
        }
        file.seekp(diff, std::ios_base::cur);
    }
    // TODO: fix this terrible appending to the end of file
    for (int i = 0; i < diff; i++) {
        write(file, (uint8_t)0);
    }

    file.close();
}

void BMP::setPixel(int x, int y, RGBPixel &pixel) {
    pixels[y][x] = pixel;
}

int BMP::getWidth() const {
    return infoHeader.width;
}

int BMP::getHeight() const {
    return infoHeader.height;
}

RGBPixel BMP::operator[](const Point &p) {
    return getPixel(p.x, p.y);
}

BMP::BMP(BMP &other) {
    fileHeader = other.fileHeader;
    infoHeader = other.infoHeader;

    pixels = new RGBPixel *[infoHeader.height];

    for (int y = 0; y < infoHeader.height; y++) {
        pixels[y] = new RGBPixel[infoHeader.width];
        for (int x = 0; x < infoHeader.width; x++) {
            pixels[y][x] = other.pixels[y][x];
        }
    }
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

bool RGBPixel::operator==(const RGBPixel &rhs) const {
    return blue == rhs.blue &&
           green == rhs.green &&
           red == rhs.red;
}

bool RGBPixel::operator!=(const RGBPixel &rhs) const {
    return !(rhs == *this);
}
