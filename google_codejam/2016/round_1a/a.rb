t=gets.to_i
for i in 1..t
	s=gets.chop
	last_word=""
	for c in s.chars
		if last_word.size==0
			last_word=c
		elsif last_word[0].ord<=c.ord
			last_word = c+last_word
		elsif last_word[0].ord>c.ord
			last_word = last_word+c
		end
	end
	puts "Case ##{i}: #{last_word}" 
end


