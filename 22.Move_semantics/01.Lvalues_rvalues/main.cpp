/*
    . Move semantics: 
        .#1: Lvalues and rvalues
            . see move_semantics_01.ixx

        .#2: Rvalue references
            . see move_semantics_02.ixx

        .#3: Moving temporaries around
            . see move_semantics_03.ixx

        .#4: Move constructor and move assignment operator
            . see move_semantics_04.ixx

        .#5: Moving lvalues with std::move
            . see move_semantics_05.ixx

        .#6: Invalidate pointers after move
            . see move_semantics_06.ixx 

        .#7: Move only types
            . see move_semantics_07.ixx

        .#8: Passing by rvalue reference
            . see move_semantics_08.ixx

    . Build instructions: 
        . Bare hands with CMake: 
            . cmake -S . -B build
            . cmake --build build

        . With CMake presets (VS Code): 
            . Select configure preset
            . Select build preset
            . Use the run and debug buttons: We can debug application right from the start.

        . Can also use presets on the command line.
    . Dependencies: 
        . gcc
        . cmake
        . ninja
        . vcpkg and setting up the VCPKG_ROOT environment variable
        . gdb any version

*/

// One line comment
#include "utilities.h"

int main() {
  //move_semantics_01_demo();
  //move_semantics_02_demo();
  //move_semantics_03_demo();
  //move_semantics_04_demo();
  //move_semantics_05_demo();
  move_semantics_06_demo();

}