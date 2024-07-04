#!/bin/bash

for i in {0..4}
do
	git rev-parse HEAD~$i
done

exit
