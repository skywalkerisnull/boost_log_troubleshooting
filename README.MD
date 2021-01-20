# Lessons Learnt

This now builds thanks to the help from a Slack user by the name of Rommudoh.

Lessons learnt:
* Cmakes ```find_package( Boost REQUIRED)``` needs to have the specific components that I need in the code.
* In the top level CMakeLists.txt I needed to add ```target_include_directories```
* In the top lelvel CMakeLists.txt I needed to add the library that I need to connect to in the ```target_link_libraries```
* Instead of using ```add_executable()``` in the sub directory, I should have used ```add_library```
