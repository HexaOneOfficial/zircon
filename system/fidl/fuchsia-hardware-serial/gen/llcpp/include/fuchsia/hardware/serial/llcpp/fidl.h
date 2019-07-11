// WARNING: This file is machine generated by fidlgen.

#pragma once

#include <lib/fidl/internal.h>
#include <lib/fidl/cpp/vector_view.h>
#include <lib/fidl/cpp/string_view.h>
#include <lib/fidl/llcpp/array.h>
#include <lib/fidl/llcpp/coding.h>
#include <lib/fidl/llcpp/traits.h>
#include <lib/fidl/llcpp/transaction.h>
#include <lib/fit/function.h>
#include <lib/zx/channel.h>
#include <zircon/fidl.h>

namespace llcpp {

namespace fuchsia {
namespace hardware {
namespace serial {

enum class StopWidth : uint8_t {
  BITS_1 = 1u,
  BITS_2 = 2u,
};


enum class Parity : uint8_t {
  NONE = 1u,
  EVEN = 2u,
  ODD = 3u,
};


enum class FlowControl : uint8_t {
  NONE = 1u,
  CTS_RTS = 2u,
};


enum class Class : uint8_t {
  GENERIC = 1u,
  BLUETOOTH_HCI = 2u,
  CONSOLE = 3u,
};


enum class CharacterWidth : uint8_t {
  BITS_5 = 1u,
  BITS_6 = 2u,
  BITS_7 = 3u,
  BITS_8 = 4u,
};


struct Config;
class Device;



struct Config {
  static constexpr const fidl_type_t* Type = nullptr;
  static constexpr uint32_t MaxNumHandles = 0;
  static constexpr uint32_t PrimarySize = 8;
  [[maybe_unused]]
  static constexpr uint32_t MaxOutOfLine = 0;

  CharacterWidth character_width{};

  StopWidth stop_width{};

  Parity parity{};

  FlowControl control_flow{};

  uint32_t baud_rate{};
};

extern "C" const fidl_type_t fuchsia_hardware_serial_DeviceGetClassResponseTable;
extern "C" const fidl_type_t fuchsia_hardware_serial_DeviceSetConfigResponseTable;

class Device final {
 public:

  struct GetClassResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    Class device_class;

    static constexpr const fidl_type_t* Type = &fuchsia_hardware_serial_DeviceGetClassResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
  };
  using GetClassRequest = ::fidl::AnyZeroArgMessage;

  struct SetConfigResponse final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    int32_t s;

    static constexpr const fidl_type_t* Type = &fuchsia_hardware_serial_DeviceSetConfigResponseTable;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
  };
  struct SetConfigRequest final {
    FIDL_ALIGNDECL
    fidl_message_header_t _hdr;
    Config config;

    static constexpr const fidl_type_t* Type = nullptr;
    static constexpr uint32_t MaxNumHandles = 0;
    static constexpr uint32_t PrimarySize = 24;
    static constexpr uint32_t MaxOutOfLine = 0;
    using ResponseType = SetConfigResponse;
  };


  class SyncClient final {
   public:
    SyncClient(::zx::channel channel) : channel_(std::move(channel)) {}

    SyncClient(SyncClient&&) = default;

    SyncClient& operator=(SyncClient&&) = default;

    ~SyncClient() {}

    const ::zx::channel& channel() const { return channel_; }

    ::zx::channel* mutable_channel() { return &channel_; }

    // Lookup what type of serial device this is.
    zx_status_t GetClass(Class* out_device_class);

    // Lookup what type of serial device this is.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    // The lifetime of handles in the response, unless moved, is tied to the returned RAII object.
    ::fidl::DecodeResult<GetClassResponse> GetClass(::fidl::BytePart _response_buffer, Class* out_device_class);

    // Lookup what type of serial device this is.
    // Messages are encoded and decoded in-place.
    ::fidl::DecodeResult<GetClassResponse> GetClass(::fidl::BytePart response_buffer);

    // Set the configuration of this serial device.
    zx_status_t SetConfig(Config config, int32_t* out_s);

    // Set the configuration of this serial device.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    // The lifetime of handles in the response, unless moved, is tied to the returned RAII object.
    ::fidl::DecodeResult<SetConfigResponse> SetConfig(::fidl::BytePart _request_buffer, Config config, ::fidl::BytePart _response_buffer, int32_t* out_s);

    // Set the configuration of this serial device.
    // Messages are encoded and decoded in-place.
    ::fidl::DecodeResult<SetConfigResponse> SetConfig(::fidl::DecodedMessage<SetConfigRequest> params, ::fidl::BytePart response_buffer);

   private:
    ::zx::channel channel_;
  };

  // Methods to make a sync FIDL call directly on an unowned channel, avoiding setting up a client.
  class Call final {
   public:

    // Lookup what type of serial device this is.
    static zx_status_t GetClass(zx::unowned_channel _client_end, Class* out_device_class);

