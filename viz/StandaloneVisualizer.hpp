//
// Copyright (c) 2015-2017, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
// Copyright (c) 2015-2017, University of Bremen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
#ifndef __MAPS_VIZ_STANDALONEVISUALIZER_HPP_
#define __MAPS_VIZ_STANDALONEVISUALIZER_HPP_

#include <boost/scoped_ptr.hpp>

#include <maps/grid/MLSMap.hpp>
#include <maps/grid/OccupancyGridMap.hpp>
#include <maps/grid/TraversabilityGrid.hpp>
#include <maps/grid/TraversabilityMap3d.hpp>

namespace maps{ namespace grid
{

class StandaloneVisualizer
{
    class Impl;
    boost::scoped_ptr<Impl> impl;
public:
    StandaloneVisualizer();
    ~StandaloneVisualizer();

    bool wait(int usecs = 1000);

    void updateData(const ::maps::grid::MLSMapKalman& mls);
    void updateData(const ::maps::grid::MLSMapSloped& mls);
    void updateData(const ::maps::grid::MLSMapPrecalculated& mls);
    void updateData(const ::maps::grid::MLSMapBase& mls);
    void updateData(const ::maps::grid::OccupancyGridMap& grid);
    void updateData(const ::maps::grid::TraversabilityGrid& travGrid);
    void updateData(const ::maps::grid::TraversabilityMap3d<maps::grid::TraversabilityNodeBase*>& travGrid);

};

} /* namespace grid */
} /* namespace maps */

#endif /* __MAPS_VIZ_STANDALONEVISUALIZER_HPP_ */
