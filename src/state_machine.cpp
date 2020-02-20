#include "state_machine.h"
#include "sd_sector_addresses.h"

#include <list>

void StateMachine::construct()
{
  // Walk menu
  State& walk = this->createState(WALK); //?? of createGaitState
  State& single_step = this->createState(SINGLE_STEP_4); 
  // moet hier boven aan een single step? 

  // Obstacle menu
  State& obstacles = this->createState(OBSTACLE_MENU);
  // Obstacle menu 2
  //State& obstacles = this->createState(OBSTACLE2_MENU);

  // Start menu normal
  // na opstarten TURNED_ON
  State& stand_up = this->createGaitState(STAND_UP, STAND_UP_SELECTED, STAND_UP_ACTIVATED, "gait_stand", &obstacles);
  State& home_sit_start =
      this->createGaitState(HOME_SIT, HOME_SIT_SELECTED, HOME_SIT_ACTIVATED, "home_sit", &stand_up);
  State& turn_off_start = this->createState(TURN_OFF);

  // start menu - 2
  //State& stand_up = this->createGaitState(STAND2_UP, STAND2_UP_SELECTED, STAND_UP_ACTIVATED, "gait_stand", &obstacles);
 // State& home_sit_start =
   //   this->createGaitState(HOME_SIT2, HOME_SIT2_SELECTED, HOME_SIT2_ACTIVATED, "home_sit", &stand_up);
  //State& turn_off_start = this->createState(TURN2_OFF);

  // Sub-menus
  this->constructObstacleMenu(&obstacles, &walk, &single_step, &obstacles);
  this->constructWalkMenu(&walk, &obstacles, &obstacles);        // eerste obstacles naar walk
  this->constructStepMenu(&single_step, &obstacles, &obstacles);

  // Menu transitions
  home_sit_start.withLeft(&turn_off_start).withRight(&stand_up).shortcutPushTo(&walk).shortcutDoublePushTo(&single_step);
  stand_up.withLeft(&home_sit_start).withRight(&obstacles).shortcutPushTo(&walk).shortcutDoublePushTo(&single_step);
  obstacles.withLeft(&stand_up).shortcutPushTo(&walk).shortcutDoublePushTo(&single_step);


  walk.backTo(&obstacles).shortcutPushTo(&obstacles).shortcutDoublePushTo(&single_step);
  single_step.backTo(&obstacles).shortcutDoublePushTo(&obstacles).shortcutPushTo(&walk);  

  // Set start state
  this->current_state_ = &home_sit_start;
}


void StateMachine::constructWalkMenu(State* from, State* prev_gait, State* obstacles)
{
  State& walk_escape =
      this->createGaitState(WALK_4, WALK_4_SELECTED, WALK_4_ACTIVATED, "gait_walk", prev_gait);
  State& home_stand_walk =
      this->createGaitState(HOMESTAND_4_WALKMENU, HOMESTAND_4_WALKMENU_SELECTED, HOMESTAND_4_WALKMENU_ACTIVATED, "gait_home_stand", prev_gait);
  State& sit_walk =
      this->createGaitState(SIT_4_WALKMENU, SIT_4_WALKMENU_SELECTED, SIT_4_WALKMENU_ACTIVATED, "gait_sit", prev_gait);
  State& home = this->createState(HOME_WAlKMENU);  // hoe fixen dat je nu naar start menu gaat?

  walk_escape.backTo(from).withRight(&home_stand_walk);
  home_stand_walk.backTo(from).withLeft(&walk_escape).withRight(&sit_walk);
  sit_walk.backTo(from).withLeft(&home_stand_walk).withRight(&home);
  home.backTo(from).withLeft(&sit_walk).withSelect(obstacles);

  from->withSelect(&walk_escape);
}

