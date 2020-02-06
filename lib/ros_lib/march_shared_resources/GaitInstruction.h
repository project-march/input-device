#ifndef _ROS_march_shared_resources_GaitInstruction_h
#define _ROS_march_shared_resources_GaitInstruction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace march_shared_resources
{

  class GaitInstruction : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _type_type;
      _type_type type;
      typedef const char* _gait_name_type;
      _gait_name_type gait_name;
      enum { STOP =  0 };
      enum { GAIT =  1 };
      enum { PAUSE =  2 };
      enum { CONTINUE =  3 };
      enum { INCREMENT_STEP_SIZE =  4 };
      enum { DECREMENT_STEP_SIZE =  5 };

    GaitInstruction():
      header(),
      type(0),
      gait_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
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
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
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

    const char * getType(){ return "march_shared_resources/GaitInstruction"; };
    const char * getMD5(){ return "f655c02301e6cc940112aec0256d56ae"; };

  };

}
#endif
