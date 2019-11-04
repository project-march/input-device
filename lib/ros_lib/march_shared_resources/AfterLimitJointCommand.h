#ifndef _ROS_march_shared_resources_AfterLimitJointCommand_h
#define _ROS_march_shared_resources_AfterLimitJointCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace march_shared_resources
{

  class AfterLimitJointCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t position_command_length;
      typedef double _position_command_type;
      _position_command_type st_position_command;
      _position_command_type * position_command;
      uint32_t effort_command_length;
      typedef double _effort_command_type;
      _effort_command_type st_effort_command;
      _effort_command_type * effort_command;

    AfterLimitJointCommand():
      header(),
      name_length(0), name(NULL),
      position_command_length(0), position_command(NULL),
      effort_command_length(0), effort_command(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->position_command_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_command_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_command_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_command_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_command_length);
      for( uint32_t i = 0; i < position_command_length; i++){
      union {
        double real;
        uint64_t base;
      } u_position_commandi;
      u_position_commandi.real = this->position_command[i];
      *(outbuffer + offset + 0) = (u_position_commandi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_commandi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_commandi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_commandi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position_commandi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position_commandi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position_commandi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position_commandi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position_command[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_command_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_command_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_command_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_command_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_command_length);
      for( uint32_t i = 0; i < effort_command_length; i++){
      union {
        double real;
        uint64_t base;
      } u_effort_commandi;
      u_effort_commandi.real = this->effort_command[i];
      *(outbuffer + offset + 0) = (u_effort_commandi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effort_commandi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effort_commandi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effort_commandi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_effort_commandi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_effort_commandi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_effort_commandi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_effort_commandi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->effort_command[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      arrToVar(length_st_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint32_t position_command_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_command_length);
      if(position_command_lengthT > position_command_length)
        this->position_command = (double*)realloc(this->position_command, position_command_lengthT * sizeof(double));
      position_command_length = position_command_lengthT;
      for( uint32_t i = 0; i < position_command_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_position_command;
      u_st_position_command.base = 0;
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_position_command.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_position_command = u_st_position_command.real;
      offset += sizeof(this->st_position_command);
        memcpy( &(this->position_command[i]), &(this->st_position_command), sizeof(double));
      }
      uint32_t effort_command_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_command_length);
      if(effort_command_lengthT > effort_command_length)
        this->effort_command = (double*)realloc(this->effort_command, effort_command_lengthT * sizeof(double));
      effort_command_length = effort_command_lengthT;
      for( uint32_t i = 0; i < effort_command_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_effort_command;
      u_st_effort_command.base = 0;
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_effort_command.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_effort_command = u_st_effort_command.real;
      offset += sizeof(this->st_effort_command);
        memcpy( &(this->effort_command[i]), &(this->st_effort_command), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/AfterLimitJointCommand"; };
    const char * getMD5(){ return "0955e98b7c2631fc5f6e19da963b050c"; };

  };

}
#endif
