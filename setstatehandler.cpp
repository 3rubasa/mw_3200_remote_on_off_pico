
#include "setstatehandler.h"
#include "include/picojson.h"


SetStateHandler::SetStateHandler(std::shared_ptr<IState> state) :
    m_state(state)
{}

bool SetStateHandler::ProcessRequest(const std::string& body) {
    printf("SetStateHandler called with param: %s", body.c_str());

    picojson::value v_root;
    std::string err = picojson::parse(v_root, body);
    if (! err.empty()) {
        printf("Failed to request body\n");
        return false;
    }

    if (!v_root.is<picojson::object>()) {
        printf("Response body is not a correct json\n");
        return false;
    }

    if (!v_root.contains("state")) {
        printf("Value 'state' not found in json\n");
        return false;
    }

    picojson::value v_state = v_root.get("state");
    std::string newStateStr = v_state.to_str();

    if (newStateStr == "on") {
        m_state->SetState(true);
    } else if (newStateStr == "off") {
        m_state->SetState(false);
    } else {
        printf("invalid state value specified: %s", newStateStr.c_str());
        return false;
    }

    return true;
}