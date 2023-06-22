#include "exceptions.h"

namespace Exceptions {

std::string fetchScope(Error error) {
    std::string scope_name = typeid(decltype(error)).name();
    size_t pos = scope_name.find("::");
    if (pos != std::string::npos) {
        return scope_name.substr(0, pos);
    }
    return "Unknown Scope";
}

void perr(Error error) {
    std::cerr << "[" << fetchScope(error) << "] " << error.message << std::endl;
}

}