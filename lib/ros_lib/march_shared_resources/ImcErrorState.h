#ifndef _ROS_march_shared_resources_ImcErrorState_h
#define _ROS_march_shared_resources_ImcErrorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace march_shared_resources
{

  class ImcErrorState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t joint_names_length;
      typedef char* _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t status_word_length;
      typedef char* _status_word_type;
      _status_word_type st_status_word;
      _status_word_type * status_word;
      uint32_t detailed_error_length;
      typedef char* _detailed_error_type;
      _detailed_error_type st_detailed_error;
      _detailed_error_type * detailed_error;
      uint32_t motion_error_length;
      typedef char* _motion_error_type;
      _motion_error_type st_motion_error;
      _motion_error_type * motion_error;
      uint32_t state_length;
      typedef char* _state_type;
      _state_type st_state;
      _state_type * state;
      uint32_t detailed_error_description_length;
      typedef char* _detailed_error_description_type;
      _detailed_error_description_type st_detailed_error_description;
      _detailed_error_description_type * detailed_error_description;
      uint32_t motion_error_description_length;
      typedef char* _motion_error_description_type;
      _motion_error_description_type st_motion_error_description;
      _motion_error_description_type * motion_error_description;
      uint32_t motor_current_length;
      typedef float _motor_current_type;
      _motor_current_type st_motor_current;
      _motor_current_type * motor_current;
      uint32_t motor_voltage_length;
      typedef float _motor_voltage_type;
      _motor_voltage_type st_motor_voltage;
      _motor_voltage_type * motor_voltage;
      uint32_t incremental_encoder_value_length;
      typedef float _incremental_encoder_value_type;
      _incremental_encoder_value_type st_incremental_encoder_value;
      _incremental_encoder_value_type * incremental_encoder_value;

    ImcErrorState():
      header(),
      joint_names_length(0), joint_names(NULL),
      status_word_length(0), status_word(NULL),
      detailed_error_length(0), detailed_error(NULL),
      motion_error_length(0), motion_error(NULL),
      state_length(0), state(NULL),
      detailed_error_description_length(0), detailed_error_description(NULL),
      motion_error_description_length(0), motion_error_description(NULL),
      motor_current_length(0), motor_current(NULL),
      motor_voltage_length(0), motor_voltage(NULL),
      incremental_encoder_value_length(0), incremental_encoder_value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->status_word_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_word_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_word_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_word_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_word_length);
      for( uint32_t i = 0; i < status_word_length; i++){
      uint32_t length_status_wordi = strlen(this->status_word[i]);
      varToArr(outbuffer + offset, length_status_wordi);
      offset += 4;
      memcpy(outbuffer + offset, this->status_word[i], length_status_wordi);
      offset += length_status_wordi;
      }
      *(outbuffer + offset + 0) = (this->detailed_error_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detailed_error_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detailed_error_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detailed_error_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detailed_error_length);
      for( uint32_t i = 0; i < detailed_error_length; i++){
      uint32_t length_detailed_errori = strlen(this->detailed_error[i]);
      varToArr(outbuffer + offset, length_detailed_errori);
      offset += 4;
      memcpy(outbuffer + offset, this->detailed_error[i], length_detailed_errori);
      offset += length_detailed_errori;
      }
      *(outbuffer + offset + 0) = (this->motion_error_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motion_error_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motion_error_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motion_error_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motion_error_length);
      for( uint32_t i = 0; i < motion_error_length; i++){
      uint32_t length_motion_errori = strlen(this->motion_error[i]);
      varToArr(outbuffer + offset, length_motion_errori);
      offset += 4;
      memcpy(outbuffer + offset, this->motion_error[i], length_motion_errori);
      offset += length_motion_errori;
      }
      *(outbuffer + offset + 0) = (this->state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_length);
      for( uint32_t i = 0; i < state_length; i++){
      uint32_t length_statei = strlen(this->state[i]);
      varToArr(outbuffer + offset, length_statei);
      offset += 4;
      memcpy(outbuffer + offset, this->state[i], length_statei);
      offset += length_statei;
      }
      *(outbuffer + offset + 0) = (this->detailed_error_description_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detailed_error_description_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detailed_error_description_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detailed_error_description_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detailed_error_description_length);
      for( uint32_t i = 0; i < detailed_error_description_length; i++){
      uint32_t length_detailed_error_descriptioni = strlen(this->detailed_error_description[i]);
      varToArr(outbuffer + offset, length_detailed_error_descriptioni);
      offset += 4;
      memcpy(outbuffer + offset, this->detailed_error_description[i], length_detailed_error_descriptioni);
      offset += length_detailed_error_descriptioni;
      }
      *(outbuffer + offset + 0) = (this->motion_error_description_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motion_error_description_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motion_error_description_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motion_error_description_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motion_error_description_length);
      for( uint32_t i = 0; i < motion_error_description_length; i++){
      uint32_t length_motion_error_descriptioni = strlen(this->motion_error_description[i]);
      varToArr(outbuffer + offset, length_motion_error_descriptioni);
      offset += 4;
      memcpy(outbuffer + offset, this->motion_error_description[i], length_motion_error_descriptioni);
      offset += length_motion_error_descriptioni;
      }
      *(outbuffer + offset + 0) = (this->motor_current_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_current_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_current_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_current_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_current_length);
      for( uint32_t i = 0; i < motor_current_length; i++){
      union {
        float real;
        uint32_t base;
      } u_motor_currenti;
      u_motor_currenti.real = this->motor_current[i];
      *(outbuffer + offset + 0) = (u_motor_currenti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_currenti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_currenti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_currenti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_current[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_voltage_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_voltage_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_voltage_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_voltage_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_voltage_length);
      for( uint32_t i = 0; i < motor_voltage_length; i++){
      union {
        float real;
        uint32_t base;
      } u_motor_voltagei;
      u_motor_voltagei.real = this->motor_voltage[i];
      *(outbuffer + offset + 0) = (u_motor_voltagei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_voltagei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_voltagei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_voltagei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_voltage[i]);
      }
      *(outbuffer + offset + 0) = (this->incremental_encoder_value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->incremental_encoder_value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->incremental_encoder_value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->incremental_encoder_value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->incremental_encoder_value_length);
      for( uint32_t i = 0; i < incremental_encoder_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_incremental_encoder_valuei;
      u_incremental_encoder_valuei.real = this->incremental_encoder_value[i];
      *(outbuffer + offset + 0) = (u_incremental_encoder_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_incremental_encoder_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_incremental_encoder_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_incremental_encoder_valuei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->incremental_encoder_value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      arrToVar(length_st_joint_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint32_t status_word_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_word_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_word_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_word_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_word_length);
      if(status_word_lengthT > status_word_length)
        this->status_word = (char**)realloc(this->status_word, status_word_lengthT * sizeof(char*));
      status_word_length = status_word_lengthT;
      for( uint32_t i = 0; i < status_word_length; i++){
      uint32_t length_st_status_word;
      arrToVar(length_st_status_word, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_status_word; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_status_word-1]=0;
      this->st_status_word = (char *)(inbuffer + offset-1);
      offset += length_st_status_word;
        memcpy( &(this->status_word[i]), &(this->st_status_word), sizeof(char*));
      }
      uint32_t detailed_error_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detailed_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detailed_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detailed_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detailed_error_length);
      if(detailed_error_lengthT > detailed_error_length)
        this->detailed_error = (char**)realloc(this->detailed_error, detailed_error_lengthT * sizeof(char*));
      detailed_error_length = detailed_error_lengthT;
      for( uint32_t i = 0; i < detailed_error_length; i++){
      uint32_t length_st_detailed_error;
      arrToVar(length_st_detailed_error, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_detailed_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_detailed_error-1]=0;
      this->st_detailed_error = (char *)(inbuffer + offset-1);
      offset += length_st_detailed_error;
        memcpy( &(this->detailed_error[i]), &(this->st_detailed_error), sizeof(char*));
      }
      uint32_t motion_error_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motion_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motion_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motion_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motion_error_length);
      if(motion_error_lengthT > motion_error_length)
        this->motion_error = (char**)realloc(this->motion_error, motion_error_lengthT * sizeof(char*));
      motion_error_length = motion_error_lengthT;
      for( uint32_t i = 0; i < motion_error_length; i++){
      uint32_t length_st_motion_error;
      arrToVar(length_st_motion_error, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_motion_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_motion_error-1]=0;
      this->st_motion_error = (char *)(inbuffer + offset-1);
      offset += length_st_motion_error;
        memcpy( &(this->motion_error[i]), &(this->st_motion_error), sizeof(char*));
      }
      uint32_t state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->state_length);
      if(state_lengthT > state_length)
        this->state = (char**)realloc(this->state, state_lengthT * sizeof(char*));
      state_length = state_lengthT;
      for( uint32_t i = 0; i < state_length; i++){
      uint32_t length_st_state;
      arrToVar(length_st_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_state-1]=0;
      this->st_state = (char *)(inbuffer + offset-1);
      offset += length_st_state;
        memcpy( &(this->state[i]), &(this->st_state), sizeof(char*));
      }
      uint32_t detailed_error_description_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detailed_error_description_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detailed_error_description_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detailed_error_description_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detailed_error_description_length);
      if(detailed_error_description_lengthT > detailed_error_description_length)
        this->detailed_error_description = (char**)realloc(this->detailed_error_description, detailed_error_description_lengthT * sizeof(char*));
      detailed_error_description_length = detailed_error_description_lengthT;
      for( uint32_t i = 0; i < detailed_error_description_length; i++){
      uint32_t length_st_detailed_error_description;
      arrToVar(length_st_detailed_error_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_detailed_error_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_detailed_error_description-1]=0;
      this->st_detailed_error_description = (char *)(inbuffer + offset-1);
      offset += length_st_detailed_error_description;
        memcpy( &(this->detailed_error_description[i]), &(this->st_detailed_error_description), sizeof(char*));
      }
      uint32_t motion_error_description_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motion_error_description_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motion_error_description_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motion_error_description_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motion_error_description_length);
      if(motion_error_description_lengthT > motion_error_description_length)
        this->motion_error_description = (char**)realloc(this->motion_error_description, motion_error_description_lengthT * sizeof(char*));
      motion_error_description_length = motion_error_description_lengthT;
      for( uint32_t i = 0; i < motion_error_description_length; i++){
      uint32_t length_st_motion_error_description;
      arrToVar(length_st_motion_error_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_motion_error_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_motion_error_description-1]=0;
      this->st_motion_error_description = (char *)(inbuffer + offset-1);
      offset += length_st_motion_error_description;
        memcpy( &(this->motion_error_description[i]), &(this->st_motion_error_description), sizeof(char*));
      }
      uint32_t motor_current_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_current_length);
      if(motor_current_lengthT > motor_current_length)
        this->motor_current = (float*)realloc(this->motor_current, motor_current_lengthT * sizeof(float));
      motor_current_length = motor_current_lengthT;
      for( uint32_t i = 0; i < motor_current_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_motor_current;
      u_st_motor_current.base = 0;
      u_st_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_motor_current = u_st_motor_current.real;
      offset += sizeof(this->st_motor_current);
        memcpy( &(this->motor_current[i]), &(this->st_motor_current), sizeof(float));
      }
      uint32_t motor_voltage_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_voltage_length);
      if(motor_voltage_lengthT > motor_voltage_length)
        this->motor_voltage = (float*)realloc(this->motor_voltage, motor_voltage_lengthT * sizeof(float));
      motor_voltage_length = motor_voltage_lengthT;
      for( uint32_t i = 0; i < motor_voltage_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_motor_voltage;
      u_st_motor_voltage.base = 0;
      u_st_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_motor_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_motor_voltage = u_st_motor_voltage.real;
      offset += sizeof(this->st_motor_voltage);
        memcpy( &(this->motor_voltage[i]), &(this->st_motor_voltage), sizeof(float));
      }
      uint32_t incremental_encoder_value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      incremental_encoder_value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      incremental_encoder_value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      incremental_encoder_value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->incremental_encoder_value_length);
      if(incremental_encoder_value_lengthT > incremental_encoder_value_length)
        this->incremental_encoder_value = (float*)realloc(this->incremental_encoder_value, incremental_encoder_value_lengthT * sizeof(float));
      incremental_encoder_value_length = incremental_encoder_value_lengthT;
      for( uint32_t i = 0; i < incremental_encoder_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_incremental_encoder_value;
      u_st_incremental_encoder_value.base = 0;
      u_st_incremental_encoder_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_incremental_encoder_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_incremental_encoder_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_incremental_encoder_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_incremental_encoder_value = u_st_incremental_encoder_value.real;
      offset += sizeof(this->st_incremental_encoder_value);
        memcpy( &(this->incremental_encoder_value[i]), &(this->st_incremental_encoder_value), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/ImcErrorState"; };
    const char * getMD5(){ return "257334b3b47fe1b244b79e0baa52a1b9"; };

  };

}
#endif
