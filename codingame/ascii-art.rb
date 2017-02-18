@l = gets.to_i
@h = gets.to_i
@t = gets.upcase.chomp
rows=[]
@h.times do
    rows << gets
end

def normalize str
    str.chars.map do |ch|
		if /[^a-z|A-Z]/=~ ch then
			next '[' 
		else
			next ch
		end
	end.join
end


for line in 1..@h
    for char in normalize(@t).chars
        first = (char.ord - 'A'.ord)*@l
        last = first+@l-1
        print rows[line-1][first..last]
    end
    print "\n"
end
