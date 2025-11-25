This document has been written by the author of this project, Arunangshu Pal (arunangshupal@cse.iitd.ac.in).

This repository contains programs and scripts to collect ndt7 and Speedtest CLI data in a GNU/Linux system. A job may be created that runs in a Raspberry Pi computer to automatically collect data.

ndt7 or NDT Client is a program provided by Measurement Lab (MLAB) to measure download and upload speeds. The product's name is NDT (Network Diagnostic Tool).
Speedtest CLI is a product (program/executable name: speedtest) provided by Ookla, LLC. to measure download and upload speeds.

This is a part of our project tentatively titled Project Sangjog or Project 5G/LTE. "Sangjog" means communication or connection in Indian languages.

Github link: https://github.com/arunangshu-pal/COL7524-Project-5G-LTE

Prerequisites for this project:
You should have both ndt7 and Speedtest CLI installed in your Raspberry Pi system. They can be easily downloaded from MLab's page and Ookla's page (links given below) and installed on your system.

MLab's NDT: https://www.measurementlab.net/tests/ndt/
You need to download ndt7-client-go from the following Github repository: https://github.com/m-lab/ndt7-client-go

Ookla's Speedtest CLI: https://www.speedtest.net/apps/cli

Although you may install any GNU/Linux distribution of your choice on your Raspberry Pi computer, we recommend the Debian 13-based Raspberry Pi OS, the same system that we have used.

Set the admin user of the Raspberry Pi system as "rpadmin" as our script assumes that "rpadmin" is the admin user with which the system boots by default. If the username is different, replace "rpadmin" with the correct username in the scripts of RPiPackage.

Follow the steps below to create the experimental setup in a Raspberry Pi computer after you have satisfied the above requirements, i.e. after you have installed both NDT and Speedtest CLI on Raspberry Pi OS in a Raspberry Pi computer.

1. In your Raspberry Pi computer, open Terminal and clone the Github repository for this project as follows.
   $ git clone https://github.com/arunangshu-pal/COL7524-Project-5G-LTE

2. Inside the RPiPackage directory, ensure that: (i) in install.sh, the variable 'rpiUser' is equal to your admin user (currently, it is "rpadmin"), (ii) in recordDataJob.script, the variable 'dataRecord' is equal to the path of the directory where you want to save the data files (currently, it is "/home/rpadmin/Desktop/nwdata"), and (iii) in recordDataJob.script, the variable 'ndt7bin' is equal to the name of the executable for NDT Client (currently, it is "ndt7"), and the variable 'speedtestbin' is equal to the name of the executable for Speedtest CLI (currently, it is "speedtest").

3. Then, run install.sh (with sudo) in RPiPackage directory to install the data collection package on your system as follows.
   .../RPiPackage$ sudo ./install.sh

4. Now, a bash script called "recordData.job.sh" will be created in RPiPackage directory. Add a job in your crontab for running recordData.job.sh at reboot.

5. An executable called "extractCSV.out" will be created in /usr/local/bin/. Make a symbolic link to this executable in /usr/bin/ as follows:
   $ sudo ln -s /usr/local/bin/extractCSV.out /usr/bin

6. Now, your experimental setup is ready. When you reboot your Raspberry Pi computer, the data collecting job will run automatically.
   
7. After boot, if you want to abort the data collection job, simply run killjob.sh within 5 minutes of boot (since there is a 5 minute sleep time in the data collection job before the data collection begins) to terminate the job as follows: $ sudo ./killjob.sh

For any queries, feel free to reach the author.
