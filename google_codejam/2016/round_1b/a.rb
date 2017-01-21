names=["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
order = [0,2,4,6,8,3,5,1,7,9]
t=gets.to_i
for i in 1..t do
	written = gets.chop.chars
	found=[]
	for j in order do
		while (names[j].chars - written).empty? do
			for char in names[j].chars do
				written.delete_at(written.find_index(char))
			end
			found << j
		end
	end
	puts "Case ##{i}: #{found.sort.join}"
end


