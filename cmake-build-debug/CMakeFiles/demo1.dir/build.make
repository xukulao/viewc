# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\c\viewc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\c\viewc\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/demo1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo1.dir/flags.make

CMakeFiles/demo1.dir/demo.c.obj: CMakeFiles/demo1.dir/flags.make
CMakeFiles/demo1.dir/demo.c.obj: ../demo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\c\viewc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/demo1.dir/demo.c.obj"
	D:\posix\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\demo1.dir\demo.c.obj   -c E:\c\viewc\demo.c

CMakeFiles/demo1.dir/demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo1.dir/demo.c.i"
	D:\posix\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\c\viewc\demo.c > CMakeFiles\demo1.dir\demo.c.i

CMakeFiles/demo1.dir/demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo1.dir/demo.c.s"
	D:\posix\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\c\viewc\demo.c -o CMakeFiles\demo1.dir\demo.c.s

CMakeFiles/demo1.dir/demo_data_type.c.obj: CMakeFiles/demo1.dir/flags.make
CMakeFiles/demo1.dir/demo_data_type.c.obj: ../demo_data_type.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\c\viewc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/demo1.dir/demo_data_type.c.obj"
	D:\posix\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\demo1.dir\demo_data_type.c.obj   -c E:\c\viewc\demo_data_type.c

CMakeFiles/demo1.dir/demo_data_type.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo1.dir/demo_data_type.c.i"
	D:\posix\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\c\viewc\demo_data_type.c > CMakeFiles\demo1.dir\demo_data_type.c.i

CMakeFiles/demo1.dir/demo_data_type.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo1.dir/demo_data_type.c.s"
	D:\posix\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\c\viewc\demo_data_type.c -o CMakeFiles\demo1.dir\demo_data_type.c.s

# Object files for target demo1
demo1_OBJECTS = \
"CMakeFiles/demo1.dir/demo.c.obj" \
"CMakeFiles/demo1.dir/demo_data_type.c.obj"

# External object files for target demo1
demo1_EXTERNAL_OBJECTS =

demo1.exe: CMakeFiles/demo1.dir/demo.c.obj
demo1.exe: CMakeFiles/demo1.dir/demo_data_type.c.obj
demo1.exe: CMakeFiles/demo1.dir/build.make
demo1.exe: CMakeFiles/demo1.dir/linklibs.rsp
demo1.exe: CMakeFiles/demo1.dir/objects1.rsp
demo1.exe: CMakeFiles/demo1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\c\viewc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable demo1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\demo1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo1.dir/build: demo1.exe

.PHONY : CMakeFiles/demo1.dir/build

CMakeFiles/demo1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\demo1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/demo1.dir/clean

CMakeFiles/demo1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\c\viewc E:\c\viewc E:\c\viewc\cmake-build-debug E:\c\viewc\cmake-build-debug E:\c\viewc\cmake-build-debug\CMakeFiles\demo1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo1.dir/depend

