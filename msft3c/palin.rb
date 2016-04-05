def factorial n
	if n==0
		return 1
	end
	return n*factorial(n-1)
end
while true
	nome = gets
	nome = nome[0..-2]
	numberOf=Hash.new
	for x in "abcdefghijklmnopqrstuvwxyz".chars
		numberOf[x] = nome.count x
	end

	encontrado = false
	contador = 0
	for x in "abcdefghijklmnopqrstuvwxyz".chars
		if numberOf[x]%2==1 
			if !encontrado then
				encontrado=true
			else
				contador+=1
				numberOf[x] = numberOf[x]-1
			end
		end
	end

	resp = factorial((nome.size - contador)/2)
	for x in "abcdefghijklmnopqrstuvwxyz".chars
		resp = resp/factorial(numberOf[x]/2)
	end
	puts "#{contador},#{resp}"
end
