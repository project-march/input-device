#ifndef _ROS_march_shared_resources_GaitAction_h
#define _ROS_march_shared_resources_GaitAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "march_shared_resources/GaitActionGoal.h"
#include "march_shared_resources/GaitActionResult.h"
#include "march_shared_resources/GaitActionFeedback.h"

namespace march_shared_resources
{

  class GaitAction : public ros::Msg
  {
    public:
      typedef march_shared_resources::GaitActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef march_shared_resources::GaitActionResult _action_result_type;
      _action_result_type action_result;
      typedef march_shared_resources::GaitActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GaitAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/GaitAction"; };
    const char * getMD5(){ return "07f5ae1dc17f9138b251fe67b0edca5f"; };

  };

}
#endif
