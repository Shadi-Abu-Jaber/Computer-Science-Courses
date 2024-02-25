#!/bin/bash
read -p "Enter 4 input values in range (1-8): " VAR1 VAR2 VAR3 VAR4
echo "the sum of these values is $(($VAR1+$VAR2+$VAR3+$VAR4))"
echo "the product of these values is $(($VAR1*$VAR2*$VAR3*$VAR4))"
cd /home/cs212955108/Lab4/SubLab4Dir
file_with_k=$(ls *k*)
mv $file_with_k $file_with_k$VAR1
