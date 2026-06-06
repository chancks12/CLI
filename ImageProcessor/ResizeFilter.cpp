#include "ResizeFilter.h"
#include "Exceptions.h"

#include <cstdint>

namespace ip {

    ResizeFilter::ResizeFilter(int w, int h)
        : m_w(w), m_h(h) {
    }

    void ResizeFilter::apply(ImageBuffer& image) {
        if (m_w <= 0 || m_h <= 0) {
            throw FilterError("ResizeFilter: invalid size");
        }

        const int srcW = image.width();
        const int srcH = image.height();

        ImageBuffer result(m_w, m_h);

        for (int y = 0; y < m_h; ++y) {
            // nearest neighbor 보간
            int srcY = y * srcH / m_h;
            const uint8_t* src = image.rowPtr(srcY);
            uint8_t* dst = result.rowPtr(y);

            for (int x = 0; x < m_w; ++x) {
                int srcX = x * srcW / m_w;
                dst[x * 3 + 0] = src[srcX * 3 + 0];
                dst[x * 3 + 1] = src[srcX * 3 + 1];
                dst[x * 3 + 2] = src[srcX * 3 + 2];
            }
        }

        image = std::move(result);
    }

} // namespace ip