#include "state_machine.h"
#include "sd_sector_addresses.h"

#include <list>

void StateMachine::construct()
{
  // Obstacle menu
  State& obstacles = this->createState(OBSTACLE2_MENU);

  // Start menu
  State& stand_up = this->createGaitState(STAND2_UP, STAND2_UP_SELECTED, STAND2_UP_ACTIVATED, "gait_stand", &obstacles);
  State& home_sit_start = this->createGaitState(HOME_SIT2, HOME_SIT2_SELECTED, HOME_SIT2_ACTIVATED, "home_sit", &stand_up);
  State& turn_off_start = this->createState(TURN2_OFF);

  // Sub-menus
  this->constructObstacleMenu(&obstacles);

  // Determine the state after the last added state before the walk and single step menu are added
  // This is used in constructing the walk and single step menu
  state_iterator list_end = states_.end();

  this->constructWalkMenu(list_end, &obstacles);
  this->constructStepMenu(list_end, &obstacles);

  // Menu transitions
  home_sit_start.withLeft(&turn_off_start).withRight(&stand_up);
  stand_up.withLeft(&home_sit_start).withRight(&obstacles);
  obstacles.withLeft(&stand_up);

  // Set start state
  this->current_state_ = &home_sit_start;
}

void StateMachine::constructWalkMenu(state_iterator list_end, State* obstacles)
{
  State& walk_escape = this->createEscapeGaitState(WALK_4, WALK_4_SELECTED, WALK_4_ACTIVATED, "gait_walk", nullptr);
  State& home_stand_walk = this->createEscapeGaitState(HOMESTAND_4_WALKMENU, HOMESTAND_4_WALKMENU_SELECTED,
                                                       HOMESTAND_4_WALKMENU_ACTIVATED, "gait_home_stand", nullptr);
  State& sit_walk = this->createEscapeGaitState(SIT_4_WALKMENU, SIT_4_WALKMENU_SELECTED, SIT_4_WALKMENU_ACTIVATED,
                                                "gait_sit", nullptr);
  State& home = this->createEscapeState(HOME_WALKMENU);

  walk_escape.withRight(&home_stand_walk);
  home_stand_walk.withRight(&sit_walk);
  sit_walk.withRight(&home);
  home.selectTo(obstacles);

  state_iterator states_iterator;
  for (states_iterator = this->states_.begin(); states_iterator != list_end; states_iterator++)
  {
    if (states_iterator->getGaitName().empty())
    {
      states_iterator->shortcutDoublePushTo(&walk_escape);
    }
  }
}

void StateMachine::constructStepMenu(state_iterator list_end, State* obstacles)
{
  State& single_step =
      this->createEscapeGaitState(SINGLE_STEP_4, SINGLE_STEP_4_SELECTED, SINGLE_STEP_4_ACTIVATED, "gait_walk", nullptr);
  State& home_stand_ss = this->createEscapeGaitState(HOMESTAND_4_SSMENU, HOMESTAND_4_SSMENU_SELECTED,
                                                     HOMESTAND_4_SSMENU_ACTIVATED, "gait_home_stand", nullptr);
  State& sit_ss =
      this->createEscapeGaitState(SIT_4_SSMENU, SIT_4_SSMENU_SELECTED, SIT_4_SSMENU_ACTIVATED, "gait_sit", nullptr);
  State& home = this->createEscapeState(HOME_WALKMENU);

  single_step.withRight(&home_stand_ss);
  home_stand_ss.withRight(&sit_ss);
  sit_ss.withRight(&home);
  home.selectTo(obstacles);

  state_iterator states_iterator;
  for (states_iterator = states_.begin(); states_iterator != list_end; states_iterator++)
  {
    if (states_iterator->getGaitName().empty())
    {
      states_iterator->shortcutPushTo(&single_step);
    }
  }
}

