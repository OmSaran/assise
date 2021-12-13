/home/ubuntu/nova-tester/testing/strata/format
cd /home/ubuntu/nova-tester; sudo rmmod logger-strata; python3 /home/ubuntu/nova-tester/load-logger-strata.py && sudo chmod 777 /dev/ioctl_dummy
cd /home/ubuntu/assise/kernfs/tests; /home/ubuntu/assise/kernfs/tests/mkfs.sh
cd /home/ubuntu/assise/kernfs/tests; /home/ubuntu/assise/kernfs/tests/run.sh kernfs

