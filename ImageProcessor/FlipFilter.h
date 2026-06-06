#pragma once

#include "ImageBuffer.h"
#include <string>

namespace ip {

    class FlipFilter {
    public:
        explicit FlipFilter(const std::string& direction); // "horizontal" or "vertical"
        void apply(ImageBuffer& image);

    private:
        std::string m_direction;
    };

} // namespace ip