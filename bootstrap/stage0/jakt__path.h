#pragma once
#include "__unified_forward.h"
#include "jakt__platform.h"
#include "jakt__platform__unknown_path.h"
namespace Jakt {
namespace jakt__path {
struct Path {
  public:
private: ByteString path;public: static jakt__path::Path from_string(ByteString const string);
public: static jakt__path::Path from_parts(JaktInternal::DynamicArray<ByteString> const parts);
private: void normalize_separators();
public: ByteString to_string() const;
public: jakt__path::Path join(ByteString const path) const;
public: jakt__path::Path join(jakt__path::Path const path) const;
public: bool is_dot() const;
public: ByteString extension() const;
public: ByteString basename(bool const strip_extension) const;
public: ErrorOr<jakt__path::Path> replace_extension(ByteString const new_extension) const;
public: jakt__path::Path parent() const;
public: bool exists() const;
public: JaktInternal::DynamicArray<ByteString> components() const;
private: JaktInternal::Tuple<ByteString,ByteString> split_at_last_slash() const;
private: static JaktInternal::Optional<size_t> last_slash(ByteString const path);
public: Path(ByteString a_path);

public: ErrorOr<jakt__path::Path> absolute() const;
public: ByteString debug_description() const;
};}
} // namespace Jakt
template<>struct Jakt::Formatter<Jakt::jakt__path::Path> : Jakt::Formatter<Jakt::StringView>{
Jakt::ErrorOr<void> format(Jakt::FormatBuilder& builder, Jakt::jakt__path::Path const& value) {
JaktInternal::PrettyPrint::ScopedEnable pretty_print_enable { m_alternative_form };Jakt::ErrorOr<void> format_error = Jakt::Formatter<Jakt::StringView>::format(builder, value.debug_description());return format_error;}
};
namespace Jakt {
} // namespace Jakt