// void StateMachine::constructWalkSizeMenu(State* from, State* prev_gait)
// {// moet met rocker
//   State& walk_small =
//       this->createGaitState(WALK_SMALL, WALK_SELECTED, WALK_ACTIVATED, "gait_walk_small", prev_gait);
//   State& walk_normal =
//       this->createGaitState(WALK_MEDIUM, WALK_SELECTED, WALK_ACTIVATED, "gait_walk_normal", prev_gait);
//   State& walk_large =
//       this->createGaitState(WALK_LARGE, WALK_SELECTED, WALK_ACTIVATED, "gait_walk_large", prev_gait);

//   walk_small.backTo(from);
//   walk_normal.backTo(from).withLeft(&walk_small);
//   walk_large.backTo(from).withLeft(&walk_normal).withRight(&walk_small);

//   from->withSelect(&walk_normal);
// }

void StateMachine::constructStepMenu(State* from, State* prev_gait, State* obstacles)
{
  State& single_step =
      this->createGaitState(SINGLE_STEP_4, SINGLE_STEP_4_SELECTED, SINGLE_STEP_4_ACTIVATED, "gait_walk", prev_gait);
  State& home_stand_ss =
      this->createGaitState(HOMESTAND_4_SSMENU, HOMESTAND_4_SSMENU_SELECTED, HOMESTAND_4_SSMENU_ACTIVATED, "gait_home_stand", prev_gait);
  State& sit_ss =
      this->createGaitState(SIT_4_SSMENU, SIT_4_SSMENU_SELECTED, SIT_4_SSMENU_ACTIVATED, "gait_sit", prev_gait);
  State& home = this->createState(HOME_WAlKMENU);

  single_step.backTo(from).withRight(&home_stand_ss);
  home_stand_ss.backTo(from).withLeft(&single_step).withRight(&sit_ss);
  sit_ss.backTo(from).withLeft(&home_stand_ss).withRight(&home);
  home.backTo(from).withLeft(&home_stand_ss).withSelect(obstacles);

  from->withSelect(&single_step); 
}

// void StateMachine::constructStepSizeMenu(State* from, State* prev_gait)
// { //ook met rocker?
//   State& single_step_small = this->createGaitState(STEP_SMALL, SINGLE_STEP_SELECTED,
//                                                    SINGLE_STEP_ACTIVATED, "gait_single_step_normal", prev_gait);    // prev_gait?
//   State& single_step_normal = this->createGaitState(STEP_MEDIUM, SINGLE_STEP_SELECTED,
//                                                     SINGLE_STEP_ACTIVATED, "gait_single_step_normal", prev_gait);
//   State& single_step_large = this->createGaitState(STEP_LARGE, SINGLE_STEP_SELECTED,
//                                                     SINGLE_STEP_ACTIVATED, "gait_single_step_normal", prev_gait);

//   single_step_small.backTo(from).withRight(&single_step_normal);
//   single_step_normal.backTo(from).withRight(&single_step_large);
//   single_step_large.backTo(from).withRight(&single_step_small);

//   from->withSelect(&single_step_normal); // nog veranderen in rocker
// }

void StateMachine::constructObstacleMenu(State* from, State* walk, State* single_step, State* obstacles)
{
  State& sofa = this->createState(SOFA);
  State& slalom = this->createState(SLALOM);
  State& rough_terrain = this->createState(ROUGH_TERRAIN);
  State& stairs = this->createState(STAIRS);
  State& tilted_path = this->createState(TILTED_PATH);
  State& slope = this->createState(SLOPE);

  this->constructSofaMenu(&sofa, &slalom, walk, single_step); // overal walk als next gait?
  this->constructSlalomMenu(&slalom, &rough_terrain, walk, single_step);
  this->constructRough_TerrainMenu(&rough_terrain, &stairs, walk, single_step);
  this->constructStairsMenu(&stairs, &tilted_path, walk, single_step);
  this->constructTilted_PathMenu(&tilted_path, &slope, walk, single_step);
  this->constructSlopeMenu(&slope, obstacles, walk, single_step);

  sofa.backTo(from).withRight(&slalom).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  slalom.backTo(from).withRight(&rough_terrain).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  rough_terrain.backTo(from).withRight(&stairs).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  stairs.backTo(from).withRight(&tilted_path).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  tilted_path.backTo(from).withRight(&slope).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  slope.backTo(from).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  

  from->withSelect(&sofa);
}

