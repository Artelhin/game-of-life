cd $(dirname $0)
mkdir -p build
cd build
cmake ..
make -j 4
cp ./GoL ..