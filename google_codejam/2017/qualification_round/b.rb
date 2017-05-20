def naive_tidy n
	if n.to_s.chars.sort.join.to_i == n
		return n
	else
		return naive_tidy n-1
	end
end

def valid? n
	n.to_s.chars.sort.join.to_i == n
end

def repair n,i
	if n.to_s[-1]=='0' and i >= n.to_s.size-1
		#p [n,i]
		return n-1
	else
		value =  n.to_s.chars.map.with_index do |c,ii|
			next c if ii<i
			next (c.to_i-1).to_s if ii==i if c.to_i!=0
			next c if ii==i
			next '9' if ii>i
		end.join.to_i
		#p [n,i,value]
		return value
	end
end

def tidy n
	#puts "====================="
	count = 0
	#p [count,n,n.to_s,n.to_s.size]
	for i in 0..(n.to_s.size+1)
		count+=1
		j = (n.to_s.size) - i
		#p [n,count,i,j,repair(n,j)]
		return repair n,j if(valid? repair n,j)
	end
	return (10**(n.to_s.size-1))-1
	#stream = n.to_s.chars
	#queue = []
	#last = stream.shift
	#while stream.size > 0
	#	ch = stream.shift
	#	if ch >= last
	#		queue << last
	#		last = ch.dup
	#		if ch==last

	#		end
	#	else
	#		queue << (last.ord-1).chr
	#		queue << '9'*(stream.size+1)
	#		#puts "n = #{n}"
	#		#puts "stream = #{stream}"
	#		#puts "queue = #{queue}"
	#		return queue.join.to_i

	#	end
	#end
	#queue << ch

	#return queue.join.to_i
end

if ARGV.last=="test"
	count = 0
	(1..10000).each do |n|
		tidyn = tidy(n)
		if (tidyn)!=(naive_tidy n)
			puts "--------------- #{n} ---------------"
			count+=1
			puts "n = #{n}"
			puts "naive_tidy(n) = #{naive_tidy(n)}"
			puts "tidy(n) = #{tidyn}"
		end
	end
	puts "#{count} erros"
	exit
end

for i in 1..(gets.to_i)
	puts "Case ##{i}: #{tidy gets.to_i}"
end

