#ifndef _ROS_march_shared_resources_PerformGait_h
#define _ROS_march_shared_resources_PerformGait_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class PerformGait : public ros::Msg
  {
    public:
      typedef const char* _gait_name_type;
      _gait_name_type gait_name;
      typedef double _time_type;
      _time_type time;
      typedef int64_t _repeat_type;
      _repeat_type repeat;

    PerformGait():
      gait_name(""),
      time(0),
      repeat(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_gait_name = strlen(this->gait_name);
      varToArr(outbuffer + offset, length_gait_name);
      offset += 4;
      memcpy(outbuffer + offset, this->gait_name, length_gait_name);
      offset += length_gait_name;
      union {
        double real;
        uint64_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time);
      union {
        int64_t real;
        uint64_t base;
      } u_repeat;
      u_repeat.real = this->repeat;
      *(outbuffer + offset + 0) = (u_repeat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_repeat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_repeat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_repeat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_repeat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_repeat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_repeat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_repeat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->repeat);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_gait_name;
      arrToVar(length_gait_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait_name-1]=0;
      this->gait_name = (char *)(inbuffer + offset-1);
      offset += length_gait_name;
      union {
        double real;
        uint64_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time = u_time.real;
      offset += sizeof(this->time);
      union {
        int64_t real;
        uint64_t base;
      } u_repeat;
      u_repeat.base = 0;
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->repeat = u_repeat.real;
      offset += sizeof(this->repeat);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/PerformGait"; };
    const char * getMD5(){ return "c2856c4d066eecb97166932dc6907aa4"; };

  };

}
#endif
