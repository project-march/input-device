#ifndef _ROS_SERVICE_GaitInstruction_h
#define _ROS_SERVICE_GaitInstruction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char GAITINSTRUCTION[] = "march_shared_resources/GaitInstruction";

  class GaitInstructionRequest : public ros::Msg
  {
    public:
      typedef int64_t _gait_type;
      _gait_type gait;

    GaitInstructionRequest():
      gait(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_gait;
      u_gait.real = this->gait;
      *(outbuffer + offset + 0) = (u_gait.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gait.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gait.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gait.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gait.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gait.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gait.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gait.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gait);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_gait;
      u_gait.base = 0;
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_gait.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->gait = u_gait.real;
      offset += sizeof(this->gait);
     return offset;
    }

    const char * getType(){ return GAITINSTRUCTION; };
    const char * getMD5(){ return "4cc8952470b45443ea64a94cb7d952ed"; };

  };

  class GaitInstructionResponse : public ros::Msg
  {
    public:
      typedef const char* _result_type;
      _result_type result;

    GaitInstructionResponse():
      result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_result = strlen(this->result);
      varToArr(outbuffer + offset, length_result);
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_result;
      arrToVar(length_result, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
     return offset;
    }

    const char * getType(){ return GAITINSTRUCTION; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class GaitInstruction {
    public:
    typedef GaitInstructionRequest Request;
    typedef GaitInstructionResponse Response;
  };

}
#endif
