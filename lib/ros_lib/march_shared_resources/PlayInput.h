#ifndef _ROS_SERVICE_PlayInput_h
#define _ROS_SERVICE_PlayInput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char PLAYINPUT[] = "march_shared_resources/PlayInput";

  class PlayInputRequest : public ros::Msg
  {
    public:
      typedef int64_t _play_input_type;
      _play_input_type play_input;

    PlayInputRequest():
      play_input(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_play_input;
      u_play_input.real = this->play_input;
      *(outbuffer + offset + 0) = (u_play_input.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_play_input.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_play_input.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_play_input.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_play_input.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_play_input.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_play_input.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_play_input.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->play_input);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_play_input;
      u_play_input.base = 0;
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_play_input.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->play_input = u_play_input.real;
      offset += sizeof(this->play_input);
     return offset;
    }

    const char * getType(){ return PLAYINPUT; };
    const char * getMD5(){ return "fc968e449017caef1e2788eccc41a159"; };

  };

  class PlayInputResponse : public ros::Msg
  {
    public:
      typedef bool _is_successful_type;
      _is_successful_type is_successful;
      typedef const char* _message_type;
      _message_type message;

    PlayInputResponse():
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

    const char * getType(){ return PLAYINPUT; };
    const char * getMD5(){ return "92814ca95de64c716f615f50abf3a8c8"; };

  };

  class PlayInput {
    public:
    typedef PlayInputRequest Request;
    typedef PlayInputResponse Response;
  };

}
#endif