void StateMachine::constructObstacleMenu(State* from)
{
  State& sofa = this->createState(SOFA2);
  State& slalom = this->createState(SLALOM2);
  State& rough_terrain = this->createState(ROUGH_TERRAIN2);
  State& stairs = this->createState(STAIRS2);
  State& tilted_path = this->createState(TILTED_PATH2);
  State& slope = this->createState(SLOPE2);

  this->constructSofaMenu(&sofa, &sofa_slalom_walk);
  this->constructSlalomMenu(&slalom, &slalom_roughterrain_walk);
  this->constructRoughTerrainMenu(&rough_terrain, &roughterrain_stairs_walk);
  this->constructStairsMenu(&stairs, &stairs_tiltedpath_walk);
  this->constructTiltedPathMenu(&tilted_path, &tiltedpath_slope_walk);
  this->constructSlopeMenu(&slope, from);

  sofa.backTo(from).withRight(&slalom);
  slalom.backTo(from).withRight(&rough_terrain);
  rough_terrain.backTo(from).withRight(&stairs);
  stairs.backTo(from).withRight(&tilted_path);
  tilted_path.backTo(from).withRight(&slope);
  slope.backTo(from).withRight(&sofa);

  from->withSelect(&slalom);
}

void StateMachine::constructSofaMenu(State* from, State* next_obstacle)
{
  State& walk_in_between = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_obstacle);
  State& sofa_standup = this->createGaitState(SOFA_STANDUP, SOFA_STANDUP_SELECTED, SOFA_STANDUP_ACTIVATED,
                                              "gait_sofa_stand", &walk_in_between);
  State& sofa_sit =
      this->createGaitState(SOFA_SIT, SOFA_SIT_SELECTED, SOFA_SIT_ACTIVATED, "gait_sofa_sit", &sofa_standup);

  sofa_sit.backTo(from).withRight(&sofa_standup);
  sofa_standup.backTo(from).withRight(&sofa_sit);
  walk_in_between.backTo(from);
  from->withSelect(&sofa_sit);
}

void StateMachine::constructSlalomMenu(State* from, State* next_obstacle)
{
  State& walk_in_between = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_obstacle);
  State& slalom_walk = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", &walk_in_between);

  slalom_walk.backTo(from);
  walk_in_between.backTo(from);

  from->withSelect(&slalom_walk);
}

void StateMachine::constructRoughTerrainMenu(State* from, State* next_obstacle)
{
  State& walk_in_between = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_obstacle);
  State& small_step_rt_second = this->createGaitState(SMALLSTEP_RT_second, SMALLSTEP_RT_SELECTED,
                                                      SMALLSTEP_RT_ACTIVATED, "gait_small_step", &walk_in_between);
  State& high_step_rt_second = this->createGaitState(HIGHSTEP_RT_second, HIGHSTEP_RT_SELECTED, HIGHSTEP_RT_ACTIVATED,
                                                     "gait_high_step", &small_step_rt_second);
  State& middle_step3_rt = this->createGaitState(MIDDLESTEP3_RT, MIDDLESTEP3_RT_SELECTED, MIDDLESTEP3_RT_ACTIVATED,
                                                 "gait_third_middle_steps", &high_step_rt_second);
  State& middle_step2_rt = this->createGaitState(MIDDLESTEP2_RT, MIDDLESTEP2_RT_SELECTED, MIDDLESTEP2_RT_ACTIVATED,
                                                 "gait_second_middle_steps", &middle_step3_rt);
  State& middle_step1_rt = this->createGaitState(MIDDLESTEP1_RT, MIDDLESTEP1_RT_SELECTED, MIDDLESTEP1_RT_ACTIVATED,
                                                 "gait_first_middle_steps", &middle_step2_rt);
  State& small_step_rt = this->createGaitState(SMALLSTEP_RT, SMALLSTEP_RT_SELECTED, SMALLSTEP_RT_ACTIVATED,
                                               "gait_small_step", &middle_step1_rt);
  State& high_step_rt =
      this->createGaitState(HIGHSTEP_RT, HIGHSTEP_RT_SELECTED, HIGHSTEP_RT_ACTIVATED, "gait_high_step", &small_step_rt);

  high_step_rt.backTo(from).withRight(&small_step_rt);
  small_step_rt.backTo(from).withRight(&middle_step1_rt);
  middle_step1_rt.backTo(from).withRight(&middle_step2_rt);
  middle_step2_rt.backTo(from).withRight(&middle_step3_rt);
  middle_step3_rt.backTo(from).withRight(&high_step_rt_second);
  high_step_rt_second.backTo(from).withRight(&small_step_rt_second);
  small_step_rt_second.backTo(from).withRight(&high_step_rt);
  walk_in_between.backTo(from);

  from->withSelect(&high_step_rt);
}

