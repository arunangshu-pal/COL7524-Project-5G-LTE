Contains programs and scripts to collect ndt7 and Speedtest CLI data in a GNU/Linux system. A job may be created that runs in a Raspberry Pi computer to automatically collect data.

ndt7 or NDT Client is a program provided by Measurement Lab (MLAB) to measure download and upload speeds. The product's name is NDT (Network Diagnostic Tool).
Speedtest CLI is a product (program/executable name: speedtest) provided by Ookla, LLC. to measure download and upload speeds.

This is a part of our project tentatively titled Project Sangjog or Project 5G/LTE. "Sangjog" means communication or connection in Indian languages.

Github link: 

Prerequisites for this project:
You should have both ndt7 from MLab and Speedtest CLI installed in your Raspberry Pi system. They can be easily downloaded from MLab's page and Ookla's page (links given below) and installed on your system.

MLab's NDT: https://www.measurementlab.net/tests/ndt/
You need to download ndt7-client-go from the following Github repository: https://github.com/m-lab/ndt7-client-go

Ookla's Speedtest CLI: https://www.speedtest.net/apps/cli

Although you may install any GNU/Linux distribution of your choice on your Raspberry Pi computer, we recommend the Debian 13-based Raspberry Pi OS, the same system that we have used.

Set the admin user of the Raspberry Pi system as "rpadmin" as our script assumes that "rpadmin" is the admin user with which the system boots by default. If the username is different, replace "rpadmin" with the correct username in the scripts of RPiPackage.

Follow the steps below to create the experimental setup in a Raspberry Pi computer after you have satisfied the above requirements, i.e. after you have installed both NDT and Speedtest CLI on Raspberry Pi OS in Raspberry Pi computer.

1. In your Raspberry Pi computer, open Terminal and clone the Github repository for this project as follows.
2. $ git clone
3. Now enter the RPiPackage directory
4. Then, enter the RPiPackage directory and run install.sh (with sudo) to install the data collection package on your system as follows.
5. .../RPiPackage$ sudo ./install.sh
6. 
   
