#include "HistogramFilter.h"

#include <cstdint>
#include <iostream>
#include <array>

namespace ip {

    void HistogramFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        std::array<int, 256> histB = {};
        std::array<int, 256> histG = {};
        std::array<int, 256> histR = {};

        for (int y = 0; y < height; ++y) {
            const uint8_t* row = image.rowPtr(y);
            for (int x = 0; x < width; ++x) {
                histB[row[x * 3 + 0]]++;
                histG[row[x * 3 + 1]]++;
                histR[row[x * 3 + 2]]++;
            }
        }

        std::cout << "\n=== Histogram ===\n";
        std::cout << "Value\t  B\t  G\t  R\n";
        for (int i = 0; i < 256; ++i) {
            if (histB[i] > 0 || histG[i] > 0 || histR[i] > 0) {
                std::cout << i << "\t"
                    << histB[i] << "\t"
                    << histG[i] << "\t"
                    << histR[i] << "\n";
            }
        }
    }

} // namespace ip