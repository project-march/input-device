#ifndef _ROS_march_shared_resources_GaitGoal_h
#define _ROS_march_shared_resources_GaitGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "march_shared_resources/Graph.h"
#include "march_shared_resources/Subgait.h"

namespace march_shared_resources
{

  class GaitGoal : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef march_shared_resources::Graph _graph_type;
      _graph_type graph;
      typedef march_shared_resources::Subgait _current_subgait_type;
      _current_subgait_type current_subgait;

    GaitGoal():
      name(""),
      graph(),
      current_subgait()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->graph.serialize(outbuffer + offset);
      offset += this->current_subgait.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->graph.deserialize(inbuffer + offset);
      offset += this->current_subgait.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "march_shared_resources/GaitGoal"; };
    const char * getMD5(){ return "1bbe0ea9e2df05297b8428716718f7d2"; };

  };

}
#endif
