list = gets[1..-2].split(',').map{|s|s.to_i}.sort
resp=""
last_printed=nil
for i in list do
	if last_printed then
		if i-last_printed>1 then
			resp+=","
		end
		resp+="#{i}"
		last_printed=i
	else
		resp+="#{i}"
		last_printed=i
	end
end
puts resp
