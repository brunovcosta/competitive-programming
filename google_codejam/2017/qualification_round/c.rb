T = gets.to_i

def get_order k
	n = Math.log(k+1,2).to_i
	max = 2*(2**n - 1)
	delta = max - k - 1
	return 2*(2**n - 2 - delta)
end


def count_right k,i
	right_node = 2*i+2
	return 0 if right_node > k
	return 1+count_left(k,right_node)+count_right(k,right_node)

end
def count_left k,i
	left_node = 2*i+1
	return 0 if left_node > k
	return 1+count_left(k,left_node)+count_right(k,left_node)
end
def get_pos n,k,i
	if i == 'LEFT_WALL'
		return 0
	elsif i == 'RIGHT_WALL'
		return n+1
	else
		order = count_left k,i
		nivel = 2**(Math.log(i+1,2).to_i+1)
		return ((order+1)*n/nivel).to_i + 1
	end
end

def first_ancestor dir,k
	#puts "first_ancestor dir: #{dir}, k: #{k}"
	if dir == 'r'
		if k.odd?
			return (k-1)/2
		else
			return first_ancestor dir,(k-1)/2
		end
	else
		if k.even?
			return (k-1)/2
		else
			return first_ancestor dir,(k-1)/2
		end
	end
end

def get_neighbors n,k
	return ['LEFT_WALL','RIGHT_WALL'] if k==0

	if k.odd?
		dir = 'l'
	else
		dir = 'r'
	end

	#puts "dir = #{dir}"
	n1 = (k-1)/2
	if Math.log(k+1,2).to_i==Math.log(k+1,2)
		n2 = 'LEFT_WALL'
	elsif Math.log(k+2,2).to_i==Math.log(k+2,2)
		n2 = 'RIGHT_WALL'
	else
		n2 = first_ancestor dir,k
	end

	return [n1,n2]
end

for i in 1..T 
	input = gets.split
	n = input[0].to_i
	k = input[1].to_i

	#puts "n = #{n}"
	#puts "k = #{k}"
	#neighbors = get_neighbors n,k-1
	#n1 = neighbors[0]
	#n2 = neighbors[1]

	#puts "n1 = #{n1}"
	#puts "n2 = #{n2}"

	#pos =  get_pos n,k,k-1
	#pos1 = get_pos n,k,n1
	#pos2 = get_pos n,k,n2
	#
	#puts "pos = #{pos}"
	#puts "pos1 = #{pos1}"
	#puts "pos2 = #{pos2}"

	#d1 = (pos1-pos).abs - 1
	#d2 = (pos2-pos).abs - 1

	#puts "d1 = #{d1}"
	#puts "d2 = #{d2}"


	#sort = [d1,d2].sort

	#puts "Case ##{i}: #{sort.last} #{sort.first}"
	#max = (n/(2**(Math.log(k,2)+1).floor)).floor
	max = n/(2*k)
	min = (n-2)/(2*k) if n>1
	min = 0 if n==1
	puts "Case ##{i}: #{max} #{min}"
end
