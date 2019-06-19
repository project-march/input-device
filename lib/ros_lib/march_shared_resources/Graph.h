#ifndef _ROS_march_shared_resources_Graph_h
#define _ROS_march_shared_resources_Graph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class Graph : public ros::Msg
  {
    public:
      uint32_t from_subgait_length;
      typedef char* _from_subgait_type;
      _from_subgait_type st_from_subgait;
      _from_subgait_type * from_subgait;
      uint32_t to_subgait_length;
      typedef char* _to_subgait_type;
      _to_subgait_type st_to_subgait;
      _to_subgait_type * to_subgait;

    Graph():
      from_subgait_length(0), from_subgait(NULL),
      to_subgait_length(0), to_subgait(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->from_subgait_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->from_subgait_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->from_subgait_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->from_subgait_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->from_subgait_length);
      for( uint32_t i = 0; i < from_subgait_length; i++){
      uint32_t length_from_subgaiti = strlen(this->from_subgait[i]);
      varToArr(outbuffer + offset, length_from_subgaiti);
      offset += 4;
      memcpy(outbuffer + offset, this->from_subgait[i], length_from_subgaiti);
      offset += length_from_subgaiti;
      }
      *(outbuffer + offset + 0) = (this->to_subgait_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->to_subgait_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->to_subgait_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->to_subgait_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->to_subgait_length);
      for( uint32_t i = 0; i < to_subgait_length; i++){
      uint32_t length_to_subgaiti = strlen(this->to_subgait[i]);
      varToArr(outbuffer + offset, length_to_subgaiti);
      offset += 4;
      memcpy(outbuffer + offset, this->to_subgait[i], length_to_subgaiti);
      offset += length_to_subgaiti;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t from_subgait_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      from_subgait_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      from_subgait_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      from_subgait_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->from_subgait_length);
      if(from_subgait_lengthT > from_subgait_length)
        this->from_subgait = (char**)realloc(this->from_subgait, from_subgait_lengthT * sizeof(char*));
      from_subgait_length = from_subgait_lengthT;
      for( uint32_t i = 0; i < from_subgait_length; i++){
      uint32_t length_st_from_subgait;
      arrToVar(length_st_from_subgait, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_from_subgait; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_from_subgait-1]=0;
      this->st_from_subgait = (char *)(inbuffer + offset-1);
      offset += length_st_from_subgait;
        memcpy( &(this->from_subgait[i]), &(this->st_from_subgait), sizeof(char*));
      }
      uint32_t to_subgait_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      to_subgait_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      to_subgait_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      to_subgait_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->to_subgait_length);
      if(to_subgait_lengthT > to_subgait_length)
        this->to_subgait = (char**)realloc(this->to_subgait, to_subgait_lengthT * sizeof(char*));
      to_subgait_length = to_subgait_lengthT;
      for( uint32_t i = 0; i < to_subgait_length; i++){
      uint32_t length_st_to_subgait;
      arrToVar(length_st_to_subgait, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_to_subgait; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_to_subgait-1]=0;
      this->st_to_subgait = (char *)(inbuffer + offset-1);
      offset += length_st_to_subgait;
        memcpy( &(this->to_subgait[i]), &(this->st_to_subgait), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/Graph"; };
    const char * getMD5(){ return "2200ec54949ab38ab4e43720b46cd756"; };

  };

}
#endif
