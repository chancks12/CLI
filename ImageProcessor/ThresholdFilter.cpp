#include "ThresholdFilter.h"

#include <cstdint>

namespace ip {

    ThresholdFilter::ThresholdFilter(int threshold)
        : m_threshold(threshold) {
    }

    void ThresholdFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        for (int y = 0; y < height; ++y) {
            uint8_t* row = image.rowPtr(y);
            for (int x = 0; x < width; ++x) {
                uint8_t b = row[x * 3 + 0];
                uint8_t g = row[x * 3 + 1];
                uint8_t r = row[x * 3 + 2];

                // 먼저 grayscale로 변환 후 임계값 적용
                uint8_t gray = static_cast<uint8_t>(0.114 * b + 0.587 * g + 0.299 * r);
                uint8_t value = (gray >= m_threshold) ? 255 : 0;

                row[x * 3 + 0] = value;
                row[x * 3 + 1] = value;
                row[x * 3 + 2] = value;
            }
        }
    }

} // namespace ip