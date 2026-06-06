#pragma once

#include "ImageBuffer.h"

namespace ip {

    class ThresholdFilter {
    public:
        explicit ThresholdFilter(int threshold);
        void apply(ImageBuffer& image);

    private:
        int m_threshold;
    };

} // namespace ip