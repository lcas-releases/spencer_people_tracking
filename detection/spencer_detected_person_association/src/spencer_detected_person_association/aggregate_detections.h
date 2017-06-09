/*
* Software License Agreement (BSD License)
*
*  Copyright (c) 2014-2015, Timm Linder, Social Robotics Lab, University of Freiburg
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  * Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*  * Neither the name of the copyright holder nor the names of its contributors
*    may be used to endorse or promote products derived from this software
*    without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
*  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _AGGREGATE_DETECTIONS_H
#define _AGGREGATE_DETECTIONS_H

#include <nodelet/nodelet.h>
#include "composite_detected_persons_synchronizer.h"

namespace spencer_detected_person_association
{
    /// Aggregates multiple spencer_tracking_msgs/CompositeDetectedPersons messages into a joint spencer_tracking_msgs/CompositeDetectedPerson message without
    /// performing any data association. Thus assumes that the sensor fields of the individual input messages are non-overlapping.
    /// The input messages must be in the same coordinate frame (header.frame_id).
    class AggregateDetectionsNodelet : public nodelet::Nodelet, protected CompositeDetectedPersonsSynchronizer
    {
    public:
        virtual void onInit();

    protected:
        /// Implements method of abstract DetectedPersonsSynchronizer base class
        virtual void onNewInputMessagesReceived(const std::vector<spencer_tracking_msgs::CompositeDetectedPersons::ConstPtr>& msgs);

    private:
        int m_seq;

    };
}


#endif // _AGGREGATE_DETECTIONS_H
