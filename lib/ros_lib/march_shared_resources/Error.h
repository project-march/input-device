#ifndef _ROS_march_shared_resources_Error_h
#define _ROS_march_shared_resources_Error_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class Error : public ros::Msg
  {
    public:
      typedef int16_t _error_code_type;
      _error_code_type error_code;
      typedef const char* _error_message_type;
      _error_message_type error_message;
      typedef uint8_t _type_type;
      _type_type type;
      enum { FATAL =  0      };

    Error():
      error_code(0),
      error_message(""),
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_error_code;
      u_error_code.real = this->error_code;
      *(outbuffer + offset + 0) = (u_error_code.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_code.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->error_code);
      uint32_t length_error_message = strlen(this->error_message);
      varToArr(outbuffer + offset, length_error_message);
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_error_code;
      u_error_code.base = 0;
      u_error_code.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_code.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->error_code = u_error_code.real;
      offset += sizeof(this->error_code);
      uint32_t length_error_message;
      arrToVar(length_error_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/Error"; };
    const char * getMD5(){ return "69eb7217b9c1a457282de062edd13773"; };

  };

}
#endif
