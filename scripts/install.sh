
echo "--------- Install gtest ---------"
sudo apt-get install libgtest-dev
cd /usr/src/googletest/googletest
sudo mkdir build && cd build
sudo cmake ..
sudo make
sudo make install
cd ..
rm -rf build

echo "--------- Install MathC ---------"
git clone https://github.com/LarinGleb/Math
cd Math
mkdir build
cmake -H. -Bbuild
sudo cmake --build build --target install
cd ../
rm -rf Math
