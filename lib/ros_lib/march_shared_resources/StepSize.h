#ifndef _ROS_march_shared_resources_StepSize_h
#define _ROS_march_shared_resources_StepSize_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class StepSize : public ros::Msg
  {
    public:
      typedef double _step_size_type;
      _step_size_type step_size;

    StepSize():
      step_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_step_size;
      u_step_size.real = this->step_size;
      *(outbuffer + offset + 0) = (u_step_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_step_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_step_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_step_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_step_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->step_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_step_size;
      u_step_size.base = 0;
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_step_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->step_size = u_step_size.real;
      offset += sizeof(this->step_size);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/StepSize"; };
    const char * getMD5(){ return "76290af81b223bb4ba79cf43558301b6"; };

  };

}
#endif
