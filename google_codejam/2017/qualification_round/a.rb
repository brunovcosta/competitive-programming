def move pancakes,pos,k
	pos1=pos
	pos2=pos+k-1
	range = pos1..pos2
	return pancakes.map.with_index do |pancake,index|
		next pancake.dup unless range.include? index
		next case pancake
		when '-'
			'+'
		when '+'
			'-'
		end
	end
end

def ready? pancakes
	return pancakes.all? {|pancake| pancake=='+'}
end
def min_moves pancakes,k
	s = pancakes.size
	places = (s-k+1)
	return 0 if ready? pancakes
	for i in 1..places do
		#puts "i = #{i}"
		for combination in (0..(places-1)).to_a.combination(i) do
			copy = pancakes.map &:dup
			#puts "comb = #{combination}"
			for position in combination do
				#puts "copy = #{copy.join}"
				copy = move copy,position,k
			end
			#puts "copy = #{copy.join}"
			#puts "======================================"
			return i if ready? copy
		end
	end
	return "IMPOSSIBLE"
end

T = gets.to_i
for i in 1..T do
	row = gets.chomp
	pancakes = row.split[0].chars
	k = row.split[1].to_i

	puts "Case ##{i}: #{min_moves pancakes,k}"
	
end
