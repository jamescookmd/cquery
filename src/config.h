#pragma once

#include "serializer.h"

#include <string>

struct Config {
  // Root directory of the project. **Not serialized**
  std::string projectRoot;
  std::string cacheDirectory;

  std::vector<std::string> extraClangArguments;

  std::vector<std::string> indexWhitelist;
  std::vector<std::string> indexBlacklist;
  // If true, project paths that were skipped by the whitelist/blacklist will
  // be logged.
  bool logSkippedPathsForIndex = false;
 
  // Maximum workspace search results.
  int maxWorkspaceSearchResults = 1000;

  // Force a certain number of indexer threads. If less than 1 a default value
  // should be used.
  int indexerCount = 0;
  // If false, the indexer will be disabled.
  bool enableIndexing = true;
  // If false, indexed files will not be written to disk.
  bool enableCacheWrite = true;
  // If false, the index will not be loaded from a previous run.
  bool enableCacheRead = true;

  // If true, document links are reported for #include directives.
  bool showDocumentLinksOnIncludes = true;

  // Maximum path length to show in completion results. Paths longer than this
  // will be elided with ".." put at the front. Set to 0 or a negative number
  // to disable eliding.
  int includeCompletionMaximumPathLength = 30;
  // Whitelist that file paths will be tested against. If a file path does not
  // end in one of these values, it will not be considered for auto-completion.
  // An example value is { ".h", ".hpp" }
  //
  // This is significantly faster than using a regex.
  std::vector<std::string> includeCompletionWhitelistLiteralEnding;
  // Regex patterns to match include completion candidates against. They
  // receive the absolute file path.
  //
  // For example, to hide all files in a /CACHE/ folder, use ".*/CACHE/.*"
  std::vector<std::string> includeCompletionWhitelist;
  std::vector<std::string> includeCompletionBlacklist;

  // Enables code lens on parameter and function variables.
  bool codeLensOnLocalVariables = true;

  // Version of the client.
  int clientVersion = 0;
};
MAKE_REFLECT_STRUCT(Config,
  cacheDirectory,

  extraClangArguments,

  indexWhitelist, indexBlacklist,
  logSkippedPathsForIndex,

  maxWorkspaceSearchResults,
  indexerCount,
  enableIndexing, enableCacheWrite, enableCacheRead,

  includeCompletionMaximumPathLength,
  includeCompletionWhitelistLiteralEnding,
  includeCompletionWhitelist, includeCompletionBlacklist,

  showDocumentLinksOnIncludes,

  codeLensOnLocalVariables,

  clientVersion);