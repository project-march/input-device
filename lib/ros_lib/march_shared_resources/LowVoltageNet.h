#ifndef _ROS_march_shared_resources_LowVoltageNet_h
#define _ROS_march_shared_resources_LowVoltageNet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class LowVoltageNet : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _operational_type;
      _operational_type operational;
      typedef float _current_type;
      _current_type current;

    LowVoltageNet():
      name(""),
      operational(0),
      current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_operational;
      u_operational.real = this->operational;
      *(outbuffer + offset + 0) = (u_operational.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operational);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_operational;
      u_operational.base = 0;
      u_operational.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operational = u_operational.real;
      offset += sizeof(this->operational);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/LowVoltageNet"; };
    const char * getMD5(){ return "85f3bad605c5adef233dbc869c206dff"; };

  };

}
#endif
