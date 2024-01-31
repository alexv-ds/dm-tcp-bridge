#pragma once
#include <thread>
#include <atomic>
#include <uvw.hpp>
#include <dm-tcp-bridge/Bridge.hpp>

namespace dm_bridge {

  class BridgeImpl final : public Bridge {
  public:
    explicit BridgeImpl(Options& opts);
    ~BridgeImpl() override;
  private:

    std::shared_ptr<uvw::loop> loop;
    std::atomic_bool invalid_state = false;

    //thread safe for libuv thread
    void on_listen_tcp_handle_error(const uvw::error_event&, uvw::tcp_handle&) noexcept;
    void on_listen_tcp_handle_close(const uvw::close_event&, uvw::tcp_handle&) noexcept;
    void on_listen_tcp_handle_end(const uvw::end_event&, uvw::tcp_handle&) noexcept;
    void on_listen_tcp_handle_listen(const uvw::listen_event&, uvw::tcp_handle&) noexcept;
    void on_listen_tcp_handle_shutdown(const uvw::shutdown_event&, uvw::tcp_handle&) noexcept;


    void on_listen_tcp_handle_end(const uvw::end_event&, uvw::tcp_handle&) noexcept;
    void on_listen_tcp_handle_end(const uvw::end_event&, uvw::tcp_handle&) noexcept;
    void on_listen_tcp_handle_end(const uvw::end_event&, uvw::tcp_handle&) noexcept;
  };

} // dm_bridge

