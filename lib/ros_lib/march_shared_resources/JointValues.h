#ifndef _ROS_march_shared_resources_JointValues_h
#define _ROS_march_shared_resources_JointValues_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "control_msgs/FollowJointTrajectoryFeedback.h"

namespace march_shared_resources
{

  class JointValues : public ros::Msg
  {
    public:
      typedef control_msgs::FollowJointTrajectoryFeedback _controller_output_type;
      _controller_output_type controller_output;
      uint32_t velocities_length;
      typedef double _velocities_type;
      _velocities_type st_velocities;
      _velocities_type * velocities;
      uint32_t accelerations_length;
      typedef double _accelerations_type;
      _accelerations_type st_accelerations;
      _accelerations_type * accelerations;
      uint32_t jerks_length;
      typedef double _jerks_type;
      _jerks_type st_jerks;
      _jerks_type * jerks;

    JointValues():
      controller_output(),
      velocities_length(0), velocities(NULL),
      accelerations_length(0), accelerations(NULL),
      jerks_length(0), jerks(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->controller_output.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++){
      union {
        double real;
        uint64_t base;
      } u_velocitiesi;
      u_velocitiesi.real = this->velocities[i];
      *(outbuffer + offset + 0) = (u_velocitiesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocitiesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocitiesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocitiesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocitiesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocitiesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocitiesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocitiesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocities[i]);
      }
      *(outbuffer + offset + 0) = (this->accelerations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++){
      union {
        double real;
        uint64_t base;
      } u_accelerationsi;
      u_accelerationsi.real = this->accelerations[i];
      *(outbuffer + offset + 0) = (u_accelerationsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerationsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelerationsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelerationsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_accelerationsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_accelerationsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_accelerationsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_accelerationsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->accelerations[i]);
      }
      *(outbuffer + offset + 0) = (this->jerks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jerks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jerks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jerks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jerks_length);
      for( uint32_t i = 0; i < jerks_length; i++){
      union {
        double real;
        uint64_t base;
      } u_jerksi;
      u_jerksi.real = this->jerks[i];
      *(outbuffer + offset + 0) = (u_jerksi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jerksi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jerksi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jerksi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_jerksi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_jerksi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_jerksi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_jerksi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->jerks[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->controller_output.deserialize(inbuffer + offset);
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocities_length);
      if(velocities_lengthT > velocities_length)
        this->velocities = (double*)realloc(this->velocities, velocities_lengthT * sizeof(double));
      velocities_length = velocities_lengthT;
      for( uint32_t i = 0; i < velocities_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_velocities;
      u_st_velocities.base = 0;
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_velocities = u_st_velocities.real;
      offset += sizeof(this->st_velocities);
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(double));
      }
      uint32_t accelerations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accelerations_length);
      if(accelerations_lengthT > accelerations_length)
        this->accelerations = (double*)realloc(this->accelerations, accelerations_lengthT * sizeof(double));
      accelerations_length = accelerations_lengthT;
      for( uint32_t i = 0; i < accelerations_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_accelerations;
      u_st_accelerations.base = 0;
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_accelerations = u_st_accelerations.real;
      offset += sizeof(this->st_accelerations);
        memcpy( &(this->accelerations[i]), &(this->st_accelerations), sizeof(double));
      }
      uint32_t jerks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jerks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jerks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jerks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jerks_length);
      if(jerks_lengthT > jerks_length)
        this->jerks = (double*)realloc(this->jerks, jerks_lengthT * sizeof(double));
      jerks_length = jerks_lengthT;
      for( uint32_t i = 0; i < jerks_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_jerks;
      u_st_jerks.base = 0;
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_jerks.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_jerks = u_st_jerks.real;
      offset += sizeof(this->st_jerks);
        memcpy( &(this->jerks[i]), &(this->st_jerks), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/JointValues"; };
    const char * getMD5(){ return "8c2d87ce75da8d6f89c63a524cb72481"; };

  };

}
#endif
