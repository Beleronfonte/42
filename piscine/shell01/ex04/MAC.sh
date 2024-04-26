#!/bin/sh

ifconfig | grep -Rns ether | cut -f 2| cut -d " " -f 2
