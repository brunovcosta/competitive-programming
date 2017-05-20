T = gets.to_i


def insert! stalls
	size = stalls.split("#").map(&:size).max
	gap = "_"*size
	filled = gap.dup
	filled[gap.size/2]="#"
	stalls.sub! gap,filled

	return [gap.size/2,gap.size - gap.size/2-1]
end
for i in 1..T
	data = gets.split
	n = data[0].to_i
	k = data[1].to_i

	stalls = "_"*n

	distances = []
	k.times do
		distances = insert! stalls
	end


	#p stalls.split("#").map(&:size).sort
	puts "Teste #{100/(2*k-1)}"
	puts "Case ##{i}: #{distances.sort.last} #{distances.sort.first}"
	#puts stalls
	#print "#{distances.sort.first}\t "
end
