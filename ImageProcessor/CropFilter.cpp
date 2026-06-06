#include "CropFilter.h"
#include "Exceptions.h"

#include <cstdint>
#include <algorithm>

namespace ip {

    CropFilter::CropFilter(int x, int y, int w, int h)
        : m_x(x), m_y(y), m_w(w), m_h(h) {
    }

    void CropFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        if (m_x < 0 || m_y < 0 || m_w <= 0 || m_h <= 0 ||
            m_x + m_w > width || m_y + m_h > height) {
            throw FilterError("CropFilter: invalid crop region");
        }

        ImageBuffer result(m_w, m_h);

        for (int y = 0; y < m_h; ++y) {
            const uint8_t* src = image.rowPtr(m_y + y);
            uint8_t* dst = result.rowPtr(y);
            for (int x = 0; x < m_w; ++x) {
                dst[x * 3 + 0] = src[(m_x + x) * 3 + 0];
                dst[x * 3 + 1] = src[(m_x + x) * 3 + 1];
                dst[x * 3 + 2] = src[(m_x + x) * 3 + 2];
            }
        }

        image = std::move(result);
    }

} // namespace ip