void StateMachine::constructSofaMenu(State* from, State* next_gait, State* walk, State* single_step)
{
  State& sofa_standup =
      this->createGaitState(SOFA_STANDUP, SOFA_STANDUP_SELECTED, SOFA_STANDUP_ACTIVATED, "gait_sofa_stand", next_gait);
  State& sofa_sit =
      this->createGaitState(SOFA_SIT, SOFA_SIT_SELECTED, SOFA_SIT_ACTIVATED, "gait_sofa_sit", &sofa_standup);

  sofa_sit.backTo(from).withRight(&sofa_standup).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  sofa_standup.backTo(&sofa_sit).withRight(&sofa_sit).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  from->withSelect(&sofa_sit); 
  // hoe automatisch walk hierna krijgen?//
}

void StateMachine::constructSlalomMenu(State* from, State* next_gait, State* walk, State* single_step)
{
  State& slalom_walk =
      this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_gait);
  
  slalom_walk.backTo(from).withRight(walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  
  from->withSelect(&slalom_walk);
}

void StateMachine::constructRough_TerrainMenu(State* from, State* next_gait, State* walk, State* single_step)
{
  State& high_step_rt =
      this->createGaitState(HIGHSTEP_RT, HIGHSTEP_RT_SELECTED, HIGHSTEP_RT_ACTIVATED, "gait_high_step", next_gait);  // de gait namen checken //
  State& small_step_rt =
      this->createGaitState(SMALLSTEP_RT, SMALLSTEP_RT_SELECTED, SMALLSTEP_RT_ACTIVATED, "gait_small_step", next_gait);
  State& middle_steps_rt =
      this->createGaitState(MIDDLESTEP_RT, MIDDLESTEP_RT_SELECTED, MIDDLESTEP_RT_ACTIVATED, "gait_middle_steps", next_gait);    
  State& high_step_rt_second =
      this->createGaitState(HIGHSTEP_RT_second, HIGHSTEP_RT_SELECTED, HIGHSTEP_RT_ACTIVATED, "gait_high_step", next_gait);
  State& small_step_rt_second =
      this->createGaitState(SMALLSTEP_RT_second, SMALLSTEP_RT_SELECTED, SMALLSTEP_RT_ACTIVATED, "gait_small_step", next_gait);

  high_step_rt.backTo(from).withRight(&small_step_rt).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  small_step_rt.backTo(&high_step_rt).withRight(&middle_steps_rt).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  middle_steps_rt.backTo(&small_step_rt).withRight(&high_step_rt_second).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  high_step_rt_second.backTo(&middle_steps_rt).withRight(&small_step_rt_second).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  small_step_rt_second.backTo(&high_step_rt_second).withRight(walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);

  
  from->withSelect(&high_step_rt);
}

