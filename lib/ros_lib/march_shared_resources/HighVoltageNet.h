#ifndef _ROS_march_shared_resources_HighVoltageNet_h
#define _ROS_march_shared_resources_HighVoltageNet_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class HighVoltageNet : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _operational_type;
      _operational_type operational;
      typedef bool _overcurrent_triggered_type;
      _overcurrent_triggered_type overcurrent_triggered;

    HighVoltageNet():
      name(""),
      operational(0),
      overcurrent_triggered(0)
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
        bool real;
        uint8_t base;
      } u_overcurrent_triggered;
      u_overcurrent_triggered.real = this->overcurrent_triggered;
      *(outbuffer + offset + 0) = (u_overcurrent_triggered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->overcurrent_triggered);
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
        bool real;
        uint8_t base;
      } u_overcurrent_triggered;
      u_overcurrent_triggered.base = 0;
      u_overcurrent_triggered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->overcurrent_triggered = u_overcurrent_triggered.real;
      offset += sizeof(this->overcurrent_triggered);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/HighVoltageNet"; };
    const char * getMD5(){ return "c9eff07a2a8705cd8361d1a06aead6fe"; };

  };

}
#endif
