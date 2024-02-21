#include<iostream>
#include <algorithm>
#include "ns3/time-wheel.h"


namespace ns3{
	TimeWheel::TimeWheel(){
	}
	void TimeWheel::PushStartTime(ns3::QPN_Time qpn_time){
		start_time_wheel.push_back(qpn_time);
	}
	void TimeWheel::PushFinishTime(ns3::QPN_Time qpn_time){
		finish_time_wheel.push_back(qpn_time);
	}
	ns3::QPN_Time TimeWheel::PopStartTime(){
		ns3::QPN_Time temp=start_time_wheel[0];
		std::vector<ns3::QPN_Time>::iterator k=start_time_wheel.begin();
		start_time_wheel.erase(k);
		return temp;
	}
	ns3::QPN_Time TimeWheel::PopFinishTime(){
		ns3::QPN_Time temp=finish_time_wheel[0];
		std::vector<ns3::QPN_Time>::iterator k=finish_time_wheel.begin();
		finish_time_wheel.erase(k);
		return temp;
	}
	void TimeWheel::SortStartTime(){
		std::make_heap(start_time_wheel.begin(),start_time_wheel.end());
		std::sort_heap(start_time_wheel.begin(),start_time_wheel.end());
	}
    void TimeWheel::SortFinishTime(){
    	std::make_heap(finish_time_wheel.begin(),finish_time_wheel.end());
    	std::sort_heap(finish_time_wheel.begin(),finish_time_wheel.end());
    }
    uint32_t TimeWheel::LengthStartTimeWheel(){
    	return (uint32_t)start_time_wheel.size();
    }
    uint32_t TimeWheel::LengthFinishTimeWheel(){
    	return (uint32_t)finish_time_wheel.size();
    }
}