T = gets.to_i
for i in 1..T
	data = gets.split
	n = data[0].to_i
	m = data[1].to_i

	grid = Array.new(n, Array.new(n, "."))

	for model in 1..m
		data = gets.split
		type = data[0]
		r = data[1].to_i
		c = data[2].to_i

		grid[r-1][c-1]=type
	end

	puts "Case ##{i}: #{}"
end
