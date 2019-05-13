while [[ $? == 0 ]]; do
  ./gen_input > input.txt 
  ./fair_set2 < input.txt > output_1.txt
  ./test < input.txt > output_2.txt
  diff -b ./output_1.txt ./output_2.txt
done
