t=gets.to_i
for i in 1..t do
	scores = gets.chop.split(" ").map{|str| str.chars}
	larger=-1
	last_j = scores[0].length-1
	for j in 0..last_j do
		if larger==-1 then
			if scores[0][j]=="?" and scores[1][j]=="?" then
				scores[0][j]="0"
				scores[1][j]="0"
			elsif scores[0][j]=="?" then
				if j!=last_j then
					next_j0 = scores[0][j+1]
					next_j1 = scores[1][j+1]
					
					if next_j0!="?" and next_j1!="?" then
						if next_j1.to_i < next_j0.to_i and scores[1][j].to_i>0 then
							scores[0][j] = (scores[1][j].to_i-1).to_s
						else
							scores[0][j] = scores[1][j]
						end
					else
						scores[0][j]=scores[1][j]
					end
				else
					scores[0][j]=scores[1][j]
				end
			elsif scores[1][j]=="?" then
				if j!=last_j then
					next_j0 = scores[0][j+1]
					next_j1 = scores[1][j+1]
					
					if next_j0!="?" and next_j1!="?" then
						if next_j0.to_i < next_j1.to_i and scores[0][j].to_i>0 then
							scores[1][j] = (scores[0][j].to_i-1).to_s
						else
							scores[1][j] = scores[0][j]
						end
					else
						scores[1][j]=scores[0][j]
					end
				else
					scores[1][j]=scores[0][j]
				end
			else
				if scores[0][j].to_i > scores[1][j].to_i then
					larger=0
				elsif scores[0][j].to_i < scores[1][j].to_i then
					larger=1
				end
			end
		else
			if scores[0][j]=="?" then
				if larger==0
					scores[0][j]="0"
				else
					scores[0][j]="9"
				end
			end
			if scores[1][j]=="?" then
				if larger==1
					scores[1][j]="0"
				else
					scores[1][j]="9"
				end
			end
		end
	end
	puts "Case ##{i}: #{scores[0].join} #{scores[1].join}"
end
