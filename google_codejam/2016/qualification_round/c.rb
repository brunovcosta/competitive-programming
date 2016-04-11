require 'prime'
def small_divisors n
	for i in Prime.first 100 do
		if n % i==0 then
			return i
		end
	end
	return false
end
def divisors_in_bases n,j,count
	list=[]
	for i in 2..10
		in_size = count.to_s 2
		in_size = "0"*(n-2-in_size.size)+in_size
		string = "1"+in_size+"1"
		list.push small_divisors(string.to_i i)
		if !list.last then
			return false
		end
	end
	return list
end
T = 1
for i in 1..T do
	N=32
	J=500
	puts "Case ##{i}:"
	count  =  0
	for j in 1..J do
		found = false
		while !found do
			count+=1
			found = divisors_in_bases N,J,count
		end
		in_size = count.to_s 2
		in_size = "0"*(N-2-in_size.size)+in_size
		string = "1"+in_size+"1"
		output =  "#{string}"
		for b in 2..10 do
			output+=" #{found[b-2]}"
		end
		puts output
	end
end