    // Lookup what type of serial device this is.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    // The lifetime of handles in the response, unless moved, is tied to the returned RAII object.
    static ::fidl::DecodeResult<GetClassResponse> GetClass(zx::unowned_channel _client_end, ::fidl::BytePart _response_buffer, Class* out_device_class);

    // Lookup what type of serial device this is.
    // Messages are encoded and decoded in-place.
    static ::fidl::DecodeResult<GetClassResponse> GetClass(zx::unowned_channel _client_end, ::fidl::BytePart response_buffer);

    // Set the configuration of this serial device.
    static zx_status_t SetConfig(zx::unowned_channel _client_end, Config config, int32_t* out_s);

    // Set the configuration of this serial device.
    // Caller provides the backing storage for FIDL message via request and response buffers.
    // The lifetime of handles in the response, unless moved, is tied to the returned RAII object.
    static ::fidl::DecodeResult<SetConfigResponse> SetConfig(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, Config config, ::fidl::BytePart _response_buffer, int32_t* out_s);

    // Set the configuration of this serial device.
    // Messages are encoded and decoded in-place.
    static ::fidl::DecodeResult<SetConfigResponse> SetConfig(zx::unowned_channel _client_end, ::fidl::DecodedMessage<SetConfigRequest> params, ::fidl::BytePart response_buffer);

  };

  // Pure-virtual interface to be implemented by a server.
  class Interface {
   public:
    Interface() = default;
    virtual ~Interface() = default;
    using _Outer = Device;
    using _Base = ::fidl::CompleterBase;

    class GetClassCompleterBase : public _Base {
     public:
      void Reply(Class device_class);
      void Reply(::fidl::BytePart _buffer, Class device_class);
      void Reply(::fidl::DecodedMessage<GetClassResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using GetClassCompleter = ::fidl::Completer<GetClassCompleterBase>;

    virtual void GetClass(GetClassCompleter::Sync _completer) = 0;

    class SetConfigCompleterBase : public _Base {
     public:
      void Reply(int32_t s);
      void Reply(::fidl::BytePart _buffer, int32_t s);
      void Reply(::fidl::DecodedMessage<SetConfigResponse> params);

     protected:
      using ::fidl::CompleterBase::CompleterBase;
    };

    using SetConfigCompleter = ::fidl::Completer<SetConfigCompleterBase>;

    virtual void SetConfig(Config config, SetConfigCompleter::Sync _completer) = 0;

  };

  // Attempts to dispatch the incoming message to a handler function in the server implementation.
  // If there is no matching handler, it returns false, leaving the message and transaction intact.
  // In all other cases, it consumes the message and returns true.
  // It is possible to chain multiple TryDispatch functions in this manner.
  static bool TryDispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn);

  // Dispatches the incoming message to one of the handlers functions in the interface.
  // If there is no matching handler, it closes all the handles in |msg| and closes the channel with
  // a |ZX_ERR_NOT_SUPPORTED| epitaph, before returning false. The message should then be discarded.
  static bool Dispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn);

  // Same as |Dispatch|, but takes a |void*| instead of |Interface*|. Only used with |fidl::Bind|
  // to reduce template expansion.
  // Do not call this method manually. Use |Dispatch| instead.
  static bool TypeErasedDispatch(void* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
    return Dispatch(static_cast<Interface*>(impl), msg, txn);
  }

};

}  // namespace serial
}  // namespace hardware
}  // namespace fuchsia
}  // namespace llcpp

namespace fidl {

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::serial::Config> : public std::true_type {};
static_assert(std::is_standard_layout_v<::llcpp::fuchsia::hardware::serial::Config>);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Config, character_width) == 0);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Config, stop_width) == 1);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Config, parity) == 2);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Config, control_flow) == 3);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Config, baud_rate) == 4);
static_assert(sizeof(::llcpp::fuchsia::hardware::serial::Config) == ::llcpp::fuchsia::hardware::serial::Config::PrimarySize);

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::serial::Device::GetClassResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::serial::Device::GetClassResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::serial::Device::GetClassResponse)
    == ::llcpp::fuchsia::hardware::serial::Device::GetClassResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Device::GetClassResponse, device_class) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::serial::Device::SetConfigRequest> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::serial::Device::SetConfigRequest> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::serial::Device::SetConfigRequest)
    == ::llcpp::fuchsia::hardware::serial::Device::SetConfigRequest::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Device::SetConfigRequest, config) == 16);

template <>
struct IsFidlType<::llcpp::fuchsia::hardware::serial::Device::SetConfigResponse> : public std::true_type {};
template <>
struct IsFidlMessage<::llcpp::fuchsia::hardware::serial::Device::SetConfigResponse> : public std::true_type {};
static_assert(sizeof(::llcpp::fuchsia::hardware::serial::Device::SetConfigResponse)
    == ::llcpp::fuchsia::hardware::serial::Device::SetConfigResponse::PrimarySize);
static_assert(offsetof(::llcpp::fuchsia::hardware::serial::Device::SetConfigResponse, s) == 16);

}  // namespace fidl
