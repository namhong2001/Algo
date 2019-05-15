while [[ $? == 0 ]]; do
  ./make_input > in && \
  ./sol < in > out1 && \
  ./test < in > out2 && \
  diff -b ./out1 ./out2
done
