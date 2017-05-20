cat c.in | ruby c_naive.rb > c_naive.out
cat c.in | ruby c.rb > c.out
diff c.out c_naive.out
