# Script to kill the recordata job that is run as a cron job at boot.

echo "Job running before killing:"
pgrep -fl -i recorddata

pkill -i recorddata
echo "\nrecordData job killed.\n"

echo "Job running after killing:"
pgrep -fl -i recorddata

