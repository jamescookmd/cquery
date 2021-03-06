#pragma once

#include <optional.h>
#include <memory>
#include <string>

using std::experimental::optional;
using std::experimental::nullopt;

struct Config;
struct IndexFile;

std::unique_ptr<IndexFile> LoadCachedIndex(Config* config,
                                           const std::string& filename);

optional<std::string> LoadCachedFileContents(Config* config,
                                             const std::string& filename);

void WriteToCache(Config* config,
                  const std::string& filename,
                  IndexFile& file,
                  const optional<std::string>& indexed_file_contents);