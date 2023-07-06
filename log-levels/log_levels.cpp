#include <string>

namespace log_line {
    std::string message(std::string m) {
        return m.substr(m.find(':') + 2);
    }

    std::string log_level(std::string m) {
        int start = m.find("[") + 1;
        int end = m.find("]");
        return m.substr(start, end-start);
    }

    std::string reformat(std::string m) {
        return log_line::message(m) + " (" + log_line::log_level(m) + ")";
    }
}
