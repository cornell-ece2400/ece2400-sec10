
# Remove the previous results file

rm -f slist-int-reverse-v2-eval.txt

# Run the evaluation
./scripts/eval.sh
for i in {2000,4000,6000,8000,10000}; do
  ./build/eval/slist-int-reverse-v2-eval $i | tee -a slist-int-reverse-v2-eval.txt;
done

