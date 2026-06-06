#include "GrayscaleFilter.h"

namespace ip {

    void GrayscaleFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        for (int y = 0; y < height; ++y) {
            uint8_t* row = image.rowPtr(y);
            for (int x = 0; x < width; ++x) {
                uint8_t b = row[x * 3 + 0];
                uint8_t g = row[x * 3 + 1];
                uint8_t r = row[x * 3 + 2];

                // RGB 가중치 공식
                uint8_t gray = static_cast<uint8_t>(0.114 * b + 0.587 * g + 0.299 * r);

                row[x * 3 + 0] = gray;
                row[x * 3 + 1] = gray;
                row[x * 3 + 2] = gray;
            }
        }
    }

} // namespace ip