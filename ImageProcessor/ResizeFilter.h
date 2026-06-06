#pragma once

#include "ImageBuffer.h"

namespace ip {

    class ResizeFilter {
    public:
        ResizeFilter(int w, int h);
        void apply(ImageBuffer& image);

    private:
        int m_w, m_h;
    };

} // namespace ip