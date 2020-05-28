#ifndef _ROS_march_shared_resources_GaitNameActionGoal_h
#define _ROS_march_shared_resources_GaitNameActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "march_shared_resources/GaitNameGoal.h"

namespace march_shared_resources
{

  class GaitNameActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef march_shared_resources::GaitNameGoal _goal_type;
      _goal_type goal;

    GaitNameActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/GaitNameActionGoal"; };
    const char * getMD5(){ return "c3fcbf5324c7c2a9996a8ed899520f78"; };

  };

}
#endif
