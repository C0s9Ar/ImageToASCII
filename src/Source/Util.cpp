#include "../Header/Util.h"

void readInputs(float& compression, int& symbol_width, int& symbol_height, string& image_path) {
    cout << "Enter path to the image file (e.g., 'img.png'): ";
    cin >> image_path;
    cout << "Enter compression factor (e.g., 2.0): ";
    cin >> compression;
    cout << "Enter symbol width (e.g., 1): ";
    cin >> symbol_width;
    cout << "Enter symbol height (e.g., 2): ";
    cin >> symbol_height;
}

bool loadImage(Image& image, const string& image_path) {
    return image.loadFromFile(image_path);
}

void generateASCIIArt(const Image& image, float compression, int symbol_width, int symbol_height) {
    stringstream string_stream;
    string palette = " `'. ^~_,-:;\\/!|*+()=><7[]1?il{}rtIvjJcu3znoL25Yf4sC%Vx&a0Teh96FyZwkUP$ODS@8XbGAgdKmREHpqNB#WQM";

    Vector2u size = image.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    int adjusted_symbol_width = static_cast<int>(symbol_width * compression);
    int adjusted_symbol_height = static_cast<int>(symbol_height * compression);

    for (unsigned int y = 0; y < height; y += adjusted_symbol_height) {
        for (unsigned int x = 0; x < width; x += adjusted_symbol_width) {
            Color pixel_color = image.getPixel(x, y);
            int average_color = (pixel_color.r + pixel_color.g + pixel_color.b) / 3;
            int normalized_value = static_cast<int>((average_color / 255.0) * (palette.size() - 1));
            string_stream << palette[normalized_value];
        }
        string_stream << '\n';
    }
    cout << string_stream.str();
}
