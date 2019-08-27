while [[ $? == 0 ]]
do
	./make_input > input.txt 
	./sol < input.txt > myout.txt
	./test < input.txt > ans.txt
	diff myout.txt ans.txt
done