void StateMachine::constructStairsMenu(State* from, State* next_gait, State* walk, State* single_step)
{
  State& stairs_down =
      this->createGaitState(STAIRS_DOWN, STAIRS_DOWN_SELECTED, STAIRS_DOWN_ACTIVATED, "gait_stairs_down", next_gait);
  State& stairs_walk =
      this->createGaitState(WALK_STAIRS, WALK_STAIRS_SELECTED, WALK_STAIRS_ACTIVATED, "gait_walk", next_gait);
  State& stairs_up =
      this->createGaitState(STAIRS_UP, STAIRS_UP_SELECTED, STAIRS_UP_ACTIVATED, "gait_stairs_up", walk);

  stairs_up.backTo(from).withRight(&stairs_walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  stairs_walk.backTo(&stairs_up).withRight(&stairs_down).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  stairs_down.backTo(&stairs_walk).withRight(walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  
  from->withSelect(&stairs_up);
}

void StateMachine::constructTilted_PathMenu(State* from, State* next_gait, State* walk, State* single_step)
{
  State& tilted_path_up =
      this->createGaitState(TILTED_PATH_UP, TILTED_PATH_UP_SELECTED, TILTED_PATH_UP_ACTIVATED, "gait_tilted_path_up", next_gait);
  State& tilted_path_walk =
      this->createGaitState(WALK_TILTED_PATH, WALK_TILTED_PATH_SELECTED, WALK_TILTED_PATH_ACTIVATED, "gait_tilted_path_walk", next_gait);
  State& tilted_path_down =
      this->createGaitState(TILTED_PATH_DOWN, TILTED_PATH_DOWN_SELECTED, TILTED_PATH_DOWN_ACTIVATED, "gait_tilted_path_down", walk);

  tilted_path_up.backTo(from).withRight(&tilted_path_walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  
  tilted_path_walk.backTo(&tilted_path_up).withRight(&tilted_path_down).shortcutPushTo(walk).shortcutDoublePushTo(single_step);

  tilted_path_down.backTo(&tilted_path_walk).withRight(walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  
  from->withSelect(&tilted_path_up);
}

void StateMachine::constructSlopeMenu(State* from, State* next_gait, State* walk, State* single_step)
{
  State& slope_down =
      this->createGaitState(SLOPE_DOWN, SLOPE_DOWN_SELECTED, SLOPE_DOWN_ACTIVATED, "gait_slope_down", next_gait); //
  State& slope_walk =
      this->createGaitState(WALK_SLOPE, WALK_SLOPE_SELECTED, WALK_SLOPE_ACTIVATED, "gait_walk", &slope_down);
  State& slope_up =
      this->createGaitState(SLOPE_UP, SLOPE_UP_SELECTED, SLOPE_UP_ACTIVATED, "gait_slope_up", &slope_walk);



  slope_up.backTo(from).withRight(&slope_walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  
  slope_walk.backTo(&slope_up).withRight(&slope_down).shortcutPushTo(walk).shortcutDoublePushTo(single_step);

  slope_down.backTo(&slope_walk).withRight(walk).shortcutPushTo(walk).shortcutDoublePushTo(single_step);
  
  from->withSelect(&slope_up);
}

std::string StateMachine::getCurrentGaitName() const
{
  if (this->hasState())
  {
    return this->current_state_->getGaitName();
  }
  return std::string();
}

SectorAddress StateMachine::getCurrentImage() const
{
  if (this->hasState())
  {
    return this->current_state_->getImage();
  }
  return SectorAddress{ 0, 0 };
}

size_t StateMachine::size() const
{
  return this->states_.size();
}

bool StateMachine::left()
{
  return this->hasState() && this->setCurrentState(this->current_state_->left());
}

bool StateMachine::right()
{
  return this->hasState() && this->setCurrentState(this->current_state_->right());
}

bool StateMachine::shortcutPush()
{
  return this->hasState() && this->setCurrentState(this->current_state_->shortcutPush());
}

bool StateMachine::shortcutDoublePush()
{
  return this->hasState() && this->setCurrentState(this->current_state_->shortcutDoublePush());
}

bool StateMachine::back()
{
  return this->hasState() && this->setCurrentState(this->current_state_->back());
}

bool StateMachine::select()
{
  return this->hasState() && this->setCurrentState(this->current_state_->select());
}

bool StateMachine::activate()
{
  return this->hasState() && this->setCurrentState(this->current_state_->activate());
}

bool StateMachine::hasState() const
{
  return this->current_state_ != nullptr;
}

bool StateMachine::setCurrentState(const State* new_state)
{
  bool has_changed = this->current_state_ != new_state;
  this->current_state_ = new_state;
  return has_changed;
}

State& StateMachine::createState(const SectorAddress address, const std::string& gait_name)
{
  this->states_.emplace_back(address, gait_name);
  return this->states_.back();
}

State& StateMachine::createGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                                     const SectorAddress addr_activated, const std::string& gait_name,
                                     const State* result)
{
  State& normal = this->createState(addr);
  State& selected = this->createState(addr_selected);
  State& activated = this->createState(addr_activated, gait_name);

  normal.withSelect(&selected);
  selected.withActivate(&activated);
  activated.withActivate(result == nullptr ? &normal : result);

  return normal;
}
