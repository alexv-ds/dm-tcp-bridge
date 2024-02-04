#pragma once
#include <nlohmann/json.hpp>

namespace dm_bridge {

  class IRequest {
  public:
    using json = nlohmann::json;

    virtual const std::string& id() const noexcept = 0;
    virtual const json& args() const noexcept = 0;
    virtual const std::string& method() const noexcept = 0;
    virtual void make_response(json&& args = json()) = 0;
    virtual void make_error(std::string&& what) = 0;
  };

} // dm_bridge