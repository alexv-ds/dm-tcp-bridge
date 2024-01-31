#include <functional>
#include <spdlog/spdlog.h>
#include "BridgeImpl.hpp"

namespace dm_bridge {
  static void close_all_handles(uvw::loop& loop) noexcept {
    loop.walk([](auto& handle) {
      handle.close();
    });
  }

  BridgeImpl::BridgeImpl(Bridge::Options& opts) : loop(uvw::loop::create()) {
    auto tcp_handle = this->loop->resource<uvw::tcp_handle>();

    tcp_handle->on<uvw::error_event>([this](uvw::error_event& err, uvw::tcp_handle& handle) {
      this->on_listen_tcp_handle_error(err, handle);
    });

    tcp_handle->on<uvw::close_event>([this](const auto& event, uvw::tcp_handle& handle) {
      this->on_listen_tcp_handle_close(event, handle);
    });


  }

  BridgeImpl::~BridgeImpl() {
    close_all_handles(*this->loop);
  }

  void BridgeImpl::on_listen_tcp_handle_error(const uvw::error_event& err, uvw::tcp_handle& handle) noexcept {
    this->invalid_state = true;
    close_all_handles(handle.parent());

    try {
      SPDLOG_CRITICAL("[TCP LISTEN HANDLE] Error event - {} - {}", err.name(), err.what());
    } catch (const std::exception&) {
      // Do nothing, logger error, we can't report this.
      // The stability of the BYOND server is more important than abort() due to the fact that we will
      // throw an exception in С
    }
  }

  void BridgeImpl::on_listen_tcp_handle_close(const uvw::close_event&, uvw::tcp_handle& handle) noexcept {
    this->invalid_state = true;
    close_all_handles(handle.parent());
    try {
      SPDLOG_INFO("[TCP LISTEN HANDLE] Close handle");
    } catch (const std::exception& e) {
      // Do nothing, logger error, we can't report this.
      // The stability of the BYOND server is more important than abort() due to the fact that we will
      // throw an exception in С
    }
  }

} // dm_bridge