#ifndef _ROS_march_shared_resources_GaitNameGoal_h
#define _ROS_march_shared_resources_GaitNameGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class GaitNameGoal : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _subgait_name_type;
      _subgait_name_type subgait_name;

    GaitNameGoal():
      name(""),
      subgait_name("")
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
      uint32_t length_subgait_name = strlen(this->subgait_name);
      varToArr(outbuffer + offset, length_subgait_name);
      offset += 4;
      memcpy(outbuffer + offset, this->subgait_name, length_subgait_name);
      offset += length_subgait_name;
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
      uint32_t length_subgait_name;
      arrToVar(length_subgait_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subgait_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subgait_name-1]=0;
      this->subgait_name = (char *)(inbuffer + offset-1);
      offset += length_subgait_name;
     return offset;
    }

    const char * getType(){ return "march_shared_resources/GaitNameGoal"; };
    const char * getMD5(){ return "e4f9d9eca41dac8a80cbbd410479e54f"; };

  };

}
#endif
