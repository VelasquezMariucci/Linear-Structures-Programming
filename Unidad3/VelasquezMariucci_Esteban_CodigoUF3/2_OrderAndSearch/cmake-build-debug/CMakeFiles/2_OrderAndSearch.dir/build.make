# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = C:\Users\esvel\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\esvel\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2_OrderAndSearch.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/2_OrderAndSearch.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/2_OrderAndSearch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_OrderAndSearch.dir/flags.make

CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj: CMakeFiles/2_OrderAndSearch.dir/flags.make
CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj: C:/Users/esvel/OneDrive/Desktop/Code/C++/Unidad3/VelasquezMariucci_Esteban_CodigoUF3/2_OrderAndSearch/main.cpp
CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj: CMakeFiles/2_OrderAndSearch.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj -MF CMakeFiles\2_OrderAndSearch.dir\main.cpp.obj.d -o CMakeFiles\2_OrderAndSearch.dir\main.cpp.obj -c C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\main.cpp

CMakeFiles/2_OrderAndSearch.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/2_OrderAndSearch.dir/main.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\main.cpp > CMakeFiles\2_OrderAndSearch.dir\main.cpp.i

CMakeFiles/2_OrderAndSearch.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/2_OrderAndSearch.dir/main.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\main.cpp -o CMakeFiles\2_OrderAndSearch.dir\main.cpp.s

# Object files for target 2_OrderAndSearch
2_OrderAndSearch_OBJECTS = \
"CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj"

# External object files for target 2_OrderAndSearch
2_OrderAndSearch_EXTERNAL_OBJECTS =

2_OrderAndSearch.exe: CMakeFiles/2_OrderAndSearch.dir/main.cpp.obj
2_OrderAndSearch.exe: CMakeFiles/2_OrderAndSearch.dir/build.make
2_OrderAndSearch.exe: CMakeFiles/2_OrderAndSearch.dir/linkLibs.rsp
2_OrderAndSearch.exe: CMakeFiles/2_OrderAndSearch.dir/objects1.rsp
2_OrderAndSearch.exe: CMakeFiles/2_OrderAndSearch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2_OrderAndSearch.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2_OrderAndSearch.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_OrderAndSearch.dir/build: 2_OrderAndSearch.exe
.PHONY : CMakeFiles/2_OrderAndSearch.dir/build

CMakeFiles/2_OrderAndSearch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2_OrderAndSearch.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2_OrderAndSearch.dir/clean

CMakeFiles/2_OrderAndSearch.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\cmake-build-debug C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\cmake-build-debug C:\Users\esvel\OneDrive\Desktop\Code\C++\Unidad3\VelasquezMariucci_Esteban_CodigoUF3\2_OrderAndSearch\cmake-build-debug\CMakeFiles\2_OrderAndSearch.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/2_OrderAndSearch.dir/depend

