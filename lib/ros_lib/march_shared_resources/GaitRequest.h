#ifndef _ROS_SERVICE_GaitRequest_h
#define _ROS_SERVICE_GaitRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char GAITREQUEST[] = "march_shared_resources/GaitRequest";

  class GaitRequestRequest : public ros::Msg
  {
    public:
      typedef const char* _gait_file_type;
      _gait_file_type gait_file;

    GaitRequestRequest():
      gait_file("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_gait_file = strlen(this->gait_file);
      varToArr(outbuffer + offset, length_gait_file);
      offset += 4;
      memcpy(outbuffer + offset, this->gait_file, length_gait_file);
      offset += length_gait_file;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_gait_file;
      arrToVar(length_gait_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait_file-1]=0;
      this->gait_file = (char *)(inbuffer + offset-1);
      offset += length_gait_file;
     return offset;
    }

    const char * getType(){ return GAITREQUEST; };
    const char * getMD5(){ return "f891f6238cf59a5f9f2daa63e7a355a4"; };

  };

  class GaitRequestResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    GaitRequestResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
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
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
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

    const char * getType(){ return GAITREQUEST; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class GaitRequest {
    public:
    typedef GaitRequestRequest Request;
    typedef GaitRequestResponse Response;
  };

}
#endif
