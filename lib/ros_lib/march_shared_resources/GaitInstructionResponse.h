#ifndef _ROS_march_shared_resources_GaitInstructionResponse_h
#define _ROS_march_shared_resources_GaitInstructionResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class GaitInstructionResponse : public ros::Msg
  {
    public:
      typedef int8_t _result_type;
      _result_type result;
      enum { GAIT_REJECTED =  -1 };
      enum { GAIT_ACCEPTED =  0 };
      enum { GAIT_FINISHED =  1 };

    GaitInstructionResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/GaitInstructionResponse"; };
    const char * getMD5(){ return "0a9a7173d5945f6df13f205af2597eb4"; };

  };

}
#endif
