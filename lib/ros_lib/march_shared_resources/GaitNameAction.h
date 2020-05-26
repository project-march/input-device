#ifndef _ROS_march_shared_resources_GaitNameAction_h
#define _ROS_march_shared_resources_GaitNameAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "march_shared_resources/GaitNameActionGoal.h"
#include "march_shared_resources/GaitNameActionResult.h"
#include "march_shared_resources/GaitNameActionFeedback.h"

namespace march_shared_resources
{

  class GaitNameAction : public ros::Msg
  {
    public:
      typedef march_shared_resources::GaitNameActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef march_shared_resources::GaitNameActionResult _action_result_type;
      _action_result_type action_result;
      typedef march_shared_resources::GaitNameActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GaitNameAction():
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

    const char * getType(){ return "march_shared_resources/GaitNameAction"; };
    const char * getMD5(){ return "3d9dbfcd7eb406596122704f6e675e77"; };

  };

}
#endif
