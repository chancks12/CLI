#include "BlurFilter.h"

#include <cstdint>
#include <vector>

namespace ip {

    void BlurFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        // 원본 복사 (컨볼루션은 원본 기준으로 계산해야 함)
        ImageBuffer original = image;

        // 3x3 평균 커널
        for (int y = 1; y < height - 1; ++y) {
            uint8_t* dst = image.rowPtr(y);
            for (int x = 1; x < width - 1; ++x) {
                for (int c = 0; c < 3; ++c) {
                    int sum = 0;
                    for (int ky = -1; ky <= 1; ++ky) {
                        const uint8_t* src = original.rowPtr(y + ky);
                        for (int kx = -1; kx <= 1; ++kx) {
                            sum += src[(x + kx) * 3 + c];
                        }
                    }
                    dst[x * 3 + c] = static_cast<uint8_t>(sum / 9);
                }
            }
        }
    }

} // namespace ip