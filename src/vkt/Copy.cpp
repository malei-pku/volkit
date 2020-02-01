#include <vkt/Copy.hpp>
#include <vkt/StructuredVolume.hpp>

#include <vkt/Copy.h>
#include <vkt/StructuredVolume.h>

#include "Copy_cuda.hpp"
#include "Copy_serial.hpp"
#include "macros.hpp"
#include "StructuredVolume_impl.hpp"

//-------------------------------------------------------------------------------------------------
// C++ API
//

namespace vkt
{
    Error CopyRange(
            StructuredVolume& dst,
            StructuredVolume& src,
            int32_t firstX,
            int32_t firstY,
            int32_t firstZ,
            int32_t lastX,
            int32_t lastY,
            int32_t lastZ,
            int32_t dstOffsetX,
            int32_t dstOffsetY,
            int32_t dstOffsetZ
            )
    {
        VKT_CALL__(
            CopyRange,
            dst,
            src,
            Vec3i(firstX, firstY, firstZ),
            Vec3i(lastX, lastY, lastZ),
            Vec3i(dstOffsetX, dstOffsetY, dstOffsetZ)
            );

        return NO_ERROR;
    }

    Error CopyRange(
            StructuredVolume& dst,
            StructuredVolume& src,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        VKT_CALL__(CopyRange, dst, src, first, last, dstOffset);

        return NO_ERROR;
    }

} // vkt

//-------------------------------------------------------------------------------------------------
// C API
//

vktError vktCopyRangeSV(
        vktStructuredVolume dst,
        vktStructuredVolume src,
        int32_t firstX,
        int32_t firstY,
        int32_t firstZ,
        int32_t lastX,
        int32_t lastY,
        int32_t lastZ,
        int32_t dstOffsetX,
        int32_t dstOffsetY,
        int32_t dstOffsetZ
        )
{
    VKT_CALL__(
        CopyRange,
        dst->volume,
        src->volume,
        vkt::Vec3i(firstX, firstY, firstZ),
        vkt::Vec3i(lastX, lastY, lastZ),
        vkt::Vec3i(dstOffsetX, dstOffsetY, dstOffsetZ)
        );

    return VKT_NO_ERROR;
}
