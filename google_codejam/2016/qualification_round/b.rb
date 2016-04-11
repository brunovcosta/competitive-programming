total = gets .to_i
for i in 1..total do
	state = gets .chop .reverse
	oldchar="+"
	bad = "-"
	turns = 0
	for char in state.chars do
		if oldchar!=char and char==bad then
			turns+=1
			bad = oldchar
		end
		oldchar=char
	end
	puts "Case ##{i}: #{turns}"
end
