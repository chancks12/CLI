#pragma once

#include "ImageBuffer.h"

namespace ip {

    class BlurFilter {
    public:
        void apply(ImageBuffer& image);
    };

} // namespace ip