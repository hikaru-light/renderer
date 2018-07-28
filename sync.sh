#!/bin/sh

read -p "Enter transport type : " type

case "$type" in
	"s") scp -r ~/works/renderer light@118.9.182.124:~/
			 break;;
	"r") scp -r light@118.9.182.124:~/renderer ~/works/
			 break;;
esac

