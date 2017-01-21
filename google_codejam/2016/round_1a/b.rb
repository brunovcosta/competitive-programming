t=gets.to_i
for i in 1..t
	n=gets.chop.to_i
	lists = []
	for j in 1..(2*n-1)
		lists.push (gets.chop.split(" ").map{|q|q.to_i})
	end
	lists = lists.sort
	resp=""
	col=[]
	for x in 0..n
		for y in 0..(2*n-2)
			if col.include? lists[y][x]
				col-=[lists[y][x]]
			else
				col+=[lists[y][x]]
			end
		end
	end
	for j in col
		resp+=" #{j}"
	end
	puts "Case ##{i}:#{resp}"

end
