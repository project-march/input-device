#ifndef _ROS_march_shared_resources_StepSize_h
#define _ROS_march_shared_resources_StepSize_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class StepSize : public ros::Msg
  {
    public:
      typedef float _step_size_type;
      _step_size_type step_size;

    StepSize():
      step_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->step_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->step_size));
     return offset;
    }

    const char * getType(){ return "march_shared_resources/StepSize"; };
    const char * getMD5(){ return "76290af81b223bb4ba79cf43558301b6"; };

  };

}
#endif