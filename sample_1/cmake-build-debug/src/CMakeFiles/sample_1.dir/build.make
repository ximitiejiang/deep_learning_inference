# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/ubuntu/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ubuntu/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/suliang_git/deep_learning_inference/sample_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/sample_1.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/sample_1.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/sample_1.dir/flags.make

src/CMakeFiles/sample_1.dir/getOptions.cpp.o: src/CMakeFiles/sample_1.dir/flags.make
src/CMakeFiles/sample_1.dir/getOptions.cpp.o: ../src/getOptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/sample_1.dir/getOptions.cpp.o"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_1.dir/getOptions.cpp.o -c /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/getOptions.cpp

src/CMakeFiles/sample_1.dir/getOptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_1.dir/getOptions.cpp.i"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/getOptions.cpp > CMakeFiles/sample_1.dir/getOptions.cpp.i

src/CMakeFiles/sample_1.dir/getOptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_1.dir/getOptions.cpp.s"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/getOptions.cpp -o CMakeFiles/sample_1.dir/getOptions.cpp.s

src/CMakeFiles/sample_1.dir/logger.cpp.o: src/CMakeFiles/sample_1.dir/flags.make
src/CMakeFiles/sample_1.dir/logger.cpp.o: ../src/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/sample_1.dir/logger.cpp.o"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_1.dir/logger.cpp.o -c /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/logger.cpp

src/CMakeFiles/sample_1.dir/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_1.dir/logger.cpp.i"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/logger.cpp > CMakeFiles/sample_1.dir/logger.cpp.i

src/CMakeFiles/sample_1.dir/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_1.dir/logger.cpp.s"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/logger.cpp -o CMakeFiles/sample_1.dir/logger.cpp.s

src/CMakeFiles/sample_1.dir/main.cpp.o: src/CMakeFiles/sample_1.dir/flags.make
src/CMakeFiles/sample_1.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/sample_1.dir/main.cpp.o"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_1.dir/main.cpp.o -c /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/main.cpp

src/CMakeFiles/sample_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_1.dir/main.cpp.i"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/main.cpp > CMakeFiles/sample_1.dir/main.cpp.i

src/CMakeFiles/sample_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_1.dir/main.cpp.s"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/main.cpp -o CMakeFiles/sample_1.dir/main.cpp.s

src/CMakeFiles/sample_1.dir/sampleEngines.cpp.o: src/CMakeFiles/sample_1.dir/flags.make
src/CMakeFiles/sample_1.dir/sampleEngines.cpp.o: ../src/sampleEngines.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/sample_1.dir/sampleEngines.cpp.o"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_1.dir/sampleEngines.cpp.o -c /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/sampleEngines.cpp

src/CMakeFiles/sample_1.dir/sampleEngines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_1.dir/sampleEngines.cpp.i"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/sampleEngines.cpp > CMakeFiles/sample_1.dir/sampleEngines.cpp.i

src/CMakeFiles/sample_1.dir/sampleEngines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_1.dir/sampleEngines.cpp.s"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/sampleEngines.cpp -o CMakeFiles/sample_1.dir/sampleEngines.cpp.s

src/CMakeFiles/sample_1.dir/sampleOptions.cpp.o: src/CMakeFiles/sample_1.dir/flags.make
src/CMakeFiles/sample_1.dir/sampleOptions.cpp.o: ../src/sampleOptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/sample_1.dir/sampleOptions.cpp.o"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sample_1.dir/sampleOptions.cpp.o -c /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/sampleOptions.cpp

src/CMakeFiles/sample_1.dir/sampleOptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sample_1.dir/sampleOptions.cpp.i"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/sampleOptions.cpp > CMakeFiles/sample_1.dir/sampleOptions.cpp.i

src/CMakeFiles/sample_1.dir/sampleOptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sample_1.dir/sampleOptions.cpp.s"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src/sampleOptions.cpp -o CMakeFiles/sample_1.dir/sampleOptions.cpp.s

# Object files for target sample_1
sample_1_OBJECTS = \
"CMakeFiles/sample_1.dir/getOptions.cpp.o" \
"CMakeFiles/sample_1.dir/logger.cpp.o" \
"CMakeFiles/sample_1.dir/main.cpp.o" \
"CMakeFiles/sample_1.dir/sampleEngines.cpp.o" \
"CMakeFiles/sample_1.dir/sampleOptions.cpp.o"

# External object files for target sample_1
sample_1_EXTERNAL_OBJECTS =

src/sample_1: src/CMakeFiles/sample_1.dir/getOptions.cpp.o
src/sample_1: src/CMakeFiles/sample_1.dir/logger.cpp.o
src/sample_1: src/CMakeFiles/sample_1.dir/main.cpp.o
src/sample_1: src/CMakeFiles/sample_1.dir/sampleEngines.cpp.o
src/sample_1: src/CMakeFiles/sample_1.dir/sampleOptions.cpp.o
src/sample_1: src/CMakeFiles/sample_1.dir/build.make
src/sample_1: /home/ubuntu/TensorRT-6.0.1.5/lib/libnvinfer.so
src/sample_1: /usr/local/cuda-9.0/lib64/libcublas.so
src/sample_1: /usr/local/cuda-9.0/lib64/libcudart.so
src/sample_1: src/CMakeFiles/sample_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sample_1"
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sample_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/sample_1.dir/build: src/sample_1

.PHONY : src/CMakeFiles/sample_1.dir/build

src/CMakeFiles/sample_1.dir/clean:
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/sample_1.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/sample_1.dir/clean

src/CMakeFiles/sample_1.dir/depend:
	cd /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/suliang_git/deep_learning_inference/sample_1 /home/ubuntu/suliang_git/deep_learning_inference/sample_1/src /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src /home/ubuntu/suliang_git/deep_learning_inference/sample_1/cmake-build-debug/src/CMakeFiles/sample_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/sample_1.dir/depend
