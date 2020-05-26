#ifndef _ROS_SERVICE_CurrentState_h
#define _ROS_SERVICE_CurrentState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char CURRENTSTATE[] = "march_shared_resources/CurrentState";

  class CurrentStateRequest : public ros::Msg
  {
    public:

    CurrentStateRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return CURRENTSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class CurrentStateResponse : public ros::Msg
  {
    public:
      typedef const char* _state_type_type;
      _state_type_type state_type;
      typedef const char* _current_state_type;
      _current_state_type current_state;

    CurrentStateResponse():
      state_type(""),
      current_state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_state_type = strlen(this->state_type);
      varToArr(outbuffer + offset, length_state_type);
      offset += 4;
      memcpy(outbuffer + offset, this->state_type, length_state_type);
      offset += length_state_type;
      uint32_t length_current_state = strlen(this->current_state);
      varToArr(outbuffer + offset, length_current_state);
      offset += 4;
      memcpy(outbuffer + offset, this->current_state, length_current_state);
      offset += length_current_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_state_type;
      arrToVar(length_state_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state_type-1]=0;
      this->state_type = (char *)(inbuffer + offset-1);
      offset += length_state_type;
      uint32_t length_current_state;
      arrToVar(length_current_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_state-1]=0;
      this->current_state = (char *)(inbuffer + offset-1);
      offset += length_current_state;
     return offset;
    }

    const char * getType(){ return CURRENTSTATE; };
    const char * getMD5(){ return "aa90f5901bca2a743ef9c01d50bd9de0"; };

  };

  class CurrentState {
    public:
    typedef CurrentStateRequest Request;
    typedef CurrentStateResponse Response;
  };

}
#endif
