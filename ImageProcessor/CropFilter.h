#pragma once

#include "ImageBuffer.h"

namespace ip {

    class CropFilter {
    public:
        CropFilter(int x, int y, int w, int h);
        void apply(ImageBuffer& image);

    private:
        int m_x, m_y, m_w, m_h;
    };

} // namespace ip