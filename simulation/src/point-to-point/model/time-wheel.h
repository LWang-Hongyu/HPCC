#ifndef TIME_WHEEL_H
#define TIME_WHEEL_H

#include <vector>
#include <ns3/object.h>
#include "ns3/rdma-queue-pair.h"

namespace ns3 {

struct QPN_Time {
    Ptr<RdmaQueuePair> QP;
    Time time;//focused time
    Time othertime;//record time

    QPN_Time() : QP(NULL),time(Time(0)),othertime(Time(0)) {}
    QPN_Time(Ptr<RdmaQueuePair> QP, Time time,Time othertime) : QP(QP),time(time),othertime(othertime) {}
    bool operator<(const QPN_Time& other) const {
        return time > other.time;
    }
}; 
class TimeWheel :public Object{
public:
    TimeWheel();
    //virtual ~TimeWheel();

    std::vector<QPN_Time> start_time_wheel;
    std::vector<QPN_Time> finish_time_wheel;

    void PushStartTime(QPN_Time qpn_time);
    void PushFinishTime(QPN_Time qpn_time);

    void SortStartTime();
    void SortFinishTime();

    QPN_Time PopStartTime();
    QPN_Time PopFinishTime();

    uint32_t LengthStartTimeWheel();
    uint32_t LengthFinishTimeWheel();
};

} // namespace ns3

#endif