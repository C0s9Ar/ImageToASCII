#include "../Header/Util.h"

int main() {
    float compression;
    int symbolWidth, symbolHeight;
    string imagePath;

    readInputs(compression, symbolWidth, symbolHeight, imagePath);

    Image image;
    if (!loadImage(image, imagePath)) {
        cout << "Failed to load image from the specified path." << endl;
        return -1;
    }

    generateASCIIArt(image, compression, symbolWidth, symbolHeight);
    system("pause");
    return 0;
}
