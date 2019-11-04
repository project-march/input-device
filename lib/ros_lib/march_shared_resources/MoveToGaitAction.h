#ifndef _ROS_march_shared_resources_MoveToGaitAction_h
#define _ROS_march_shared_resources_MoveToGaitAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "march_shared_resources/MoveToGaitActionGoal.h"
#include "march_shared_resources/MoveToGaitActionResult.h"
#include "march_shared_resources/MoveToGaitActionFeedback.h"

namespace march_shared_resources
{

  class MoveToGaitAction : public ros::Msg
  {
    public:
      typedef march_shared_resources::MoveToGaitActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef march_shared_resources::MoveToGaitActionResult _action_result_type;
      _action_result_type action_result;
      typedef march_shared_resources::MoveToGaitActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MoveToGaitAction():
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

    const char * getType(){ return "march_shared_resources/MoveToGaitAction"; };
    const char * getMD5(){ return "7f6f08d79e3be16de203dd0c4d237a26"; };

  };

}
#endif
