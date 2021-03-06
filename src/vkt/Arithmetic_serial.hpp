// This file is distributed under the MIT license.
// See the LICENSE file for details.

#pragma once

#include <cmath>

#include <vkt/StructuredVolume.hpp>

#include "linalg.hpp"

namespace vkt
{
    template <typename Func>
    void ArithmeticOp(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset,
            Func func
            )
    {
        for (int32_t z = first.z; z != last.z; ++z)
        {
            for (int32_t y = first.y; y != last.y; ++y)
            {
                for (int32_t x = first.x; x != last.x; ++x)
                {
                    float val1 = source1.getValue(x, y, z);
                    float val2 = source2.getValue(x, y, z);

                    float val3 = func(val1, val2);

                    dest.setValue(
                        x + dstOffset.x,
                        y + dstOffset.y,
                        z + dstOffset.z,
                        val3
                        );
                }
            }
        }
    }

    void SumRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [](float f1, float f2) { return f1 + f2; }
            );
    }

    void DiffRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [](float f1, float f2) { return f1 - f2; }
            );
    }

    void ProdRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [](float f1, float f2) { return f1 * f2; }
            );
    }

    void QuotRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [](float f1, float f2) { return f1 / f2; }
            );
    }

    void AbsDiffRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [](float f1, float f2) { return fabsf(f1 - f2); }
            );
    }

    void SafeSumRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        float lo = dest.getVoxelMapping().x;
        float hi = dest.getVoxelMapping().y;

        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [lo, hi](float f1, float f2) { return clamp(f1 + f2, lo, hi); }
            );
    }

    void SafeDiffRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        float lo = dest.getVoxelMapping().x;
        float hi = dest.getVoxelMapping().y;

        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [lo, hi](float f1, float f2) { return clamp(f1 - f2, lo, hi); }
            );
    }

    void SafeProdRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        float lo = dest.getVoxelMapping().x;
        float hi = dest.getVoxelMapping().y;

        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [lo, hi](float f1, float f2) { return clamp(f1 * f2, lo, hi); }
            );
    }

    void SafeQuotRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        float lo = dest.getVoxelMapping().x;
        float hi = dest.getVoxelMapping().y;

        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [lo, hi](float f1, float f2) { return clamp(f1 / f2, lo, hi); }
            );
    }

    void SafeAbsDiffRange_serial(
            StructuredVolume& dest,
            StructuredVolume& source1,
            StructuredVolume& source2,
            Vec3i first,
            Vec3i last,
            Vec3i dstOffset
            )
    {
        float lo = dest.getVoxelMapping().x;
        float hi = dest.getVoxelMapping().y;

        ArithmeticOp(
            dest,
            source1,
            source2,
            first,
            last,
            dstOffset,
            [lo, hi](float f1, float f2) { return clamp(fabsf(f1 - f2), lo, hi); }
            );
    }

} // vkt
