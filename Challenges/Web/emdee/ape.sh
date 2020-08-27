#!/usr/bin/bash
va=$(curl 'http://docker.hackthebox.eu:30441/' | grep "MD5 encrypt" | cut -d '>' -f4| cut -d '<' -f1)
echo $va
fin=$(echo -n $va | md5sum | tr -d " -")
curl 'http://docker.hackthebox.eu:30441/' -H 'Host: docker.hackthebox.eu:30441' --data 'hash=$fin'