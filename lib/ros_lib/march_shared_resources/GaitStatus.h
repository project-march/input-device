#ifndef _ROS_march_shared_resources_GaitStatus_h
#define _ROS_march_shared_resources_GaitStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class GaitStatus : public ros::Msg
  {
    public:
      typedef int64_t _type_type;
      _type_type type;
      typedef const char* _gait_name_type;
      _gait_name_type gait_name;

    GaitStatus():
      type(0),
      gait_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_gait_name = strlen(this->gait_name);
      varToArr(outbuffer + offset, length_gait_name);
      offset += 4;
      memcpy(outbuffer + offset, this->gait_name, length_gait_name);
      offset += length_gait_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t length_gait_name;
      arrToVar(length_gait_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait_name-1]=0;
      this->gait_name = (char *)(inbuffer + offset-1);
      offset += length_gait_name;
     return offset;
    }

    const char * getType(){ return "march_shared_resources/GaitStatus"; };
    const char * getMD5(){ return "ac2e94188f865942da982b5b64401ab2"; };

  };

}
#endif
