t = gets .to_i
for i in 1..t do
	n = gets .to_i
	if n==0 then
		puts "Case ##{i}: INSOMNIA"
	else
		found = []
		counter=0
		while found.size<10 do
			counter+=n
			found = found | counter.to_s.chars
		end
		puts "Case ##{i}: #{counter}"
	end
end
