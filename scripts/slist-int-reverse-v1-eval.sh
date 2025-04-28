
# Remove the previous results file

rm -f slist-int-reverse-v1-eval.txt

# Run the evaluation
./scripts/eval.sh
for i in {200,400,600,800,1000}; do
  ./build/eval/slist-int-reverse-v1-eval $i | tee -a slist-int-reverse-v1-eval.txt;
done

