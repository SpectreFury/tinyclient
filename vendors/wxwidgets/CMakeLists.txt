include(FetchContent)

message(STATUS "Fetching wxWidgets")
FetchContent_Declare(
  wxwidgets
  GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
  GIT_TAG master
)

FetchContent_MakeAvailable(wxwidgets)
message(STATUS "Fetched wxWidgets")
