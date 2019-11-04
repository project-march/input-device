#ifndef _ROS_march_shared_resources_PowerDistributionBoardState_h
#define _ROS_march_shared_resources_PowerDistributionBoardState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "march_shared_resources/LowVoltageNet.h"
#include "march_shared_resources/HighVoltageNet.h"

namespace march_shared_resources
{

  class PowerDistributionBoardState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _high_voltage_enabled_type;
      _high_voltage_enabled_type high_voltage_enabled;
      typedef float _power_distribution_board_current_type;
      _power_distribution_board_current_type power_distribution_board_current;
      typedef float _high_voltage_net_current_type;
      _high_voltage_net_current_type high_voltage_net_current;
      typedef bool _master_shutdown_requested_type;
      _master_shutdown_requested_type master_shutdown_requested;
      uint32_t low_voltage_nets_length;
      typedef march_shared_resources::LowVoltageNet _low_voltage_nets_type;
      _low_voltage_nets_type st_low_voltage_nets;
      _low_voltage_nets_type * low_voltage_nets;
      uint32_t high_voltage_nets_length;
      typedef march_shared_resources::HighVoltageNet _high_voltage_nets_type;
      _high_voltage_nets_type st_high_voltage_nets;
      _high_voltage_nets_type * high_voltage_nets;

    PowerDistributionBoardState():
      header(),
      high_voltage_enabled(0),
      power_distribution_board_current(0),
      high_voltage_net_current(0),
      master_shutdown_requested(0),
      low_voltage_nets_length(0), low_voltage_nets(NULL),
      high_voltage_nets_length(0), high_voltage_nets(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_high_voltage_enabled;
      u_high_voltage_enabled.real = this->high_voltage_enabled;
      *(outbuffer + offset + 0) = (u_high_voltage_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->high_voltage_enabled);
      union {
        float real;
        uint32_t base;
      } u_power_distribution_board_current;
      u_power_distribution_board_current.real = this->power_distribution_board_current;
      *(outbuffer + offset + 0) = (u_power_distribution_board_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_power_distribution_board_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_power_distribution_board_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_power_distribution_board_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->power_distribution_board_current);
      union {
        float real;
        uint32_t base;
      } u_high_voltage_net_current;
      u_high_voltage_net_current.real = this->high_voltage_net_current;
      *(outbuffer + offset + 0) = (u_high_voltage_net_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_high_voltage_net_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_high_voltage_net_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_high_voltage_net_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->high_voltage_net_current);
      union {
        bool real;
        uint8_t base;
      } u_master_shutdown_requested;
      u_master_shutdown_requested.real = this->master_shutdown_requested;
      *(outbuffer + offset + 0) = (u_master_shutdown_requested.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->master_shutdown_requested);
      *(outbuffer + offset + 0) = (this->low_voltage_nets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->low_voltage_nets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->low_voltage_nets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->low_voltage_nets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->low_voltage_nets_length);
      for( uint32_t i = 0; i < low_voltage_nets_length; i++){
      offset += this->low_voltage_nets[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->high_voltage_nets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->high_voltage_nets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->high_voltage_nets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->high_voltage_nets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->high_voltage_nets_length);
      for( uint32_t i = 0; i < high_voltage_nets_length; i++){
      offset += this->high_voltage_nets[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_high_voltage_enabled;
      u_high_voltage_enabled.base = 0;
      u_high_voltage_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->high_voltage_enabled = u_high_voltage_enabled.real;
      offset += sizeof(this->high_voltage_enabled);
      union {
        float real;
        uint32_t base;
      } u_power_distribution_board_current;
      u_power_distribution_board_current.base = 0;
      u_power_distribution_board_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_power_distribution_board_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_power_distribution_board_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_power_distribution_board_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->power_distribution_board_current = u_power_distribution_board_current.real;
      offset += sizeof(this->power_distribution_board_current);
      union {
        float real;
        uint32_t base;
      } u_high_voltage_net_current;
      u_high_voltage_net_current.base = 0;
      u_high_voltage_net_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_high_voltage_net_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_high_voltage_net_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_high_voltage_net_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->high_voltage_net_current = u_high_voltage_net_current.real;
      offset += sizeof(this->high_voltage_net_current);
      union {
        bool real;
        uint8_t base;
      } u_master_shutdown_requested;
      u_master_shutdown_requested.base = 0;
      u_master_shutdown_requested.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->master_shutdown_requested = u_master_shutdown_requested.real;
      offset += sizeof(this->master_shutdown_requested);
      uint32_t low_voltage_nets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      low_voltage_nets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      low_voltage_nets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      low_voltage_nets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->low_voltage_nets_length);
      if(low_voltage_nets_lengthT > low_voltage_nets_length)
        this->low_voltage_nets = (march_shared_resources::LowVoltageNet*)realloc(this->low_voltage_nets, low_voltage_nets_lengthT * sizeof(march_shared_resources::LowVoltageNet));
      low_voltage_nets_length = low_voltage_nets_lengthT;
      for( uint32_t i = 0; i < low_voltage_nets_length; i++){
      offset += this->st_low_voltage_nets.deserialize(inbuffer + offset);
        memcpy( &(this->low_voltage_nets[i]), &(this->st_low_voltage_nets), sizeof(march_shared_resources::LowVoltageNet));
      }
      uint32_t high_voltage_nets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      high_voltage_nets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      high_voltage_nets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      high_voltage_nets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->high_voltage_nets_length);
      if(high_voltage_nets_lengthT > high_voltage_nets_length)
        this->high_voltage_nets = (march_shared_resources::HighVoltageNet*)realloc(this->high_voltage_nets, high_voltage_nets_lengthT * sizeof(march_shared_resources::HighVoltageNet));
      high_voltage_nets_length = high_voltage_nets_lengthT;
      for( uint32_t i = 0; i < high_voltage_nets_length; i++){
      offset += this->st_high_voltage_nets.deserialize(inbuffer + offset);
        memcpy( &(this->high_voltage_nets[i]), &(this->st_high_voltage_nets), sizeof(march_shared_resources::HighVoltageNet));
      }
     return offset;
    }

    const char * getType(){ return "march_shared_resources/PowerDistributionBoardState"; };
    const char * getMD5(){ return "2ff720814f62ef92954d191a316aeaf3"; };

  };

}
#endif
