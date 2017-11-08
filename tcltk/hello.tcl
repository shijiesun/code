#!/usr/bin/tclsh
# filename hello2.tcl
# This program code shows 
# metacharacter usage
 
puts stdout "Hello, World! \a"
puts stdout {Hello, World! \a}
 
set Pints 6
set Days 7
 
puts stdout "The answer to the \
 universe is [eval $Pints * $Days]!\n"
     
***
~/tcltk$ ./hello2.tcl
Hello, World!
Hello, World! \a
The answer to everything is 42!
