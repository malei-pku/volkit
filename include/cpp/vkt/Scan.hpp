#pragma once

#include <cstdint>

#include "common.hpp"
#include "forward.hpp"
#include "linalg.hpp"

namespace vkt
{
    VKTAPI Error Scan(StructuredVolume& dst,
                      StructuredVolume& src);

    VKTAPI Error ScanRange(StructuredVolume& dst,
                           StructuredVolume& src,
                           int32_t firstX,
                           int32_t firstY,
                           int32_t firstZ,
                           int32_t lastX,
                           int32_t lastY,
                           int32_t lastZ,
                           int32_t dstOffsetX = 0,
                           int32_t dstOffsetY = 0,
                           int32_t dstOffsetZ = 0);

    VKTAPI Error ScanRange(StructuredVolume& dst,
                           StructuredVolume& src,
                           vec3i first,
                           vec3i last,
                           vec3i dstOffset = vec3i(0));

} // vkt