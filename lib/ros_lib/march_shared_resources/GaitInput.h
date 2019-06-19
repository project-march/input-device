#ifndef _ROS_SERVICE_GaitInput_h
#define _ROS_SERVICE_GaitInput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char GAITINPUT[] = "march_shared_resources/GaitInput";

  class GaitInputRequest : public ros::Msg
  {
    public:
      typedef const char* _gait_name_type;
      _gait_name_type gait_name;
      typedef float _time_type;
      _time_type time;

    GaitInputRequest():
      gait_name(""),
      time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_gait_name = strlen(this->gait_name);
      varToArr(outbuffer + offset, length_gait_name);
      offset += 4;
      memcpy(outbuffer + offset, this->gait_name, length_gait_name);
      offset += length_gait_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_gait_name;
      arrToVar(length_gait_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait_name-1]=0;
      this->gait_name = (char *)(inbuffer + offset-1);
      offset += length_gait_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
     return offset;
    }

    const char * getType(){ return GAITINPUT; };
    const char * getMD5(){ return "2d623642030e07b94e6482959561c22f"; };

  };

  class GaitInputResponse : public ros::Msg
  {
    public:
      typedef bool _is_successful_type;
      _is_successful_type is_successful;
      typedef const char* _message_type;
      _message_type message;

    GaitInputResponse():
      is_successful(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_successful;
      u_is_successful.real = this->is_successful;
      *(outbuffer + offset + 0) = (u_is_successful.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_successful);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_successful;
      u_is_successful.base = 0;
      u_is_successful.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_successful = u_is_successful.real;
      offset += sizeof(this->is_successful);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return GAITINPUT; };
    const char * getMD5(){ return "92814ca95de64c716f615f50abf3a8c8"; };

  };

  class GaitInput {
    public:
    typedef GaitInputRequest Request;
    typedef GaitInputResponse Response;
  };

}
#endif
