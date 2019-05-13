while [[ $? == 0 ]]; do
  ./test1 > input.txt 
  ./11495_1 < input.txt > output_1.txt
  ./test < input.txt > output_2.txt
  diff -b ./output_1.txt ./output_2.txt
done
