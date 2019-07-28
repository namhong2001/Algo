RANGE=1000000001;

while [[ $? == 0 ]]; do
  RAND1=($RANDOM % $RANGE);
  RAND2=($RANDOM % $RANGE); 
  echo "$RAND1 $RAND2" > in2
  ./sol < in2 > ji.txt
  ./sol2 < in2 > nh.txt
  diff -b ./ji.txt ./nh.txt
done
