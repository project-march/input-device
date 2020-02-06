#ifndef _ROS_SERVICE_PossibleGaits_h
#define _ROS_SERVICE_PossibleGaits_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

static const char POSSIBLEGAITS[] = "march_shared_resources/PossibleGaits";

  class PossibleGaitsRequest : public ros::Msg
  {
    public:

    PossibleGaitsRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return POSSIBLEGAITS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class PossibleGaitsResponse : public ros::Msg
  {
    public:
      uint32_t gaits_length;
      typedef char* _gaits_type;
      _gaits_type st_gaits;
      _gaits_type * gaits;

    PossibleGaitsResponse():
      gaits_length(0), gaits(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->gaits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gaits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gaits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gaits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gaits_length);
      for( uint32_t i = 0; i < gaits_length; i++){
      uint32_t length_gaitsi = strlen(this->gaits[i]);
      varToArr(outbuffer + offset, length_gaitsi);
      offset += 4;
      memcpy(outbuffer + offset, this->gaits[i], length_gaitsi);
      offset += length_gaitsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t gaits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gaits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gaits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gaits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gaits_length);
      if(gaits_lengthT > gaits_length)
        this->gaits = (char**)realloc(this->gaits, gaits_lengthT * sizeof(char*));
      gaits_length = gaits_lengthT;
      for( uint32_t i = 0; i < gaits_length; i++){
      uint32_t length_st_gaits;
      arrToVar(length_st_gaits, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_gaits; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_gaits-1]=0;
      this->st_gaits = (char *)(inbuffer + offset-1);
      offset += length_st_gaits;
        memcpy( &(this->gaits[i]), &(this->st_gaits), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return POSSIBLEGAITS; };
    const char * getMD5(){ return "c219eff76e391465811d4c90e35eb728"; };

  };

  class PossibleGaits {
    public:
    typedef PossibleGaitsRequest Request;
    typedef PossibleGaitsResponse Response;
  };

}
#endif
