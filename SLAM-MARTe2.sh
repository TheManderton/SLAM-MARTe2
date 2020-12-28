#!/bin/bash

mkdir Projects
mkdir Projects/SLAM-Python
cd Projects/SLAM-Python

git clone https://github.com/ibvandersluis/fastslam.git
git clone https://github.com/ibvandersluis/bioslam.git

sudo apt-get install "Development Tools" -y
sudo apt-get install wget cmake python tmux -y

cd ../

git clone https://github.com/TheManderton/MARTe2.git
git clone https://github.com/TheManderton/MARTe2-components.git

export TARGET=x86-linux
export MARTe2_DIR=~/SLAM-MARTe2/Projects/MARTe2
export MARTe2_Components_DIR=~/SLAM-MARTe2/Projects/MARTe2-components

cd ~/SLAM-MARTe2/Projects/MARTe2
make -f Makefile.x86-linux
cd ~/SLAM-MARTe2/Projects/MARTe2-components
make -f Makefile.linux
cd ../../

echo "Setup done"
echo "Starting MARTe2 test"

timeout 10s ./Main.sh -l RealTimeLoader -f Configurations/RTApp-1-1.cfg -s State1

echo "Test done"
