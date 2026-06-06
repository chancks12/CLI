#pragma once

#include "ImageBuffer.h"

namespace ip {

    class HistogramFilter {
    public:
        void apply(ImageBuffer& image);
    };

} // namespace ip