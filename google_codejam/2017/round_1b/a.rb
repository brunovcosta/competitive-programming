t = gets.to_i

def min_time d,k,s
	return (d-k)/s.to_f
end

for i in 1..t do
	input = gets.split
	d = input[0].to_i
	n = input[1].to_i

	k = []
	s = []

	times = []


	n.times do
		input = gets.split
		k<<input[0].to_i
		s<<input[1].to_i

		times << [(min_time d,k.last,s.last),d,k.last,s.last] if k.last>0
	end

	puts "Case ##{i}: #{d/times.max[0]}"
end
