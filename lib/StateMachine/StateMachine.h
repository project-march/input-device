#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <Arduino.h>
#include <vector>

enum class State {  ScrollSofa,
                    ScrollCups,
                    ScrollSlopeUp,
                    ScrollStairsUp,
                    ScrollSit,
                    Walk,
                    WalkSelected,
                    WalkActivated};


class StateMachine
{
private:
    State currentState;
    void updateScrollState(String joystickState);
    std::vector<State> scrollStates;
    std::vector<State>::iterator currentScrollState;
    
public:
    StateMachine();
    void updateState(String joystickState = "NEUTRAL", String joystickPress = "NEUTRAL", String rockerState = "NEUTRAL", String triggerPress = "NEUTRAL");
    int * getScreenImage();
};




#endif // STATEMACHINE_H