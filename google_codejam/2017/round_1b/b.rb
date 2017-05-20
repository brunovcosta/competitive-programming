# ROYGBV

graph = {
	r: [:g,:b,:y],
	g: [:r],
	b: [:o,:y,:r],
	y: [:v,:r,:b],
	o: [:b],
	v: [:y]
}

def next_hops graph, state
	# return [] if @found
	pos = state[:pos]
	rest = state[:rest]
	path = state[:path]
	possible = []

	for neighbor in graph[pos]
		if rest[neighbor] > 0 and graph[path.first].any?{|nn| rest[nn] > 0}
			next_rest = rest.dup
			next_rest[neighbor]-=1

			next_path = path.dup
			next_path << neighbor

			possible << {
				pos: neighbor,
				rest: next_rest,
				path: next_path
			}
		end
	end

	if [rest[:r],rest[:g],rest[:b],rest[:y],rest[:v],rest[:o]].max == 0
		@found = true
		return path.join.upcase
	else
		return possible.map{|s| next_hops graph, s}
	end
end

def first_state graph, rest
	graph.each do |pos,neighbors|
		next_rest = rest.dup
		next_rest[pos]-=1
		if rest[pos] > 0
			return {
				pos: pos,
				path: [pos],
				rest: next_rest
			}
		end
	end

	raise "Impossible"
end

t = gets.to_i
for i in 1..t
	@found = false
	input = gets.split
	n = input.first.to_i

	rest = {
		r: input[1].to_i,
		o: input[2].to_i,
		y: input[3].to_i,
		g: input[4].to_i,
		b: input[5].to_i,
		v: input[6].to_i
	}

	state = (first_state graph, rest)
	
	
	possibles = (next_hops graph,state).flatten
	p possibles
	 if possibles.size > 0
	 	puts "Case ##{i}: #{possibles.first}"
	 else
	 	puts "Case ##{i}: IMPOSSIBLE"
	 end

end
