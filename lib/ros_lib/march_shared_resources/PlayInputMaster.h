#ifndef _ROS_march_shared_resources_PlayInputMaster_h
#define _ROS_march_shared_resources_PlayInputMaster_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class PlayInputMaster : public ros::Msg
  {
    public:
      typedef int64_t _play_input_type;
      _play_input_type play_input;

    PlayInputMaster():
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

    const char * getType(){ return "march_shared_resources/PlayInputMaster"; };
    const char * getMD5(){ return "fc968e449017caef1e2788eccc41a159"; };

  };

}
#endif
