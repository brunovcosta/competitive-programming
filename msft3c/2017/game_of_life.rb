
inps = gets.chomp.split(" ")
@h = inps[0].to_i
@w = inps[1].to_i
@t = inps[2].to_i

b = []
for i in 1..@h
	b << gets.chomp.chars
end

def oposite c
	return "*" if c == "#"
	return "#" if c == "*"
	return "."
end

def plant? c
	return c!="."
end

def update board
	next_board = (board.map &:dup)

	for i in 0..(board.size-1)
		for j in 0..(board[0].size-1)
			cell = board[i][j]

			neighbors = []
			neighbors<<board[i+1][j] if i < @h-1
			neighbors<<board[i-1][j] if i > 0
			neighbors<<board[i][j+1] if j < @w-1
			neighbors<<board[i][j-1] if j > 0

			#if [i,j]==[2,2]
			#	p board[i-1]
			#	p board[i]
			#	p board[i+1]
			#end
			oposites = neighbors.select {|n|
				(n == oposite(cell))
			}.size

			female = neighbors.select {|n|
				n == "*"
			}.size

			male = neighbors.select {|n|
				n == "#"
			}.size

			if plant? cell
				p oposites
				next_board[i][j]="." if oposites < 2 # A plant cell with less than two neighbors of the opposite gender dies and becomes empty
				next_board[i][j]="." if oposites > 3 # A plant cell with more than three neighbors of the opposite gender dies and becomes empty
				next_board[i][j] = board[i][j] # Otherwise, the non-empty cells remains the same
			else
				# An empty cell grows a new plant only when it has exactly three plant neighbors and they are not all the same gender. In this case, the cell becomes the gender that is represented by only one of the three neighbors
				next_board[i][j] = board[i][j]
				if female+male ==3
					next_board[i][j] = "*" if female==1
					next_board[i][j] = "#" if male==1
				end
			end

		end
	end
	return next_board
end



curr = b

@t.times do
	curr = update curr
puts curr.map{|row|row.join ""}
puts ""
end
puts curr.map{|row|row.join ""}



