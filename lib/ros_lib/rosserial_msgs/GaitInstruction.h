#ifndef _ROS_rosserial_msgs_GaitInstruction_h
#define _ROS_rosserial_msgs_GaitInstruction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosserial_msgs
{

  class GaitInstruction : public ros::Msg
  {
    public:
      typedef int16_t _type_type;
      _type_type type;
      typedef const char* _gait_name_type;
      _gait_name_type gait_name;
      enum { INPUT_DEVICE_LOST =  -1 };
      enum { STOP =  0 };
      enum { GAIT =  1 };
      enum { PAUSE =  2 };
      enum { CONTINUE =  3 };

    GaitInstruction():
      type(0),
      gait_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
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
        int16_t real;
        uint16_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
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

    const char * getType(){ return "rosserial_msgs/GaitInstruction"; };
    const char * getMD5(){ return "abd2750b2844ffd9e9397ec5f63a164d"; };

  };

}
#endif
