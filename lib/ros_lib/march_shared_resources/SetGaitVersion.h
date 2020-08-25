#ifndef _ROS_SERVICE_SetGaitVersion_h
#define _ROS_SERVICE_SetGaitVersion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char SETGAITVERSION[] = "march_shared_resources/SetGaitVersion";

  class SetGaitVersionRequest : public ros::Msg
  {
    public:
      typedef const char* _gait_type;
      _gait_type gait;
      uint32_t subgaits_length;
      typedef char* _subgaits_type;
      _subgaits_type st_subgaits;
      _subgaits_type * subgaits;
      uint32_t versions_length;
      typedef char* _versions_type;
      _versions_type st_versions;
      _versions_type * versions;

    SetGaitVersionRequest():
      gait(""),
      subgaits_length(0), subgaits(NULL),
      versions_length(0), versions(NULL)
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
      *(outbuffer + offset + 0) = (this->versions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->versions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->versions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->versions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->versions_length);
      for( uint32_t i = 0; i < versions_length; i++){
      uint32_t length_versionsi = strlen(this->versions[i]);
      varToArr(outbuffer + offset, length_versionsi);
      offset += 4;
      memcpy(outbuffer + offset, this->versions[i], length_versionsi);
      offset += length_versionsi;
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
      uint32_t versions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      versions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      versions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      versions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->versions_length);
      if(versions_lengthT > versions_length)
        this->versions = (char**)realloc(this->versions, versions_lengthT * sizeof(char*));
      versions_length = versions_lengthT;
      for( uint32_t i = 0; i < versions_length; i++){
      uint32_t length_st_versions;
      arrToVar(length_st_versions, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_versions; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_versions-1]=0;
      this->st_versions = (char *)(inbuffer + offset-1);
      offset += length_st_versions;
        memcpy( &(this->versions[i]), &(this->st_versions), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SETGAITVERSION; };
    const char * getMD5(){ return "f7723c86866cf380148082df35441a88"; };

  };

  class SetGaitVersionResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SetGaitVersionResponse():
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

    const char * getType(){ return SETGAITVERSION; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SetGaitVersion {
    public:
    typedef SetGaitVersionRequest Request;
    typedef SetGaitVersionResponse Response;
  };

}
#endif
