#pragma once

#include <string>
#include <vector>

// A helper function to simulate alert collection
extern std::vector<std::string> messages;
extern std::function<void(const std::string&)> alertfunc;
