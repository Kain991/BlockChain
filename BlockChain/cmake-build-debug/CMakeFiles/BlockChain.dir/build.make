# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kaina\CLionProjects\BlockChain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kaina\CLionProjects\BlockChain\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BlockChain.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BlockChain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BlockChain.dir/flags.make

CMakeFiles/BlockChain.dir/main.cpp.obj: CMakeFiles/BlockChain.dir/flags.make
CMakeFiles/BlockChain.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kaina\CLionProjects\BlockChain\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BlockChain.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BlockChain.dir\main.cpp.obj -c C:\Users\kaina\CLionProjects\BlockChain\main.cpp

CMakeFiles/BlockChain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BlockChain.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kaina\CLionProjects\BlockChain\main.cpp > CMakeFiles\BlockChain.dir\main.cpp.i

CMakeFiles/BlockChain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BlockChain.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kaina\CLionProjects\BlockChain\main.cpp -o CMakeFiles\BlockChain.dir\main.cpp.s

# Object files for target BlockChain
BlockChain_OBJECTS = \
"CMakeFiles/BlockChain.dir/main.cpp.obj"

# External object files for target BlockChain
BlockChain_EXTERNAL_OBJECTS =

BlockChain.exe: CMakeFiles/BlockChain.dir/main.cpp.obj
BlockChain.exe: CMakeFiles/BlockChain.dir/build.make
BlockChain.exe: CMakeFiles/BlockChain.dir/linklibs.rsp
BlockChain.exe: CMakeFiles/BlockChain.dir/objects1.rsp
BlockChain.exe: CMakeFiles/BlockChain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kaina\CLionProjects\BlockChain\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BlockChain.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BlockChain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BlockChain.dir/build: BlockChain.exe
.PHONY : CMakeFiles/BlockChain.dir/build

CMakeFiles/BlockChain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BlockChain.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BlockChain.dir/clean

CMakeFiles/BlockChain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kaina\CLionProjects\BlockChain C:\Users\kaina\CLionProjects\BlockChain C:\Users\kaina\CLionProjects\BlockChain\cmake-build-debug C:\Users\kaina\CLionProjects\BlockChain\cmake-build-debug C:\Users\kaina\CLionProjects\BlockChain\cmake-build-debug\CMakeFiles\BlockChain.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BlockChain.dir/depend

