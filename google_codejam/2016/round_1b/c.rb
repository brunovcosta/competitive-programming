require 'set'
t=gets.to_i
for i in 1..t do
	n=gets.to_i
	topics=[]
	for j in 1..n do
		words = gets.chop.split(" ").map{|str|str.chars}
		topics<<words
	end
	topics = topics.sort
	fakes=Set.new
	for j in 0..(topics.length-2) do
		top1=topics[j]
		topics_minus=topics[j+1..-1]
		for k in (j+1)..(topics.length-1) do
			top2=topics[k]
			fakes << [top1[0],top2[1]] if (topics_minus-[top2]).include? [top1[0],top2[1]]
			fakes << [top2[0],top1[1]] if (topics_minus-[top2]).include? [top2[0],top1[1]]
		end
	end
	puts "Case ##{i}: #{fakes.length}"
end
