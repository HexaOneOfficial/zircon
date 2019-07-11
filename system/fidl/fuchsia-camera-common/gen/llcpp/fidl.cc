// WARNING: This file is machine generated by fidlgen.

#include <fuchsia/camera/common/llcpp/fidl.h>
#include <memory>

namespace llcpp {

namespace fuchsia {
namespace camera {
namespace common {

namespace {

[[maybe_unused]]
constexpr uint64_t kStream_Start_Ordinal = 932812003lu << 32;
[[maybe_unused]]
constexpr uint64_t kStream_Stop_Ordinal = 9009058lu << 32;
[[maybe_unused]]
constexpr uint64_t kStream_ReleaseFrame_Ordinal = 629961612lu << 32;
extern "C" const fidl_type_t fuchsia_camera_common_StreamReleaseFrameRequestTable;
[[maybe_unused]]
constexpr uint64_t kStream_OnFrameAvailable_Ordinal = 1771204245lu << 32;

}  // namespace

zx_status_t Stream::SyncClient::Start() {
  return Stream::Call::Start(zx::unowned_channel(this->channel_));
}

zx_status_t Stream::Call::Start(zx::unowned_channel _client_end) {
  constexpr uint32_t _kWriteAllocSize = ::fidl::internal::ClampedMessageSize<StartRequest>();
  FIDL_ALIGNDECL uint8_t _write_bytes[_kWriteAllocSize] = {};
  auto& _request = *reinterpret_cast<StartRequest*>(_write_bytes);
  _request._hdr.ordinal = kStream_Start_Ordinal;
  ::fidl::BytePart _request_bytes(_write_bytes, _kWriteAllocSize, sizeof(StartRequest));
  ::fidl::DecodedMessage<StartRequest> _decoded_request(std::move(_request_bytes));
  auto _encode_request_result = ::fidl::Encode(std::move(_decoded_request));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}


zx_status_t Stream::SyncClient::Stop() {
  return Stream::Call::Stop(zx::unowned_channel(this->channel_));
}

zx_status_t Stream::Call::Stop(zx::unowned_channel _client_end) {
  constexpr uint32_t _kWriteAllocSize = ::fidl::internal::ClampedMessageSize<StopRequest>();
  FIDL_ALIGNDECL uint8_t _write_bytes[_kWriteAllocSize] = {};
  auto& _request = *reinterpret_cast<StopRequest*>(_write_bytes);
  _request._hdr.ordinal = kStream_Stop_Ordinal;
  ::fidl::BytePart _request_bytes(_write_bytes, _kWriteAllocSize, sizeof(StopRequest));
  ::fidl::DecodedMessage<StopRequest> _decoded_request(std::move(_request_bytes));
  auto _encode_request_result = ::fidl::Encode(std::move(_decoded_request));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}


zx_status_t Stream::SyncClient::ReleaseFrame(uint32_t buffer_id) {
  return Stream::Call::ReleaseFrame(zx::unowned_channel(this->channel_), std::move(buffer_id));
}

zx_status_t Stream::Call::ReleaseFrame(zx::unowned_channel _client_end, uint32_t buffer_id) {
  constexpr uint32_t _kWriteAllocSize = ::fidl::internal::ClampedMessageSize<ReleaseFrameRequest>();
  FIDL_ALIGNDECL uint8_t _write_bytes[_kWriteAllocSize] = {};
  auto& _request = *reinterpret_cast<ReleaseFrameRequest*>(_write_bytes);
  _request._hdr.ordinal = kStream_ReleaseFrame_Ordinal;
  _request.buffer_id = std::move(buffer_id);
  ::fidl::BytePart _request_bytes(_write_bytes, _kWriteAllocSize, sizeof(ReleaseFrameRequest));
  ::fidl::DecodedMessage<ReleaseFrameRequest> _decoded_request(std::move(_request_bytes));
  auto _encode_request_result = ::fidl::Encode(std::move(_decoded_request));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}

zx_status_t Stream::SyncClient::ReleaseFrame(::fidl::BytePart _request_buffer, uint32_t buffer_id) {
  return Stream::Call::ReleaseFrame(zx::unowned_channel(this->channel_), std::move(_request_buffer), std::move(buffer_id));
}

zx_status_t Stream::Call::ReleaseFrame(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, uint32_t buffer_id) {
  if (_request_buffer.capacity() < ReleaseFrameRequest::PrimarySize) {
    return ZX_ERR_BUFFER_TOO_SMALL;
  }
  auto& _request = *reinterpret_cast<ReleaseFrameRequest*>(_request_buffer.data());
  _request._hdr.ordinal = kStream_ReleaseFrame_Ordinal;
  _request.buffer_id = std::move(buffer_id);
  _request_buffer.set_actual(sizeof(ReleaseFrameRequest));
  ::fidl::DecodedMessage<ReleaseFrameRequest> _decoded_request(std::move(_request_buffer));
  auto _encode_request_result = ::fidl::Encode(std::move(_decoded_request));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}

zx_status_t Stream::SyncClient::ReleaseFrame(::fidl::DecodedMessage<ReleaseFrameRequest> params) {
  return Stream::Call::ReleaseFrame(zx::unowned_channel(this->channel_), std::move(params));
}

zx_status_t Stream::Call::ReleaseFrame(zx::unowned_channel _client_end, ::fidl::DecodedMessage<ReleaseFrameRequest> params) {
  params.message()->_hdr = {};
  params.message()->_hdr.ordinal = kStream_ReleaseFrame_Ordinal;
  auto _encode_request_result = ::fidl::Encode(std::move(params));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}

zx_status_t Stream::SyncClient::HandleEvents(Stream::EventHandlers handlers) {
  return Stream::Call::HandleEvents(zx::unowned_channel(channel_), std::move(handlers));
}

zx_status_t Stream::Call::HandleEvents(zx::unowned_channel client_end,
                                            Stream::EventHandlers handlers) {
  zx_status_t status = client_end->wait_one(ZX_CHANNEL_READABLE | ZX_CHANNEL_PEER_CLOSED,
                                            zx::time::infinite(),
                                            nullptr);
  if (status != ZX_OK) {
    return status;
  }
  constexpr uint32_t kReadAllocSize = ([]() constexpr {
    uint32_t x = 0;
    if (::fidl::internal::ClampedMessageSize<OnFrameAvailableResponse>() >= x) {
      x = ::fidl::internal::ClampedMessageSize<OnFrameAvailableResponse>();
    }
    return x;
  })();
  constexpr uint32_t kHandleAllocSize = ([]() constexpr {
    uint32_t x = 0;
    if (OnFrameAvailableResponse::MaxNumHandles >= x) {
      x = OnFrameAvailableResponse::MaxNumHandles;
    }
    if (x > ZX_CHANNEL_MAX_MSG_HANDLES) {
      x = ZX_CHANNEL_MAX_MSG_HANDLES;
    }
    return x;
  })();
  FIDL_ALIGNDECL uint8_t read_bytes[kReadAllocSize];
  zx_handle_t read_handles[kHandleAllocSize];
  uint32_t actual_bytes;
  uint32_t actual_handles;
  status = client_end->read(ZX_CHANNEL_READ_MAY_DISCARD,
                            read_bytes, read_handles,
                            kReadAllocSize, kHandleAllocSize,
                            &actual_bytes, &actual_handles);
  if (status == ZX_ERR_BUFFER_TOO_SMALL) {
    // Message size is unexpectedly larger than calculated.
    // This can only be due to a newer version of the protocol defining a new event,
    // whose size exceeds the maximum of known events in the current protocol.
    return handlers.unknown();
  }
  if (status != ZX_OK) {
    return status;
  }
  if (actual_bytes < sizeof(fidl_message_header_t)) {
    zx_handle_close_many(read_handles, actual_handles);
    return ZX_ERR_INVALID_ARGS;
  }
  auto msg = fidl_msg_t {
    .bytes = read_bytes,
    .handles = read_handles,
    .num_bytes = actual_bytes,
    .num_handles = actual_handles
  };
  fidl_message_header_t* hdr = reinterpret_cast<fidl_message_header_t*>(msg.bytes);
  switch (hdr->ordinal) {
    case kStream_OnFrameAvailable_Ordinal: {
      auto result = ::fidl::DecodeAs<OnFrameAvailableResponse>(&msg);
      if (result.status != ZX_OK) {
        return result.status;
      }
      auto message = result.message.message();
      return handlers.on_frame_available(std::move(message->frame));
    }
    default:
      zx_handle_close_many(read_handles, actual_handles);
      return handlers.unknown();
  }
}

bool Stream::TryDispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
  if (msg->num_bytes < sizeof(fidl_message_header_t)) {
    zx_handle_close_many(msg->handles, msg->num_handles);
    txn->Close(ZX_ERR_INVALID_ARGS);
    return true;
  }
  fidl_message_header_t* hdr = reinterpret_cast<fidl_message_header_t*>(msg->bytes);
  switch (hdr->ordinal) {
    case kStream_Start_Ordinal: {
      auto result = ::fidl::DecodeAs<StartRequest>(msg);
      if (result.status != ZX_OK) {
        txn->Close(ZX_ERR_INVALID_ARGS);
        return true;
      }
      impl->Start(
        Interface::StartCompleter::Sync(txn));
      return true;
    }
    case kStream_Stop_Ordinal: {
      auto result = ::fidl::DecodeAs<StopRequest>(msg);
      if (result.status != ZX_OK) {
        txn->Close(ZX_ERR_INVALID_ARGS);
        return true;
      }
      impl->Stop(
        Interface::StopCompleter::Sync(txn));
      return true;
    }
    case kStream_ReleaseFrame_Ordinal: {
      auto result = ::fidl::DecodeAs<ReleaseFrameRequest>(msg);
      if (result.status != ZX_OK) {
        txn->Close(ZX_ERR_INVALID_ARGS);
        return true;
      }
      auto message = result.message.message();
      impl->ReleaseFrame(std::move(message->buffer_id),
        Interface::ReleaseFrameCompleter::Sync(txn));
      return true;
    }
    default: {
      return false;
    }
  }
}

bool Stream::Dispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
  bool found = TryDispatch(impl, msg, txn);
  if (!found) {
    zx_handle_close_many(msg->handles, msg->num_handles);
    txn->Close(ZX_ERR_NOT_SUPPORTED);
  }
  return found;
}


zx_status_t Stream::SendOnFrameAvailableEvent(::zx::unowned_channel _chan, FrameAvailableEvent frame) {
  constexpr uint32_t _kWriteAllocSize = ::fidl::internal::ClampedMessageSize<OnFrameAvailableResponse>();
  FIDL_ALIGNDECL uint8_t _write_bytes[_kWriteAllocSize] = {};
  auto& _response = *reinterpret_cast<OnFrameAvailableResponse*>(_write_bytes);
  _response._hdr = {};
  _response._hdr.ordinal = kStream_OnFrameAvailable_Ordinal;
  _response.frame = std::move(frame);
  ::fidl::BytePart _response_bytes(_write_bytes, _kWriteAllocSize, sizeof(OnFrameAvailableResponse));
  return ::fidl::Write(zx::unowned_channel(_chan), ::fidl::DecodedMessage<OnFrameAvailableResponse>(std::move(_response_bytes)));
}

zx_status_t Stream::SendOnFrameAvailableEvent(::zx::unowned_channel _chan, ::fidl::BytePart _buffer, FrameAvailableEvent frame) {
  if (_buffer.capacity() < OnFrameAvailableResponse::PrimarySize) {
    return ZX_ERR_BUFFER_TOO_SMALL;
  }
  auto& _response = *reinterpret_cast<OnFrameAvailableResponse*>(_buffer.data());
  _response._hdr = {};
  _response._hdr.ordinal = kStream_OnFrameAvailable_Ordinal;
  _response.frame = std::move(frame);
  _buffer.set_actual(sizeof(OnFrameAvailableResponse));
  return ::fidl::Write(zx::unowned_channel(_chan), ::fidl::DecodedMessage<OnFrameAvailableResponse>(std::move(_buffer)));
}

zx_status_t Stream::SendOnFrameAvailableEvent(::zx::unowned_channel _chan, ::fidl::DecodedMessage<OnFrameAvailableResponse> params) {
  params.message()->_hdr = {};
  params.message()->_hdr.ordinal = kStream_OnFrameAvailable_Ordinal;
  return ::fidl::Write(zx::unowned_channel(_chan), std::move(params));
}


auto ::llcpp::fuchsia::camera::common::VirtualStreamConfig::which() const -> Tag {
  switch (ordinal_) {
  case Tag::kArtificialConfig:
  case Tag::kRealWorldConfig:
    return ordinal_;
  default:
    return Tag::kUnknown;
  }
}

void ::llcpp::fuchsia::camera::common::VirtualStreamConfig::SizeAndOffsetAssertionHelper() {
  static_assert(sizeof(VirtualStreamConfig) == sizeof(fidl_xunion_t));
  static_assert(offsetof(VirtualStreamConfig, ordinal_) == offsetof(fidl_xunion_t, tag));
  static_assert(offsetof(VirtualStreamConfig, envelope_) == offsetof(fidl_xunion_t, envelope));
}

namespace {

[[maybe_unused]]
constexpr uint64_t kVirtualCameraFactory_CreateDevice_Ordinal = 2009870148lu << 32;
extern "C" const fidl_type_t fuchsia_camera_common_VirtualCameraFactoryCreateDeviceRequestTable;

}  // namespace

zx_status_t VirtualCameraFactory::SyncClient::CreateDevice(VirtualCameraConfig config) {
  return VirtualCameraFactory::Call::CreateDevice(zx::unowned_channel(this->channel_), std::move(config));
}

zx_status_t VirtualCameraFactory::Call::CreateDevice(zx::unowned_channel _client_end, VirtualCameraConfig config) {
  constexpr uint32_t _kWriteAllocSize = ::fidl::internal::ClampedMessageSize<CreateDeviceRequest>();
  std::unique_ptr<uint8_t[]> _write_bytes_unique_ptr(new uint8_t[_kWriteAllocSize]);
  uint8_t* _write_bytes = _write_bytes_unique_ptr.get();
  CreateDeviceRequest _request = {};
  _request._hdr.ordinal = kVirtualCameraFactory_CreateDevice_Ordinal;
  _request.config = std::move(config);
  auto _linearize_result = ::fidl::Linearize(&_request, ::fidl::BytePart(_write_bytes,
                                                                         _kWriteAllocSize));
  if (_linearize_result.status != ZX_OK) {
    return _linearize_result.status;
  }
  ::fidl::DecodedMessage<CreateDeviceRequest> _decoded_request = std::move(_linearize_result.message);
  auto _encode_request_result = ::fidl::Encode(std::move(_decoded_request));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}

zx_status_t VirtualCameraFactory::SyncClient::CreateDevice(::fidl::BytePart _request_buffer, VirtualCameraConfig config) {
  return VirtualCameraFactory::Call::CreateDevice(zx::unowned_channel(this->channel_), std::move(_request_buffer), std::move(config));
}

zx_status_t VirtualCameraFactory::Call::CreateDevice(zx::unowned_channel _client_end, ::fidl::BytePart _request_buffer, VirtualCameraConfig config) {
  if (_request_buffer.capacity() < CreateDeviceRequest::PrimarySize) {
    return ZX_ERR_BUFFER_TOO_SMALL;
  }
  CreateDeviceRequest _request = {};
  _request._hdr.ordinal = kVirtualCameraFactory_CreateDevice_Ordinal;
  _request.config = std::move(config);
  auto _linearize_result = ::fidl::Linearize(&_request, std::move(_request_buffer));
  if (_linearize_result.status != ZX_OK) {
    return _linearize_result.status;
  }
  ::fidl::DecodedMessage<CreateDeviceRequest> _decoded_request = std::move(_linearize_result.message);
  auto _encode_request_result = ::fidl::Encode(std::move(_decoded_request));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}

zx_status_t VirtualCameraFactory::SyncClient::CreateDevice(::fidl::DecodedMessage<CreateDeviceRequest> params) {
  return VirtualCameraFactory::Call::CreateDevice(zx::unowned_channel(this->channel_), std::move(params));
}

zx_status_t VirtualCameraFactory::Call::CreateDevice(zx::unowned_channel _client_end, ::fidl::DecodedMessage<CreateDeviceRequest> params) {
  params.message()->_hdr = {};
  params.message()->_hdr.ordinal = kVirtualCameraFactory_CreateDevice_Ordinal;
  auto _encode_request_result = ::fidl::Encode(std::move(params));
  if (_encode_request_result.status != ZX_OK) {
    return _encode_request_result.status;
  }
  return ::fidl::Write(std::move(_client_end), std::move(_encode_request_result.message));
}


bool VirtualCameraFactory::TryDispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
  if (msg->num_bytes < sizeof(fidl_message_header_t)) {
    zx_handle_close_many(msg->handles, msg->num_handles);
    txn->Close(ZX_ERR_INVALID_ARGS);
    return true;
  }
  fidl_message_header_t* hdr = reinterpret_cast<fidl_message_header_t*>(msg->bytes);
  switch (hdr->ordinal) {
    case kVirtualCameraFactory_CreateDevice_Ordinal: {
      auto result = ::fidl::DecodeAs<CreateDeviceRequest>(msg);
      if (result.status != ZX_OK) {
        txn->Close(ZX_ERR_INVALID_ARGS);
        return true;
      }
      auto message = result.message.message();
      impl->CreateDevice(std::move(message->config),
        Interface::CreateDeviceCompleter::Sync(txn));
      return true;
    }
    default: {
      return false;
    }
  }
}

bool VirtualCameraFactory::Dispatch(Interface* impl, fidl_msg_t* msg, ::fidl::Transaction* txn) {
  bool found = TryDispatch(impl, msg, txn);
  if (!found) {
    zx_handle_close_many(msg->handles, msg->num_handles);
    txn->Close(ZX_ERR_NOT_SUPPORTED);
  }
  return found;
}


}  // namespace common
}  // namespace camera
}  // namespace fuchsia
}  // namespace llcpp
