#ifndef _ROS_march_shared_resources_PressureSole_h
#define _ROS_march_shared_resources_PressureSole_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"

namespace march_shared_resources
{

  class PressureSole : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ros::Time _pressure_soles_time_type;
      _pressure_soles_time_type pressure_soles_time;
      typedef float _total_force_left_type;
      _total_force_left_type total_force_left;
      typedef float _total_force_right_type;
      _total_force_right_type total_force_right;
      uint32_t pressure_left_length;
      typedef float _pressure_left_type;
      _pressure_left_type st_pressure_left;
      _pressure_left_type * pressure_left;
      uint32_t pressure_right_length;
      typedef float _pressure_right_type;
      _pressure_right_type st_pressure_right;
      _pressure_right_type * pressure_right;
      uint32_t cop_left_length;
      typedef float _cop_left_type;
      _cop_left_type st_cop_left;
      _cop_left_type * cop_left;
      uint32_t cop_right_length;
      typedef float _cop_right_type;
      _cop_right_type st_cop_right;
      _cop_right_type * cop_right;

    PressureSole():
      header(),
      pressure_soles_time(),
      total_force_left(0),
      total_force_right(0),
      pressure_left_length(0), pressure_left(NULL),
      pressure_right_length(0), pressure_right(NULL),
      cop_left_length(0), cop_left(NULL),
      cop_right_length(0), cop_right(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pressure_soles_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure_soles_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pressure_soles_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pressure_soles_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_soles_time.sec);
      *(outbuffer + offset + 0) = (this->pressure_soles_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure_soles_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pressure_soles_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pressure_soles_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_soles_time.nsec);
      union {
        float real;
        uint32_t base;
      } u_total_force_left;
      u_total_force_left.real = this->total_force_left;
      *(outbuffer + offset + 0) = (u_total_force_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_force_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_force_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_force_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_force_left);
      union {
        float real;
        uint32_t base;
      } u_total_force_right;
      u_total_force_right.real = this->total_force_right;
      *(outbuffer + offset + 0) = (u_total_force_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_total_force_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_total_force_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_total_force_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->total_force_right);
      *(outbuffer + offset + 0) = (this->pressure_left_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure_left_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pressure_left_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pressure_left_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_left_length);
      for( uint32_t i = 0; i < pressure_left_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pressure_lefti;
      u_pressure_lefti.real = this->pressure_left[i];
      *(outbuffer + offset + 0) = (u_pressure_lefti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_lefti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_lefti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_lefti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_left[i]);
      }
      *(outbuffer + offset + 0) = (this->pressure_right_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure_right_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pressure_right_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pressure_right_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_right_length);
      for( uint32_t i = 0; i < pressure_right_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pressure_righti;
      u_pressure_righti.real = this->pressure_right[i];
      *(outbuffer + offset + 0) = (u_pressure_righti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure_righti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure_righti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure_righti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure_right[i]);
      }
      *(outbuffer + offset + 0) = (this->cop_left_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cop_left_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cop_left_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cop_left_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cop_left_length);
      for( uint32_t i = 0; i < cop_left_length; i++){
      union {
        float real;
        uint32_t base;
      } u_cop_lefti;
      u_cop_lefti.real = this->cop_left[i];
      *(outbuffer + offset + 0) = (u_cop_lefti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cop_lefti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cop_lefti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cop_lefti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cop_left[i]);
      }
      *(outbuffer + offset + 0) = (this->cop_right_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cop_right_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cop_right_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cop_right_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cop_right_length);
      for( uint32_t i = 0; i < cop_right_length; i++){
      union {
        float real;
        uint32_t base;
      } u_cop_righti;
      u_cop_righti.real = this->cop_right[i];
      *(outbuffer + offset + 0) = (u_cop_righti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cop_righti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cop_righti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cop_righti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cop_right[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->pressure_soles_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->pressure_soles_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pressure_soles_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pressure_soles_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pressure_soles_time.sec);
      this->pressure_soles_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->pressure_soles_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pressure_soles_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pressure_soles_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pressure_soles_time.nsec);
      union {
        float real;
        uint32_t base;
      } u_total_force_left;
      u_total_force_left.base = 0;
      u_total_force_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_force_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_force_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_force_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_force_left = u_total_force_left.real;
      offset += sizeof(this->total_force_left);
      union {
        float real;
        uint32_t base;
      } u_total_force_right;
      u_total_force_right.base = 0;
      u_total_force_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_total_force_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_total_force_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_total_force_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->total_force_right = u_total_force_right.real;
      offset += sizeof(this->total_force_right);
      uint32_t pressure_left_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pressure_left_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pressure_left_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pressure_left_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pressure_left_length);
      if(pressure_left_lengthT > pressure_left_length)
        this->pressure_left = (float*)realloc(this->pressure_left, pressure_left_lengthT * sizeof(float));
      pressure_left_length = pressure_left_lengthT;
      for( uint32_t i = 0; i < pressure_left_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pressure_left;
      u_st_pressure_left.base = 0;
      u_st_pressure_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pressure_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pressure_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pressure_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pressure_left = u_st_pressure_left.real;
      offset += sizeof(this->st_pressure_left);
        memcpy( &(this->pressure_left[i]), &(this->st_pressure_left), sizeof(float));
      }
      uint32_t pressure_right_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pressure_right_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pressure_right_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pressure_right_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pressure_right_length);
      if(pressure_right_lengthT > pressure_right_length)
        this->pressure_right = (float*)realloc(this->pressure_right, pressure_right_lengthT * sizeof(float));
      pressure_right_length = pressure_right_lengthT;
      for( uint32_t i = 0; i < pressure_right_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pressure_right;
      u_st_pressure_right.base = 0;
      u_st_pressure_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pressure_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pressure_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pressure_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pressure_right = u_st_pressure_right.real;
      offset += sizeof(this->st_pressure_right);
        memcpy( &(this->pressure_right[i]), &(this->st_pressure_right), sizeof(float));
      }
      uint32_t cop_left_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cop_left_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cop_left_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cop_left_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cop_left_length);
      if(cop_left_lengthT > cop_left_length)
        this->cop_left = (float*)realloc(this->cop_left, cop_left_lengthT * sizeof(float));
      cop_left_length = cop_left_lengthT;
      for( uint32_t i = 0; i < cop_left_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_cop_left;
      u_st_cop_left.base = 0;
      u_st_cop_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cop_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cop_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cop_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cop_left = u_st_cop_left.real;
      offset += sizeof(this->st_cop_left);
        memcpy( &(this->cop_left[i]), &(this->st_cop_left), sizeof(float));
      }
      uint32_t cop_right_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cop_right_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cop_right_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cop_right_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cop_right_length);
      if(cop_right_lengthT > cop_right_length)
        this->cop_right = (float*)realloc(this->cop_right, cop_right_lengthT * sizeof(float));
      cop_right_length = cop_right_lengthT;
      for( uint32_t i = 0; i < cop_right_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_cop_right;
      u_st_cop_right.base = 0;
      u_st_cop_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cop_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cop_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cop_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_cop_right = u_st_cop_right.real;
      offset += sizeof(this->st_cop_right);
        memcpy( &(this->cop_right[i]), &(this->st_cop_right), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/PressureSole"; };
    const char * getMD5(){ return "13b27f467193798354308188ddb84202"; };

  };

}
#endif
