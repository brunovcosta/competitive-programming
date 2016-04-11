t = gets .to_i
for i in 1..t do
	numbers = gets .chop .split " "
	k=numbers[0].to_i
	c=numbers[1].to_i
	s=numbers[2].to_i
	if k>s*(2**(c-1)) then
		puts "Case ##{i}: IMPOSSIBLE"
	else
		output=""
		first = 2*(k**c)/3
		for j in 1..s do
			output+=" #{(first+j) % (k**c)+1}"
		end
		puts "Case ##{i}:"+output
	end
end
