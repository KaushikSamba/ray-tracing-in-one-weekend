# Run Docker compose 
# Problem : 
# cpp-dev  | CMake Error: Cannot open file for write: /code/build/CMakeCache.txt.tmp
# cpp-dev  | CMake Error: : System Error: Permission denied
# cpp-dev  | CMake Error: Unable to open cache file for save. /code/build/CMakeCache.txt
# cpp-dev  | CMake Error: : System Error: Permission denied

CURRENT_UID="$(id -u):$(id -g)" docker compose up 