void StateMachine::constructStairsMenu(State* from, State* next_obstacle)
{
  State& walk_in_between = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_obstacle);
  State& stairs_down = this->createGaitState(STAIRS_DOWN, STAIRS_DOWN_SELECTED, STAIRS_DOWN_ACTIVATED,
                                             "gait_stairs_down", &walk_in_between);
  State& stairs_walk =
      this->createGaitState(WALK_STAIRS, WALK_STAIRS_SELECTED, WALK_STAIRS_ACTIVATED, "gait_walk", &stairs_down);
  State& stairs_up =
      this->createGaitState(STAIRS_UP, STAIRS_UP_SELECTED, STAIRS_UP_ACTIVATED, "gait_stairs_up", &stairs_walk);

  stairs_up.backTo(from).withRight(&stairs_walk);
  stairs_walk.backTo(from).withRight(&stairs_down);
  stairs_down.backTo(from).withRight(&stairs_up);
  walk_in_between.backTo(from);

  from->withSelect(&stairs_up);
}

void StateMachine::constructTiltedPathMenu(State* from, State* next_obstacle)
{
  State& walk_in_between = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_obstacle);

  State& tilted_pathL = this->createState(TILTED_PATH_LINKS);
  State& tilted_pathR = this->createState(TILTED_PATH_RECHTS);

  State& tilted_pathL_down = this->createGaitState(TILTED_PATH_DOWN, TILTED_PATH_DOWN_SELECTED,
                                                   TILTED_PATH_DOWN_ACTIVATED, "gait_tilted_path_down", &walk_in_between);
  State& tilted_pathL_walk =
      this->createGaitState(WALK_TILTED_PATH, WALK_TILTED_PATH_SELECTED, WALK_TILTED_PATH_ACTIVATED,
                            "gait_tilted_path_left_walk", &tilted_pathL_down);
  State& tilted_pathL_up = this->createGaitState(TILTED_PATH_UP, TILTED_PATH_UP_SELECTED, TILTED_PATH_UP_ACTIVATED,
                                                 "gait_tilted_path_left_up", &tilted_pathL_walk);

  State& tilted_pathR_down = this->createGaitState(TILTED_PATH_DOWN, TILTED_PATH_DOWN_SELECTED,
                                                   TILTED_PATH_DOWN_ACTIVATED, "gait_tilted_path_down", &walk_in_between);
  State& tilted_pathR_walk =
      this->createGaitState(WALK_TILTED_PATH, WALK_TILTED_PATH_SELECTED, WALK_TILTED_PATH_ACTIVATED,
                            "gait_tilted_path_walk", &tilted_pathR_down);
  State& tilted_pathR_up = this->createGaitState(TILTED_PATH_UP, TILTED_PATH_UP_SELECTED, TILTED_PATH_UP_ACTIVATED,
                                                 "gait_tilted_path_up", &tilted_pathR_walk);

  tilted_pathL.withSelect(&tilted_pathL_up).backTo(from).withRight(&tilted_pathR);
  tilted_pathR.withSelect(&tilted_pathR_up).backTo(from).withRight(&tilted_pathL);

  tilted_pathL_up.backTo(&tilted_pathL).withRight(&tilted_pathL_walk);
  tilted_pathL_walk.backTo(&tilted_pathL).withRight(&tilted_pathL_down);
  tilted_pathL_down.backTo(&tilted_pathL).withRight(&tilted_pathL_up);

  tilted_pathR_up.backTo(&tilted_pathR).withRight(&tilted_pathR_walk);
  tilted_pathR_walk.backTo(&tilted_pathR).withRight(&tilted_pathR_down);
  tilted_pathR_down.backTo(&tilted_pathR).withRight(&tilted_pathR_up);

  walk_in_between.backTo(from);

  from->withSelect(&tilted_pathL);
}

