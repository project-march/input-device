#ifndef _ROS_SERVICE_ContainsGait_h
#define _ROS_SERVICE_ContainsGait_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char CONTAINSGAIT[] = "march_shared_resources/ContainsGait";

  class ContainsGaitRequest : public ros::Msg
  {
    public:
      typedef const char* _gait_type;
      _gait_type gait;
      uint32_t subgaits_length;
      typedef char* _subgaits_type;
      _subgaits_type st_subgaits;
      _subgaits_type * subgaits;

    ContainsGaitRequest():
      gait(""),
      subgaits_length(0), subgaits(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_gait = strlen(this->gait);
      varToArr(outbuffer + offset, length_gait);
      offset += 4;
      memcpy(outbuffer + offset, this->gait, length_gait);
      offset += length_gait;
      *(outbuffer + offset + 0) = (this->subgaits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subgaits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subgaits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subgaits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subgaits_length);
      for( uint32_t i = 0; i < subgaits_length; i++){
      uint32_t length_subgaitsi = strlen(this->subgaits[i]);
      varToArr(outbuffer + offset, length_subgaitsi);
      offset += 4;
      memcpy(outbuffer + offset, this->subgaits[i], length_subgaitsi);
      offset += length_subgaitsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_gait;
      arrToVar(length_gait, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gait; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gait-1]=0;
      this->gait = (char *)(inbuffer + offset-1);
      offset += length_gait;
      uint32_t subgaits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subgaits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subgaits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subgaits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->subgaits_length);
      if(subgaits_lengthT > subgaits_length)
        this->subgaits = (char**)realloc(this->subgaits, subgaits_lengthT * sizeof(char*));
      subgaits_length = subgaits_lengthT;
      for( uint32_t i = 0; i < subgaits_length; i++){
      uint32_t length_st_subgaits;
      arrToVar(length_st_subgaits, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_subgaits; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_subgaits-1]=0;
      this->st_subgaits = (char *)(inbuffer + offset-1);
      offset += length_st_subgaits;
        memcpy( &(this->subgaits[i]), &(this->st_subgaits), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return CONTAINSGAIT; };
    const char * getMD5(){ return "c234d34b1f77b3f85ab7f59d681e4aab"; };

  };

  class ContainsGaitResponse : public ros::Msg
  {
    public:
      typedef bool _contains_type;
      _contains_type contains;

    ContainsGaitResponse():
      contains(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_contains;
      u_contains.real = this->contains;
      *(outbuffer + offset + 0) = (u_contains.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contains);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_contains;
      u_contains.base = 0;
      u_contains.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contains = u_contains.real;
      offset += sizeof(this->contains);
     return offset;
    }

    const char * getType(){ return CONTAINSGAIT; };
    const char * getMD5(){ return "5865510046ec078baae5a62527defb32"; };

  };

  class ContainsGait {
    public:
    typedef ContainsGaitRequest Request;
    typedef ContainsGaitResponse Response;
  };

}
#endif
