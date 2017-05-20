while(TRUE) do
	n = gets
	break if n=="\n"
	n = n.to_i
	c = 0
	while c*c <= n do
		puts "c"
		puts c
		puts c*c
		c+=1
	end
	puts n-c+1
end