void StateMachine::constructSlopeMenu(State* from, State* next_obstacle)
{
  State& walk_in_between = this->createGaitState(WALK_2O, WALK_2O_SELECTED, WALK_2O_ACTIVATED, "gait_walk", next_obstacle);
  State& slope_down =
      this->createGaitState(SLOPE_DOWN, SLOPE_DOWN_SELECTED, SLOPE_DOWN_ACTIVATED, "gait_slope_down", &walk_in_between);
  State& slope_walk =
      this->createGaitState(WALK_SLOPE, WALK_SLOPE_SELECTED, WALK_SLOPE_ACTIVATED, "gait_walk", &slope_down);
  State& slope_up =
      this->createGaitState(SLOPE_UP, SLOPE_UP_SELECTED, SLOPE_UP_ACTIVATED, "gait_slope_up", &slope_walk);

  slope_up.backTo(from).withRight(&slope_walk);
  slope_walk.backTo(from).withRight(&slope_down);
  slope_down.backTo(from).withRight(&slope_up);
  walk_in_between.backTo(from);

  from->withSelect(&slope_up);
}

void StateMachine::setEscapeStatesBackTo(const State* previous_state)
{
  for (State& escape_state : this->escape_states_)
  {
    if ((escape_state.getGaitName()).empty())
    {
      escape_state.backTo(previous_state);
    }
    else
    {
      escape_state.withActivate(previous_state);
    }
  }
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
  if (!this->in_escape_menu_)
  {
    this->previous_state_ = this->current_state_;
    this->setEscapeStatesBackTo(this->previous_state_);
    this->in_escape_menu_ = true;
  }

  return this->hasState() && this->setCurrentState(this->current_state_->shortcutPush());
}

bool StateMachine::shortcutDoublePush()
{
  if (!this->in_escape_menu_)
  {
    this->previous_state_ = this->current_state_;
    this->setEscapeStatesBackTo(this->previous_state_);
    this->in_escape_menu_ = true;
  }
  return this->hasState() && this->setCurrentState(this->current_state_->shortcutDoublePush());
}

bool StateMachine::back()
{
  if (this->in_escape_menu_ && this->current_state_->back() == this->previous_state_)
  {
    this->in_escape_menu_ = false;
  }
  return this->hasState() && this->setCurrentState(this->current_state_->back());
}

bool StateMachine::select()
{
  if (this->in_escape_menu_ && this->current_state_->select() == this->current_state_->select()->activate())
  {
    this->in_escape_menu_ = false;
  }
  return this->hasState() && this->setCurrentState(this->current_state_->select());
}

bool StateMachine::activate()
{
  if (this->in_escape_menu_ && this->current_state_->activate()->activate() == this->previous_state_)
  {
    this->in_escape_menu_ = false;
  }
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

State& StateMachine::createEscapeState(const SectorAddress address, const std::string& gait_name)
{
  this->escape_states_.emplace_back(address, gait_name);
  return escape_states_.back();
}

State& StateMachine::createEscapeGaitState(const SectorAddress addr, const SectorAddress addr_selected,
                                           const SectorAddress addr_activated, const std::string& gait_name,
                                           const State* result)
{
  State& normal = this->createEscapeState(addr);
  State& selected = this->createState(addr_selected);
  State& activated = this->createEscapeState(addr_activated, gait_name);

  normal.withSelect(&selected);
  selected.withActivate(&activated);
  activated.withActivate(result == nullptr ? &normal : result);

  return normal;
}
