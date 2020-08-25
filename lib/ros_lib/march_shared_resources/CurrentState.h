#ifndef _ROS_march_shared_resources_CurrentState_h
#define _ROS_march_shared_resources_CurrentState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace march_shared_resources
{

  class CurrentState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _state_type;
      _state_type state;
      typedef int8_t _state_type_type;
      _state_type_type state_type;
      enum { IDLE =  0 };
      enum { GAIT =  1 };

    CurrentState():
      header(),
      state(""),
      state_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      union {
        int8_t real;
        uint8_t base;
      } u_state_type;
      u_state_type.real = this->state_type;
      *(outbuffer + offset + 0) = (u_state_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      union {
        int8_t real;
        uint8_t base;
      } u_state_type;
      u_state_type.base = 0;
      u_state_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state_type = u_state_type.real;
      offset += sizeof(this->state_type);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/CurrentState"; };
    const char * getMD5(){ return "0fde5ff34496644ac8d85338bbbcbdcd"; };

  };

}
#endif
