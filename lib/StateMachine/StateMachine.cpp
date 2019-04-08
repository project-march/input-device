#include "StateMachine.h"
#include "SD_sector_addresses.h"

// Constructor
StateMachine::StateMachine()
{
    this->currentState = State::ScrollSlopeUp;

    // Fill scroll states
    this->scrollStates.push_back(State::ScrollSofa);
    this->scrollStates.push_back(State::ScrollCups);
    this->scrollStates.push_back(State::ScrollSlopeUp);
    this->scrollStates.push_back(State::ScrollStairsUp);
    this->scrollStates.push_back(State::ScrollSit);

    this->currentScrollState = this->scrollStates.begin();
}

// Updates the current state based on the button inputs
void StateMachine::updateState(String joystickState, String joystickPress, String rockerState, String triggerPress){
    switch (this->currentState)
    {
        case State::ScrollSofa:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState();
            break;
        case State::ScrollCups:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState();
            break;
        case State::ScrollSlopeUp:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState();
            break;
        case State::ScrollStairsUp:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState();
            break;
        case State::ScrollSit:
            // first check if go outside scroll mode, else update scroll state
            this->updateScrollState();
            break;
        case State::Walk:
            if(joystickPress == "PUSH"){
                this->currentState = State::WalkSelected;
            }
        case State::WalkSelected:
            if(triggerPress == "PUSH"){
                this->currentState = State::WalkActivated;
            }
            break;
        case State::WalkActivated:
            if(triggerPress == "PUSH"){
                this->currentState = this->currentScrollState;
            }
            break;
        default:
            break;
    }
}

void StateMachine::updateScrollState(String joystickState){
    if (joystickState == "UP"){
        this->currentState = State::Walk;
    }
    else if(joystickState == "LEFT"){
        this->currentScrollState--;
        this->currentState = this->currentScrollState;
    }
    else if(joystickState == "RIGHT"){
        this->currentScrollState++;
        this->currentState = this->currentScrollState;
    }
}

// Return the SD addresses of the image that should be drawn in the current state
int * StateMachine::getScreenImage(){
    static int currentSdAddresses[2];
    switch (this->currentState)
    {
        case State::ScrollSofa:
            currentSdAddresses = {Sofa_Hi, Sofa_Lo};
            break;
        case State::ScrollCups:
            currentSdAddresses = {Cups_Hi, Cups_Lo};
            break;
        case State::ScrollSlopeUp:
            currentSdAddresses = {SlopeUp_Hi, SlopeUp_Lo};
            break;
        case State::ScrollStairsUp:
            currentSdAddresses = {StairUp_Hi, StairUp_Lo};
            break;
        case State::ScrollSit:
            currentSdAddresses = {Sit_Hi, Sit_Lo};
            break;
        case State::Walk:
            currentSdAddresses = {Walk_Hi, Walk_Lo};
            break;
        case State::WalkSelected:
            currentSdAddresses = {WalkS_Hi, WalkS_Lo};
            break;
        case State::WalkActivated:
            currentSdAddresses = {WalkA_Hi, WalkA_Lo};
        default:
            currentSdAddresses = {BStepS_Hi, BStepS_Lo};
            break;
    }
    return currentSdAddresses;
}