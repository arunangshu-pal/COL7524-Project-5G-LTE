#!/usr/bin/bash

recDataJobscriptname=recordDataJob.script
jobfname=recordData.job.sh
rpiUser=rpadmin

make
exCSVbin=extractCSV.out
cp -f $exCSVbin /usr/local/bin && chown $rpiUser:$rpiUser /usr/local/bin/$exCSVbin && echo "$exCSVbin installed successfully."

touch $jobfname
cat $recDataJobscriptname >$jobfname
chmod ugo+x $jobfname

echo "Installation complete. (See above for errors; if any error is encountered, rerun this script with sudo.)"