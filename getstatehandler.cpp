
#include "getstatehandler.h"

GetStateHandler::GetStateHandler(std::shared_ptr<IState> state) :
    m_state(state) 
{

}

std::string GetStateHandler::ProcessRequest() {
    if (m_state->GetState()) {
        return "{\"state\": \"on\"}";
    } else {
        return "{\"state\": \"off\"}";
    }
}