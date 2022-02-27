rm -rf build
cmake -B build
cmake --build build
./build/tree < edges.txt
