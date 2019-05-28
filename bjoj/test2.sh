shopt -s extglob dotglob nullglob

for file in ~/Downloads/problems/a/!(*a); 
do
# output=`echo "$file" | sed -e 's/in$/ans/'`
  output="${file}a"
  echo ${file}
  echo ${output}
  ./sol < ${file} | diff -b - ${output}
done
