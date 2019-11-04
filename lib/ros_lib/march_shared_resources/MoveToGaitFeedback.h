#ifndef _ROS_march_shared_resources_MoveToGaitFeedback_h
#define _ROS_march_shared_resources_MoveToGaitFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace march_shared_resources
{

  class MoveToGaitFeedback : public ros::Msg
  {
    public:

    MoveToGaitFeedback()
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

    const char * getType(){ return "march_shared_resources/MoveToGaitFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
