#ifndef _ROS_march_shared_resources_CurrentGait_h
#define _ROS_march_shared_resources_CurrentGait_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace march_shared_resources
{

  class CurrentGait : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _gait_type;
      _gait_type gait;
      typedef const char* _subgait_type;
      _subgait_type subgait;
      typedef const char* _version_type;
      _version_type version;
      typedef ros::Duration _duration_type;
      _duration_type duration;
      typedef const char* _gait_type_type;
      _gait_type_type gait_type;

    CurrentGait():
      header(),
      gait(""),
      subgait(""),
      version(""),
      duration(),
      gait_type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_gait = strlen(this->gait);
      varToArr(outbuffer + offset, length_gait);
      offset += 4;
      memcpy(outbuffer + offset, this->gait, length_gait);
      offset += length_gait;
      uint32_t length_subgait = strlen(this->subgait);
      varToArr(outbuffer + offset, length_subgait);
      offset += 4;
      memcpy(outbuffer + offset, this->subgait, length_subgait);
      offset += length_subgait;
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
      uint32_t length_gait_type = strlen(this->gait_type);
      varToArr(outbuffer + offset, length_gait_type);
      offset += 4;
      memcpy(outbuffer + offset, this->gait_type, length_gait_type);
      offset += length_gait_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_gait;
      arrToVar(length_gait, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait-1]=0;
      this->gait = (char *)(inbuffer + offset-1);
      offset += length_gait;
      uint32_t length_subgait;
      arrToVar(length_subgait, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subgait; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subgait-1]=0;
      this->subgait = (char *)(inbuffer + offset-1);
      offset += length_subgait;
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
      uint32_t length_gait_type;
      arrToVar(length_gait_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait_type-1]=0;
      this->gait_type = (char *)(inbuffer + offset-1);
      offset += length_gait_type;
     return offset;
    }

    const char * getType(){ return "march_shared_resources/CurrentGait"; };
    const char * getMD5(){ return "05545223cf87f9c70c68a04b825e8621"; };

  };

}
#endif
