#pragma once

#include "ImageBuffer.h"

namespace ip {

    class BrightnessFilter {
    public:
        explicit BrightnessFilter(int delta);
        void apply(ImageBuffer& image);

    private:
        int m_delta;
    };

} // namespace ip