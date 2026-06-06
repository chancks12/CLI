#include "BrightnessFilter.h"

#include <cstdint>
#include <algorithm>

namespace ip {

    BrightnessFilter::BrightnessFilter(int delta)
        : m_delta(delta) {
    }

    void BrightnessFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        for (int y = 0; y < height; ++y) {
            uint8_t* row = image.rowPtr(y);
            for (int x = 0; x < width; ++x) {
                for (int c = 0; c < 3; ++c) {
                    int val = row[x * 3 + c] + m_delta;
                    // 0~255 범위 클램핑
                    val = std::clamp(val, 0, 255);
                    row[x * 3 + c] = static_cast<uint8_t>(val);
                }
            }
        }
    }

} // namespace ip