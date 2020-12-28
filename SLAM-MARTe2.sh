#!/bin/bash

mkdir Projects
mkdir Projects/SLAM-Python
cd Projects/SLAM-Python

git clone https://github.com/ibvandersluis/fastslam.git
git clone https://github.com/ibvandersluis/bioslam.git

cd ../

git clone https://vcis-gitlab.f4e.europa.eu/aneto/MARTe2.git
git clone https://vcis-gitlab.f4e.europa.eu/aneto/MARTe2-components.git
git clone https://vcis-gitlab.f4e.europa.eu/aneto/MARTe2-demos-padova.git

export TARGET=x86-linux
export MARTe2_DIR=~/Projects/MARTe2-dev
export MARTe2_Components_DIR=~/Projects/MARTe2-components

cd ~/Projects/MARTe2-dev
make -f Makefile.x86-linux
cd ~/Projects/MARTe2-components
make -f Makefile.linux
cd ~/Projects/MARTe2-demos-padova
make -f Makefile.x86-linux

echo "Setup done"
#echo "Starting MARTe2 test"

#cd Startup
#./Main.sh -l RealTimeLoader -f ../Configurations/RTApp-1-1.cfg -s State1

