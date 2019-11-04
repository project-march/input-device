#ifndef _ROS_march_shared_resources_Subgait_h
#define _ROS_march_shared_resources_Subgait_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "march_shared_resources/Setpoint.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "ros/duration.h"
#include "march_shared_resources/Sound.h"

namespace march_shared_resources
{

  class Subgait : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _version_type;
      _version_type version;
      typedef const char* _description_type;
      _description_type description;
      uint32_t setpoints_length;
      typedef march_shared_resources::Setpoint _setpoints_type;
      _setpoints_type st_setpoints;
      _setpoints_type * setpoints;
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef ros::Duration _duration_type;
      _duration_type duration;
      uint32_t sounds_length;
      typedef march_shared_resources::Sound _sounds_type;
      _sounds_type st_sounds;
      _sounds_type * sounds;

    Subgait():
      name(""),
      version(""),
      description(""),
      setpoints_length(0), setpoints(NULL),
      trajectory(),
      duration(),
      sounds_length(0), sounds(NULL)
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
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      *(outbuffer + offset + 0) = (this->setpoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->setpoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->setpoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->setpoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpoints_length);
      for( uint32_t i = 0; i < setpoints_length; i++){
      offset += this->setpoints[i].serialize(outbuffer + offset);
      }
      offset += this->trajectory.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
      *(outbuffer + offset + 0) = (this->sounds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sounds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sounds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sounds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sounds_length);
      for( uint32_t i = 0; i < sounds_length; i++){
      offset += this->sounds[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t setpoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      setpoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      setpoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      setpoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->setpoints_length);
      if(setpoints_lengthT > setpoints_length)
        this->setpoints = (march_shared_resources::Setpoint*)realloc(this->setpoints, setpoints_lengthT * sizeof(march_shared_resources::Setpoint));
      setpoints_length = setpoints_lengthT;
      for( uint32_t i = 0; i < setpoints_length; i++){
      offset += this->st_setpoints.deserialize(inbuffer + offset);
        memcpy( &(this->setpoints[i]), &(this->st_setpoints), sizeof(march_shared_resources::Setpoint));
      }
      offset += this->trajectory.deserialize(inbuffer + offset);
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
      uint32_t sounds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sounds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sounds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sounds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sounds_length);
      if(sounds_lengthT > sounds_length)
        this->sounds = (march_shared_resources::Sound*)realloc(this->sounds, sounds_lengthT * sizeof(march_shared_resources::Sound));
      sounds_length = sounds_lengthT;
      for( uint32_t i = 0; i < sounds_length; i++){
      offset += this->st_sounds.deserialize(inbuffer + offset);
        memcpy( &(this->sounds[i]), &(this->st_sounds), sizeof(march_shared_resources::Sound));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/Subgait"; };
    const char * getMD5(){ return "56dd95f06d51574a3fc7a0eac6b1b780"; };

  };

}
#endif
