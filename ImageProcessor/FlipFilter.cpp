#include "FlipFilter.h"
#include "Exceptions.h"
#include <algorithm>
#include <cstdint>

namespace ip {

    FlipFilter::FlipFilter(const std::string& direction)
        : m_direction(direction) {
    }

    void FlipFilter::apply(ImageBuffer& image) {
        const int width = image.width();
        const int height = image.height();

        if (m_direction == "horizontal") {
            for (int y = 0; y < height; ++y) {
                uint8_t* row = image.rowPtr(y);
                for (int x = 0; x < width / 2; ++x) {
                    int mirror = width - 1 - x;
                    std::swap(row[x * 3 + 0], row[mirror * 3 + 0]);
                    std::swap(row[x * 3 + 1], row[mirror * 3 + 1]);
                    std::swap(row[x * 3 + 2], row[mirror * 3 + 2]);
                }
            }
        }
        else if (m_direction == "vertical") {
            for (int y = 0; y < height / 2; ++y) {
                uint8_t* top = image.rowPtr(y);
                uint8_t* bottom = image.rowPtr(height - 1 - y);
                for (int x = 0; x < width; ++x) {
                    std::swap(top[x * 3 + 0], bottom[x * 3 + 0]);
                    std::swap(top[x * 3 + 1], bottom[x * 3 + 1]);
                    std::swap(top[x * 3 + 2], bottom[x * 3 + 2]);
                }
            }
        }
        else {
            throw FilterError("FlipFilter: unknown direction: " + m_direction);
        }
    }

} // namespace ip