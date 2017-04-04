def nextNumber n
	sqrsum=0
	for i in n.to_s.chars
		sqrsum+=(i.to_i)*(i.to_i)
	end
	return sqrsum
end


while true
	cont=0
	actual = gets 
	actual = actual.to_i

	unhappy=false
	list=[]
	while actual!=1
		cont=cont+1
		actual = nextNumber actual
		if list.include? actual
			puts "unhappy #{cont}"
			unhappy=true
			break
		end
		list.push actual
	end
	if !unhappy
		puts "happy #{cont}"
	end
end
