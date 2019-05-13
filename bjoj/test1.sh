while [[ $? == 0 ]]
do
	./test1 > input.txt 
	./13389 < input.txt > output.txt
	diff -b output.txt output2.txt
done

